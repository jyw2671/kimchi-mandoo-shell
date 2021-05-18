/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cmd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjung <yjung@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 22:26:53 by yjung             #+#    #+#             */
/*   Updated: 2021/05/18 15:19:21 by yjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_cmd_exec(t_cmd *cmds, t_check *g)
{
	int		status;

	if (ft_strcmp(cmds->cmd, "cd") == 0)
		status = ft_cd(cmds->args);
	else if (ft_strcmp(cmds->cmd, "echo") == 0)
		status = ft_echo(cmds->args);
	else if (ft_strcmp(cmds->cmd, "pwd") == 0)
		status = ft_pwd();
	else if (ft_strcmp(cmds->cmd, "env") == 0)
		status = ft_env(cmds->args);
	else if (ft_strcmp(cmds->cmd, "export") == 0)
		status = ft_export(cmds->args);
	else if (ft_strcmp(cmds->cmd, "unset") == 0)
		status = ft_unset(cmds->args);
	else if (ft_strcmp(cmds->cmd, "exit") == 0)
		status = ft_exit();
	else
		status = ft_cmd_set(cmds, g);
	return (status);
}
