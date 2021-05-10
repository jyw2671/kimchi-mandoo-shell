/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjung <yjung@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 17:48:20 by yjung             #+#    #+#             */
/*   Updated: 2021/05/10 20:02:27 by yjung            ###   ########.fr       */
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
	num->pi_out = pi[0];
	num->pi_in = pi[1];
	if (g->pipe_fd)
		ft_lstlast(g->pipe_fd)->next = ft_lstnew(num);
	else
		g->pipe_fd = ft_lstnew(num);
	g->pipe_cnt++;
	return (0);
}

void	ft_pipe_close(t_check *g)
{
	t_pi_fd	*num;
	int		pi[2];

	num = (g->pipe_fd)->content;
	dup2(pi[1], num->pi_out);
	close(num->pi_out);
	g->fd_i = pi[1];
	g->fd_o = pi[0];
	close(pi[0]);
}

void	ft_pipe_connect(int *status, t_check *g)
{
	t_pi_fd	*num;

	// TODO: 코드 검증 필요!
	if (g->pipe_cnt <= 0)
		return ;
	num = (g->pipe_fd)->content;
	if (num && num->pi_out > 0 && num->pi_in > 0 && g->pipe_check == 0)
	// if (num && num->pi_in > 0 && num->pi_out > 0)
	{
		*status = dup2(num->pi_in, STDOUT_FILENO);
		// pipe의 pi_in 부분을 stdout에 복제해준다
		// pi_in을 stdout으로 접근 가능
		if (*status < 0)
			return ;
		close(num->pi_out);
		// ((t_pi_fd *)((g->pipe_fd)->content))->pi_in = -1;
		g->pipe_check = 1;
		g->pipe_close = 1;
	}
	else
	{
		if (g->fd_i != 0 && g->fd_o != 0)
		{
			num->pi_in = g->fd_i;
			num->pi_out = g->fd_o;
		}
		*status = dup2(num->pi_out, STDIN_FILENO);
		if (*status < 0)
			return ;
		close(num->pi_in);
		ft_lstdelone(g->pipe_fd, (g->pipe_fd)->content);
		g->pipe_fd= (g->pipe_fd)->next;
		g->pipe_cnt--;
		g->pipe_check = 0;
		g->pipe_close = 0;
	}
}

int	ft_pipe_exec(t_pipe	*pipes, t_check *g)
{
	int	status;

	status = 0;
	status = ft_set_pipe(g);
	if (status != 0)
		return (status);
	status = ft_tree_parser(pipes->left, g);
	if (status)
		return (status);
	return (ft_tree_parser(pipes->right, g));
}
