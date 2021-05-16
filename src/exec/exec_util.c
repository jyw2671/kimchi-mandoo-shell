/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_util.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjung <yjung@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 12:58:07 by yjung             #+#    #+#             */
/*   Updated: 2021/05/16 19:06:36 by yjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_ctr_op_exec(t_ctr_op *ctr, t_check *g)
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

int	parse_cmd_err_check(char *args)
{
	if ((int)args == PARSE_MALLOC)
		ft_error_print(PARSE_MALLOC_MSG, strerror(errno));
	else if ((int)args == PARSE_CMD_NONE)
		ft_error_print(PARSE_CMD_NONE_MSG, strerror(errno));
	else
		return (SUCCESS);
	return (FAIL);
}

int	ft_make_cmd(char *cmd, t_list *lst)
{
	int		status;
	int		cnt;
	t_list	*curr;
	char	**args;

	status = 0;
	if (!ft_malloc((void **)&args, sizeof(char *) * (ft_lstsize(lst) + 2)))
		// TODO: 예외처리 필요
		return (FAIL);
	cnt = 0;
	// TODO: 분리 필요!
	args[cnt++] = parse_cmd(normalize(&cmd, NORMALIZE_CMD));
	if (parse_cmd_err_check(args[0]) == -1)
		return (FAIL);
	curr = lst;
	while (curr)
	{
		args[cnt] = normalize((char **)&curr->content, NORMALIZE_CMD);
		if (parse_cmd_err_check(args[cnt++]) == -1)
			return (FAIL);
		curr = curr->next;
	}
	args[cnt] = NULL;
	status = execve(args[0], args, (char **)ft_lst_to_array(g_sh.envp));
	return (status);
}
