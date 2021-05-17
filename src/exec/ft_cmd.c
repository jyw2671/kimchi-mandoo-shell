/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cmd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjung <yjung@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 22:26:53 by yjung             #+#    #+#             */
/*   Updated: 2021/05/17 19:13:03 by yjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_list	*parse_cmd_args(t_list *args_lst)
{
	t_list	*result;

	if (args_lst)
	{
		result = parse_arg(args_lst);
		if ((int)result == PARSE_MALLOC)
			ft_error_print(PARSE_MALLOC_MSG, strerror(errno));
		else if ((int)result == PARSE_CMD_NONE)
			ft_error_print(PARSE_CMD_NONE_MSG, strerror(errno));
		else
			return (result);
		return ((t_list *)PARSE_ARG_ERR);
	}
	return (NULL);
}

int	ft_cmd_exec(t_cmd *cmds, t_check *g)
{
	int		status;
	t_list	*args;

	args = parse_cmd_args(cmds->args);
	if (args == (t_list *)PARSE_ARG_ERR)
		return (FAIL);
	if (ft_strcmp(cmds->cmd, "cd") == 0)
		status = ft_cd(args);
	else if (ft_strcmp(cmds->cmd, "echo") == 0)
		status = ft_echo(args);
	else if (ft_strcmp(cmds->cmd, "pwd") == 0)
		status = ft_pwd();
	else if (ft_strcmp(cmds->cmd, "env") == 0)
		status = ft_env(args);
	else if (ft_strcmp(cmds->cmd, "export") == 0)
		status = ft_export(args);
	else if (ft_strcmp(cmds->cmd, "unset") == 0)
		status = ft_unset(args);
	else if (ft_strcmp(cmds->cmd, "exit") == 0)
		status = ft_exit();
	else
		status = ft_cmd_set(cmds, g);
	if (args)
		ft_lstclear(&args, ft_free);
	return (status);
}
