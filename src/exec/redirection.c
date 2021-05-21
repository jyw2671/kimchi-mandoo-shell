/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
<<<<<<< Updated upstream
/*   By: yjung <yjung@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 12:56:09 by yjung             #+#    #+#             */
/*   Updated: 2021/05/10 20:43:36 by yjung            ###   ########.fr       */
=======
<<<<<<< HEAD
/*   By: jaeskim <jaeskim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 12:56:09 by yjung             #+#    #+#             */
/*   Updated: 2021/05/21 17:29:34 by jaeskim          ###   ########.fr       */
=======
/*   By: yjung <yjung@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 12:56:09 by yjung             #+#    #+#             */
/*   Updated: 2021/05/10 20:43:36 by yjung            ###   ########.fr       */
>>>>>>> origin/master
>>>>>>> Stashed changes
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

<<<<<<< Updated upstream
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

int	ft_redir_connect(t_check *g)
=======
<<<<<<< HEAD
int	ft_redir_connect(t_check *g, int is_dup)
{
	if (g->fd_in > 0)
	{
		if (is_dup)
		{
			g->save_in = dup(STDIN_FILENO);
			if (g->save_in < 0)
				return (DUP_ERROR);
		}
		if (dup2(g->fd_in, STDIN_FILENO) < 0)
			return (DUP_ERROR);
	}
	if (g->fd_out > 0)
	{
		if (is_dup)
		{
			g->save_out = dup(STDOUT_FILENO);
			if (g->save_out < 0)
				return (DUP_ERROR);
		}
		if (dup2(g->fd_out, STDOUT_FILENO) < 0)
			return (DUP_ERROR);
	}
	return (SUCCESS);
}

static int	redir_connect_dup(int *redir_fd, int *save, int is_red_in)
=======
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

int	ft_redir_connect(t_check *g)
>>>>>>> origin/master
>>>>>>> Stashed changes
{
	int	status;

	status = 0;
<<<<<<< Updated upstream
	if (g->fd_in != 0 && g->save_in == -1)
=======
<<<<<<< HEAD
	close(*redir_fd);
	if (*save != -1)
>>>>>>> Stashed changes
	{
		g->save_in = dup(STDIN_FILENO);
		status = dup2(g->fd_in, STDIN_FILENO);
	}
	if (status < 0)
		return (status);
	if (g->fd_out != 0 && g->save_out == -1)
	{
		g->save_out = dup(STDOUT_FILENO);
		status = dup2(g->fd_out, STDOUT_FILENO);
	}
<<<<<<< Updated upstream
=======
	*redir_fd = 0;
=======
	if (g->fd_in != 0 && g->save_in == -1)
	{
		g->save_in = dup(STDIN_FILENO);
		status = dup2(g->fd_in, STDIN_FILENO);
	}
	if (status < 0)
		return (status);
	if (g->fd_out != 0 && g->save_out == -1)
	{
		g->save_out = dup(STDOUT_FILENO);
		status = dup2(g->fd_out, STDOUT_FILENO);
	}
>>>>>>> origin/master
>>>>>>> Stashed changes
	return (status);
}

int	ft_redir_close(t_check *g)
{
	int	status;

	status = 0;
<<<<<<< Updated upstream
	if (g->fd_in != 0 && g->save_in != -1)
	{
		close(g->fd_in);
		status = dup2(g->save_in, STDIN_FILENO);
		g->save_in = -1;
		g->fd_in = 0;
	}
=======
<<<<<<< HEAD
	if (g->fd_in > 0)
		status = redir_connect_dup(&g->fd_in, &g->save_in, 1);
>>>>>>> Stashed changes
	if (status < 0)
		return (status);
	if (g->fd_out != 0 && g->save_out != -1)
	{
		close(g->fd_out);
<<<<<<< Updated upstream
=======
=======
	if (g->fd_in != 0 && g->save_in != -1)
	{
		close(g->fd_in);
		status = dup2(g->save_in, STDIN_FILENO);
		g->save_in = -1;
		g->fd_in = 0;
	}
	if (status < 0)
		return (status);
	if (g->fd_out != 0 && g->save_out != -1)
	{
		close(g->fd_out);
>>>>>>> Stashed changes
		status = dup2(g->save_out, STDOUT_FILENO);
		close(g->save_out);
		g->save_out = -1;
		g->fd_out = 0;
	}
	return (status);
<<<<<<< Updated upstream
=======
>>>>>>> origin/master
>>>>>>> Stashed changes
}

int	ft_redir_exec(t_redirect *redir, t_check *g)
{
<<<<<<< Updated upstream
	int	status;
=======
<<<<<<< HEAD
	char	*path;
>>>>>>> Stashed changes

	status = 0;
	if (redir->type == FT_FD_IN)
		g->fd_in = open(redir->file, O_RDONLY);
	else if (redir->type == FT_FD_OUT)
		g->fd_out = open(redir->file, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	else if (redir->type == FT_FD_APPEND)
		g->fd_out = open(redir->file, O_WRONLY | O_CREAT | O_APPEND, 0644);
	// else if (redir->type == FT_FD_HEREDOC)
	// 	ft_redir_heredoc();
	if (g->fd_in < 0 || g->fd_out < 0)
<<<<<<< Updated upstream
=======
	{
		if (!(redir->type == FT_FD_HEREDOC))
			ft_error_print("open fail", strerror(errno));
		return (-1);
	}
	return (exec_tree_parser(redir->AST, g));
=======
	int	status;

	status = 0;
	if (redir->type == FT_FD_IN)
		g->fd_in = open(redir->file, O_RDONLY);
	else if (redir->type == FT_FD_OUT)
		g->fd_out = open(redir->file, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	else if (redir->type == FT_FD_APPEND)
		g->fd_out = open(redir->file, O_WRONLY | O_CREAT | O_APPEND, 0644);
	// else if (redir->type == FT_FD_HEREDOC)
	// 	ft_redir_heredoc();
	if (g->fd_in < 0 || g->fd_out < 0)
>>>>>>> Stashed changes
		ft_error_print("open fail", strerror(errno));
	else if (!redir->AST)
		return (0);
	else
		status = ft_tree_parser(redir->AST, g);
	return (status);
<<<<<<< Updated upstream
=======
>>>>>>> origin/master
>>>>>>> Stashed changes
}
