/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_exec.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjung <yjung@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 19:59:36 by yjung             #+#    #+#             */
/*   Updated: 2021/05/21 14:04:14 by yjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_free_cmd(void *target, int ret)
{
	if (target != NULL)
		free_CMD(target);
	return (ret);
}

void	free_g(t_check *g)
{
	if (g->pipe_fd)
		free_pipe(g->pipe_fd);
}

void	free_pipe(void *data)
{
	t_pi_fd	*pipe;

	pipe = data;
	if (pipe)
		ft_free(pipe);
}
