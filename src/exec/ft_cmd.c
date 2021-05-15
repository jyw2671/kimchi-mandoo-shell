/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cmd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeskim <jaeskim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 22:26:53 by yjung             #+#    #+#             */
/*   Updated: 2021/05/15 17:41:440 by jaeskim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_built_cmd_set(t_cmd *cmds, t_check *g)
{
	pid_t	pid;
	int		status;

	status = 0;
	pid = fork();
	if (pid < 0)
		ft_error_print("fail fork", strerror(errno));
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
	else
	{
		wait(&pid);
		ft_redir_close(g);
		ft_pipe_close(g);
	}
	return (status);
}

int	ft_cmd_set(t_cmd *cmds, t_check *g)
{
	pid_t	pid;
	int		status;

	status = 0;
	pid = fork();
	if (pid < 0)
		ft_error_print("fail fork", strerror(errno));
	if (pid == 0)
	{
		ft_pipe_connect(&status, g);
		if (status < 0)
			return (status);
		status = ft_redir_connect(g, 0);
		if (status < 0)
			return (status);
		status = ft_make_cmd(cmds->cmd, cmds->args);
		exit(status);
	}
	else
	{
		wait(&pid);
		ft_redir_close(g);
		ft_pipe_close(g);
	}
	return (status);
}

int	ft_cmd_exec(t_cmd *cmds, t_check *g)
{
	if (ft_strcmp(cmds->cmd, "cd") == 0)
		return (ft_cd(g, cmds->args));
	if (ft_strcmp(cmds->cmd, "echo") == 0)
		return (ft_echo(g, cmds->args));
	if (ft_strcmp(cmds->cmd, "pwd") == 0)
		return (ft_pwd(g));
	if (ft_strcmp(cmds->cmd, "env") == 0)
		return (ft_env());
	if (ft_strcmp(cmds->cmd, "export") == 0)
		return (ft_export(g, cmds->args));
	if (ft_strcmp(cmds->cmd, "unset") == 0)
		return (ft_unset(g, cmds->args));
	if (ft_strcmp(cmds->cmd, "exit") == 0)
		return (ft_exit());
	return (ft_cmd_set(cmds, g));
}
