/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cmd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjung <yjung@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 22:26:53 by yjung             #+#    #+#             */
<<<<<<< Updated upstream
/*   Updated: 2021/05/10 21:03:30 by yjung            ###   ########.fr       */
=======
<<<<<<< HEAD
/*   Updated: 2021/05/18 15:19:21 by yjung            ###   ########.fr       */
=======
/*   Updated: 2021/05/10 21:03:30 by yjung            ###   ########.fr       */
>>>>>>> origin/master
>>>>>>> Stashed changes
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

<<<<<<< Updated upstream
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
		if (status < 0)
			return (status);
		status = ft_redir_connect(g);
		if (status < 0)
			return (status);
		status = ft_cmd_exec(cmds, g);
		if (status < 0)
			return (status);
		status = ft_redir_close(g);
		ft_pipe_connect(&status, g);
		exit(status);
	}
	else
	{
		wait(&pid);
		// ft_pipe_connect(&status, g);
		// if (status < 0)
		// 	return (status);
	}
	return (status);
}

int	ft_cmd_set(t_cmd *cmds, t_check *g)
=======
<<<<<<< HEAD
int	ft_cmd_exec(t_cmd *cmds, t_check *g)
>>>>>>> Stashed changes
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
		status = ft_redir_connect(g);
		if (status < 0)
			return (status);
		status = ft_make_cmd(cmds->cmd, cmds->args);
		if (status < 0)
			return (status);
		status = ft_redir_close(g);
		exit(status);
	}
	else
	{
		wait(&pid);
		if (g->pipe_close == 1)
			ft_pipe_close(g);
	}
	return (status);
}

int	ft_cmd_exec(t_cmd *cmds, t_check *g)
{
	int	 status;

	status = 0;
	// TODO: cd를 제외한 나머지 fork()
	if (ft_strcmp(cmds->cmd, "cd") == 0)
		status = ft_cd(g, cmds->args);
	else if (ft_strcmp(cmds->cmd, "echo") == 0)
		status = ft_echo(g, cmds->args);
	else if (ft_strcmp(cmds->cmd, "pwd") == 0)
		ft_pwd(g);
	else if (ft_strcmp(cmds->cmd, "env") == 0)
		status = ft_env();
	else if (ft_strcmp(cmds->cmd, "export") == 0)
		status = ft_export(cmds->args);
	else if (ft_strcmp(cmds->cmd, "unset") == 0)
		status = ft_unset(g, cmds->args);
	else if (ft_strcmp(cmds->cmd, "exit") == 0)
<<<<<<< Updated upstream
=======
		status = ft_exit();
	else
=======
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
		if (status < 0)
			return (status);
		status = ft_redir_connect(g);
		if (status < 0)
			return (status);
		status = ft_cmd_exec(cmds, g);
		if (status < 0)
			return (status);
		status = ft_redir_close(g);
		ft_pipe_connect(&status, g);
		exit(status);
	}
	else
	{
		wait(&pid);
		// ft_pipe_connect(&status, g);
		// if (status < 0)
		// 	return (status);
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
		status = ft_redir_connect(g);
		if (status < 0)
			return (status);
		status = ft_make_cmd(cmds->cmd, cmds->args);
		if (status < 0)
			return (status);
		status = ft_redir_close(g);
		exit(status);
	}
	else
	{
		wait(&pid);
		if (g->pipe_close == 1)
			ft_pipe_close(g);
	}
	return (status);
}

int	ft_cmd_exec(t_cmd *cmds, t_check *g)
{
	int	 status;

	status = 0;
	// TODO: cd를 제외한 나머지 fork()
	if (ft_strcmp(cmds->cmd, "cd") == 0)
		status = ft_cd(g, cmds->args);
	else if (ft_strcmp(cmds->cmd, "echo") == 0)
		status = ft_echo(g, cmds->args);
	else if (ft_strcmp(cmds->cmd, "pwd") == 0)
		ft_pwd(g);
	else if (ft_strcmp(cmds->cmd, "env") == 0)
		status = ft_env();
	else if (ft_strcmp(cmds->cmd, "export") == 0)
		status = ft_export(cmds->args);
	else if (ft_strcmp(cmds->cmd, "unset") == 0)
		status = ft_unset(g, cmds->args);
	else if (ft_strcmp(cmds->cmd, "exit") == 0)
>>>>>>> Stashed changes
	{
		// status = ft_exit(cmds->args);
		if (status != -1)
			exit(status);
	}
	else if (cmds)
<<<<<<< Updated upstream
=======
>>>>>>> origin/master
>>>>>>> Stashed changes
		status = ft_cmd_set(cmds, g);
	return (status);
}
