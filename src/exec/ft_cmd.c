/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cmd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjung <yjung@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 22:26:53 by yjung             #+#    #+#             */
/*   Updated: 2021/05/17 22:48:51 by yjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static t_list	*parse_cmd_args(t_list *args_lst)
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
		return ((t_list *)PARSE_ERROR_COUNT);
	}
	return (NULL);
}

static t_cmd	*parse_t_cmd(t_cmd *cmds, int *status)
{
	char	*cmd;
	t_cmd	*result;

	*status = 0;
	if (!ft_malloc((void **)&result, sizeof(t_cmd)))
	{
		*status = PARSE_MALLOC;
		return (result);
	}
	cmd = cmds->cmd;
	result->cmd = normalize(&cmd, NORMALIZE_CMD);
	if (result->cmd == NULL)
	{
		*status = PARSE_MALLOC;
		return (result);
	}
	result->args = parse_cmd_args(cmds->args);
	if (result->args <= (t_list *)PARSE_ERROR_COUNT)
		*status = (int)result->args;
	return (result);
}

static int	ft_free_cmd(void *target, int ret)
{
	if (target != NULL)
		free_CMD(target);
	return (ret);
}

int	ft_cmd_exec(t_cmd *cmds, t_check *g)
{
	int		status;
	t_cmd	*parse_cmd;

	parse_cmd = parse_t_cmd(cmds, &status);
	if (status != SUCCESS)
		return (ft_free_cmd(parse_cmd, FAIL));
	else if (ft_strcmp(parse_cmd->cmd, "cd") == 0)
		status = ft_cd(parse_cmd->args);
	else if (ft_strcmp(parse_cmd->cmd, "echo") == 0)
		status = ft_echo(parse_cmd->args);
	else if (ft_strcmp(parse_cmd->cmd, "pwd") == 0)
		status = ft_pwd();
	else if (ft_strcmp(parse_cmd->cmd, "env") == 0)
		status = ft_env(parse_cmd->args);
	else if (ft_strcmp(parse_cmd->cmd, "export") == 0)
		status = ft_export(parse_cmd->args);
	else if (ft_strcmp(parse_cmd->cmd, "unset") == 0)
		status = ft_unset(parse_cmd->args);
	else if (ft_strcmp(parse_cmd->cmd, "exit") == 0)
		status = ft_exit();
	else
		status = ft_cmd_set(cmds, g);
	free_CMD(parse_cmd);
	return (status);
}
