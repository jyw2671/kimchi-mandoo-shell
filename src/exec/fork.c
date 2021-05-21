/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjung <yjung@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 15:45:57 by yjung             #+#    #+#             */
/*   Updated: 2021/05/21 22:33:38 by yjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	builtin_cmd_set(t_cmd *cmds, t_check *g)
{
	int	status;

	status = ft_redir_connect(g, 1);
	if (status < 0)
	{
		ft_redir_close(g);
		return (status);
	}
	status = ft_cmd_exec(cmds, g);
	ft_redir_close(g);
	return (status);
}

int	builtin_pipe_set(t_cmd *cmds, t_check *g)
{
	pid_t	pid;
	int		status;

	status = 0;
	pid = fork();
	if (pid < 0)
		ft_error_print("fail fork", NULL, strerror(errno));
	else if (pid == 0)
	{
		ft_pipe_connect(&status, g);
		if (status < 0)
			return (status);
		status = ft_redir_connect(g, 0);
		if (status < 0)
			return (status);
		status = ft_cmd_exec(cmds, g);
		exit(status);
	}
	waitpid(pid, &status, WUNTRACED);
	g_sh.status += (status >> 8) & 0xff;
	ft_redir_close(g);
	ft_pipe_close(g);
	return (g_sh.status);
}

int	ft_cmd_set(t_cmd *cmds, t_check *g)
{
	pid_t	pid;
	int		status;

	status = 0;
	pid = fork();
	if (pid < 0)
		ft_error_print("fail fork", NULL, strerror(errno));
	if (pid == 0)
	{
		ft_pipe_connect(&status, g);
		if (status < 0)
			exit(status);
		status = ft_redir_connect(g, 0);
		if (status < 0)
			exit(status);
		status = ft_make_cmd(cmds->cmd, cmds->args);
		exit(status);
	}
	waitpid(pid, &status, WUNTRACED);
	g_sh.status += (status >> 8) & 0xff;
	ft_redir_close(g);
	ft_pipe_close(g);
	return (g_sh.status);
}
