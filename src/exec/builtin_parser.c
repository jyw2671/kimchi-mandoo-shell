/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_parser.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjung <yjung@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 14:47:11 by yjung             #+#    #+#             */
/*   Updated: 2021/05/22 13:15:20 by yjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	is_builtin(t_cmd *cmds)
{
	if (ft_strcmp(cmds->cmd, "cd") == 0)
		return (1);
	if (ft_strcmp(cmds->cmd, "echo") == 0)
		return (1);
	if (ft_strcmp(cmds->cmd, "pwd") == 0)
		return (1);
	if (ft_strcmp(cmds->cmd, "env") == 0)
		return (1);
	if (ft_strcmp(cmds->cmd, "export") == 0)
		return (1);
	if (ft_strcmp(cmds->cmd, "unset") == 0)
		return (1);
	if (ft_strcmp(cmds->cmd, "exit") == 0)
		return (1);
	return (0);
}

int	builtin_parser(t_cmd *cmds, t_check *g)
{
	t_cmd	*result;
	int		check;
	int		status;

	result = parse_t_cmd(cmds, &status, g);
	if (status != SUCCESS)
		return (ft_free_cmd(result, FAIL));
	check = is_builtin(result);
	if (check == 1 && g->pipe_cnt > 0)
		check = 2;
	if (check == 0)
		status = ft_cmd_exec(result, g);
	else if (check == 1)
		status = builtin_cmd_set(result, g);
	else
		status = builtin_pipe_set(result, g);
	free_CMD(result);
	return (status);
}
