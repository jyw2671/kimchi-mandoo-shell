/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_tree_parser.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjung <yjung@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/15 17:12:27 by jaeskim           #+#    #+#             */
/*   Updated: 2021/05/17 15:50:30 by yjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	ft_ctr_op_exec(t_ctr_op *ctr, t_check *g)
{
	int		status;

	status = 0;
	status = exec_tree_parser(ctr->left, g);
	if (ctr->type == FT_AND && status != 0)
		return (status);
	if (ctr->type == FT_OR && status == 0)
		return (status);
	status = exec_tree_parser(ctr->right, g);
	return (status);
}

static int	is_builtin(t_cmd *cmds)
{
	if (ft_strcmp(cmds->cmd, "cd") == 0)
		return (2);
	if (ft_strcmp(cmds->cmd, "echo") == 0)
		return (1);
	if (ft_strcmp(cmds->cmd, "pwd") == 0)
		return (1);
	if (ft_strcmp(cmds->cmd, "env") == 0)
		return (1);
	if (ft_strcmp(cmds->cmd, "export") == 0)
		return (2);
	if (ft_strcmp(cmds->cmd, "unset") == 0)
		return (2);
	if (ft_strcmp(cmds->cmd, "exit") == 0)
		return (0);
	return (0);
}

int	exec_tree_parser(t_AST *cmds, t_check *g)
{
	int	check;

	if (cmds->type == FT_CMD && cmds->data)
	{
		check = is_builtin(cmds->data);
		if (check == 1)
			return (ft_built_cmd_set(cmds->data, g));
		else if (check == 0)
			return (ft_cmd_exec(cmds->data, g));
		else
			return (builtin_pipe_set(cmds->data, g));
	}
	if (cmds->type == FT_PIPE)
		return (ft_pipe_exec(cmds->data, g));
	if (cmds->type == FT_REDIRECT)
		return (ft_redir_exec(cmds->data, g));
	if (cmds->type == FT_CTR_OP)
		return (ft_ctr_op_exec(cmds->data, g));
	return (SUCCESS);
}
