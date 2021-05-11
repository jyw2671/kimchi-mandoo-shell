/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjung <yjung@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 17:48:20 by yjung             #+#    #+#             */
/*   Updated: 2021/05/11 20:04:55 by yjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	ft_set_pipe(t_check *g)
{
	int		pi[2];
	int		status;
	t_pi_fd	*num;
	t_pi_fd	*check;

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
	ft_d_lstadd_back(g->pipe_fd, ft_d_lstnew(num));
	g->pipe_cnt++;
	return (0);
}

void	ft_pipe_connect(int *status, t_check *g)
{
	t_pi_fd	*num;

	// TODO: 코드 검증 필요!
	if (g->pipe_cnt <= 0)
		return ;
	num = (g->pipe_fd)->content;
	if (num->check == PIPE_R_ONLY)
		*status = dup2(num->pi_read, STDOUT_FILENO);
	else if (num->check == PIPE_W_ONLY)
		*status = dup2(num->pi_write, STDIN_FILENO);
	else if (num->check == PIPE_R_W)
	{
		num = (g->pipe_fd->prev)->content;
		*status = dup2(num->pi_write, STDIN_FILENO);
		if (*status < 0)
			return ;
		num = (g->pipe_fd)->content;
		*status = dup2(num->pi_read, STDOUT_FILENO);
	}
	if (*status < 0)
		return ;
}

void	ft_pipe_close(t_check *g)
{
	t_pi_fd		*num;
	t_d_list	*tmp;

	if (g->pipe_cnt <= 0)
		return ;
	num = (g->pipe_fd)->content;
	if (num->check == PIPE_R_ONLY)
	{
		close(num->pi_read);
		num->check = PIPE_W_ONLY;
		return ;
	}
	// TODO: 아래 두가지 케이스 refactoring 필요
	else if (num->check == PIPE_W_ONLY)
	{
		close(num->pi_write);
		tmp = (g->pipe_fd)->next;
		ft_d_lstdelone(g->pipe_fd, (g->pipe_fd)->content);
		g->pipe_fd = tmp;
	}
	else if (num->check == PIPE_R_W)
	{
		num = (g->pipe_fd)->prev;
		close(num->pi_write);
		tmp = (g->pipe_fd)->next;
		ft_d_lstdelone(g->pipe_fd, (g->pipe_fd)->content);
		g->pipe_fd = tmp;
		num->check = PIPE_W_ONLY;
	}
	g->pipe_cnt--;
}

int	ft_pipe_exec(t_pipe	*pipes, t_check *g)
{
	int		status;

	status = 0;
	status = ft_set_pipe(g);
	if (status != 0)
		return (status);
	// ((t_pi_fd *)(g->pipe_fd->content))->check = 1;
	status = ft_tree_parser(pipes->left, g);
	// TODO: close()
	if (status)
		return (status);
	// ((t_pi_fd *)(g->pipe_fd->content))->check = 0;
	status = ft_tree_parser(pipes->right, g);
	return (status);
}
