/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_tree_parser.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjung <yjung@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/15 17:12:27 by jaeskim           #+#    #+#             */
/*   Updated: 2021/05/16 16:57:44 by yjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	is_builtin(t_cmd *cmds)
{
	if (ft_strcmp(cmds->cmd, "cd") == 0)
		return (0);
	if (ft_strcmp(cmds->cmd, "echo") == 0)
		return (1);
	if (ft_strcmp(cmds->cmd, "pwd") == 0)
		return (1);
	if (ft_strcmp(cmds->cmd, "env") == 0)
		return (1);
	if (ft_strcmp(cmds->cmd, "export") == 0)
		return (0);
	if (ft_strcmp(cmds->cmd, "unset") == 0)
		return (0);
	if (ft_strcmp(cmds->cmd, "exit") == 0)
		return (0);
	return (0);
}

int	exec_tree_parser(t_AST *cmds, t_check *g)
{
	if (cmds->type == FT_CMD && cmds->data)
	{
		if (is_builtin(cmds->data))
			return (ft_built_cmd_set(cmds->data, g));
		else
			return (ft_cmd_exec(cmds->data, g));
	}
	if (cmds->type == FT_PIPE)
		return (ft_pipe_exec(cmds->data, g));
	if (cmds->type == FT_REDIRECT)
		return (ft_redir_exec(cmds->data, g));
	if (cmds->type == FT_CTR_OP)
		return (ft_ctr_op_exec(cmds->data, g));
	return (0);
}
