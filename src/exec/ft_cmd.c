/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cmd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjung <yjung@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 22:26:53 by yjung             #+#    #+#             */
/*   Updated: 2021/05/16 20:52:17 by yjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	builtin_pipe_set(t_cmd *cmds, t_check *g)
{
	if (g->pipe_cnt > 0 && ((t_pi_fd *)(g->pipe_fd->content))->check \
		== PIPE_R_ONLY)
		return (ft_built_cmd_set(cmds, g));
	if (g->fd_out > 0)
	{
		if (ft_redir_connect(g, 1) == DUP_ERROR)
			return (DUP_ERROR);
		if (ft_cmd_exec(cmds, g) == FAIL)
			return (FAIL);
		ft_redir_close(g);
		return (SUCCESS);
	}
	return (ft_cmd_exec(cmds, g));
}

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
	// TODO: arg 환경변수 치환
	// TODO: pipe 연결 등 빌트인 함수 포크 로직 다시 만들기
	if (ft_strcmp(cmds->cmd, "cd") == 0)
		return (ft_cd(g, cmds->args));
	if (ft_strcmp(cmds->cmd, "echo") == 0)
		return (ft_echo(g, cmds->args));
	if (ft_strcmp(cmds->cmd, "pwd") == 0)
		return (ft_pwd(g));
	if (ft_strcmp(cmds->cmd, "env") == 0)
		return (ft_env(cmds->args));
	if (ft_strcmp(cmds->cmd, "export") == 0)
		return (ft_export(cmds->args));
	if (ft_strcmp(cmds->cmd, "unset") == 0)
		return (ft_unset(cmds->args));
	if (ft_strcmp(cmds->cmd, "exit") == 0)
		return (ft_exit());
	return (ft_cmd_set(cmds, g));
}
