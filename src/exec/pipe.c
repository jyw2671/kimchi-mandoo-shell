/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjung <yjung@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 17:48:20 by yjung             #+#    #+#             */
/*   Updated: 2021/05/12 20:35:57 by yjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	ft_set_pipe(t_check *g)
{
	int		pi[2];
	int		status;
	t_pi_fd	*num;

	if (!ft_malloc((void **)&num, sizeof(t_pi_fd)))
		// TODO: 예외처리 확인 필요.
		return (-1);
	status = pipe(pi);
	if (status < 0)
		return (-1);
	num->pi_write = pi[0];
	num->pi_read = pi[1];
	num->check = PIPE_R_ONLY;
	if (g->pipe_fd)
		((t_pi_fd *)(g->pipe_fd->content))->check = PIPE_R_W;
	ft_d_lstadd_back(&g->pipe_fd, ft_d_lstnew(num));
	g->pipe_cnt++;
	return (0);
}

void	ft_pipe_connect(int *status, t_check *g)
{
	t_pi_fd	*num;

	if (g->pipe_cnt <= 0)
		return ;
	num = (g->pipe_fd)->content;
	if (num->check == PIPE_R_ONLY)
		*status = dup2(num->pi_read, STDOUT_FILENO);
	else if (num->check == PIPE_W_ONLY && g->fd_in != 0 && (g->redir_in = 1))
		return ;
	else if (num->check == PIPE_W_ONLY)
		*status = dup2(num->pi_write, STDIN_FILENO);
	else if (num->check == PIPE_R_W)
	{
		if (g->fd_in == 0)
			*status = dup2(num->pi_write, STDIN_FILENO);
		else
			g->redir_in = 1;
		if (*status < 0)
			return ;
		num = (g->pipe_fd->next)->content;
		*status = dup2(num->pi_read, STDOUT_FILENO);
	}
	if (*status < 0)
		return ;
}

void	ft_pipe_write_close(t_check *g, int check)
{
	t_pi_fd		*num;
	t_d_list	*tmp;

	if (g->redir_in == 0)
	{
		num = (g->pipe_fd)->content;
		close(num->pi_write);
	}
	else
		g->redir_in = 0;
	tmp = (g->pipe_fd)->next;
	ft_d_lstdelone(g->pipe_fd, free_pipe);
	g->pipe_fd = tmp;
	if (check == 1)
	{
		num = (g->pipe_fd)->content;
		close(num->pi_read);
		((t_pi_fd *)(g->pipe_fd->content))->check = PIPE_W_ONLY;
	}
}

void	ft_pipe_close(t_check *g)
{
	int		check;
	t_pi_fd	*num;

	if (g->pipe_cnt <= 0)
		return ;
	num = (g->pipe_fd)->content;
	if (num->check == PIPE_R_W)
		check = 1;
	else
		check = 0;
	if (num->check == PIPE_R_ONLY)
	{
		close(num->pi_read);
		((t_pi_fd *)(g->pipe_fd->content))->check = PIPE_W_ONLY;
		return ;
	}
	ft_pipe_write_close(g, check);
	g->pipe_cnt--;
}

int	ft_pipe_exec(t_pipe	*pipes, t_check *g)
{
	int		status;

	status = 0;
	status = ft_set_pipe(g);
	if (status != 0)
		return (status);
	status = ft_tree_parser(pipes->left, g);
	if (status)
		return (status);
	status = ft_tree_parser(pipes->right, g);
	return (status);
}
