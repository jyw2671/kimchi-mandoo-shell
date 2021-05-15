/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjung <yjung@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 12:56:09 by yjung             #+#    #+#             */
/*   Updated: 2021/05/15 22:29:01 by yjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// static int	ft_redir_heredoc(t_AST *cmds, char *file, t_list **envp)
// {
// 	int	status;

// 	// TODO: here_doc 구현 필요
// 	(void)cmds;
// 	(void)file;
// 	(void)envp;
// 	status = 0;
// 	return (status);
// }

int	ft_redir_connect(t_check *g, int is_dup)
{
	if (g->fd_in > 0)
	{
		if (is_dup)
			g->save_in = dup(STDIN_FILENO);
		if (g->save_in < 0)
			return (DUP_ERROR);
		if (dup2(g->fd_in, STDIN_FILENO) < 0)
			return (DUP_ERROR);
	}
	if (g->fd_out > 0)
	{
		if (is_dup)
			g->save_out = dup(STDOUT_FILENO);
		if (g->save_out < 0)
			return (DUP_ERROR);
		if (dup2(g->fd_out, STDOUT_FILENO) < 0)
			return (DUP_ERROR);
	}
	return (0);
}

static int	redir_connect_dup(int *redir_fd, int *save, int is_red_in)
{
	int	status;

	status = 0;
	close(*redir_fd);
	if (*save != -1)
	{
		if (is_red_in)
			status = dup2(*save, STDIN_FILENO);
		else
			status = dup2(*save, STDOUT_FILENO);
		if (status < 0)
			return (DUP_ERROR);
		close(*save);
		*save = -1;
	}
	*redir_fd = 0;
	return (status);
}

int	ft_redir_close(t_check *g)
{
	int	status;

	status = 0;
	if (g->fd_in > 0)
		status = redir_connect_dup(&g->fd_in, &g->save_in, 1);
	if (status < 0)
		return (status);
	if (g->fd_out > 0)
		status = redir_connect_dup(&g->fd_out, &g->save_out, 0);
	return (status);
}

int	ft_redir_exec(t_redirect *redir, t_check *g)
{
	int	status;

	status = 0;
	if (redir->type == FT_FD_IN)
	{
		g->fd_in = open(redir->file, O_RDONLY);
		g->redir_in = 1;
	}
	else if (redir->type == FT_FD_OUT)
		g->fd_out = open(redir->file, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	else if (redir->type == FT_FD_APPEND)
		g->fd_out = open(redir->file, O_WRONLY | O_CREAT | O_APPEND, 0644);
	// else if (redir->type == FT_FD_HEREDOC)
	// 	ft_redir_heredoc();
	if (g->fd_in < 0 || g->fd_out < 0)
	{
		status = -1;
		ft_error_print("open fail", strerror(errno));
	}
	else if (!redir->AST)
		return (0);
	else
		status = exec_tree_parser(redir->AST, g);
	return (status);
}
