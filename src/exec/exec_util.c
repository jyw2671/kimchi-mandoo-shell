/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_util.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeskim <jaeskim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 12:58:07 by yjung             #+#    #+#             */
/*   Updated: 2021/05/09 00:14:22 by jaeskim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_tree_parser(t_AST *cmds, t_list **envp, t_check *g)
{
	int		status;

	status = 0;
	if (cmds->type == FT_CMD)
	{
		if (g->pipe_cnt > 0)
			status = ft_cmd_pipe_set(cmds->data, envp, g);
		else
			status = ft_cmd_exec(cmds->data, envp, g);
	}
	else if (cmds->type == FT_PIPE)
		status = ft_pipe_exec(cmds->data, envp, g);
	else if (cmds->type == FT_REDIRECT)
		status = ft_redir_exec(cmds->data, envp, g);
	else if (cmds->type == FT_CTR_OP)
		status = ft_ctr_op_exec(cmds->data, envp, g);
	if (status != 0)
		return (status);
	return (status);
}

int	ft_ctr_op_exec(t_ctr_op *ctr, t_list **envp, t_check *g)
{
	int		status;

	status = 0;
	status = ft_tree_parser(ctr->left, envp, g);
	if (ctr->type == 2 && status != 0)
		return (status);
	status = ft_tree_parser(ctr->right, envp, g);
	return (status);
}

// quotes 처리...
// $ 치환...
// link_list 연결 후 free
static int	ft_make_cmd(char *cmd, t_list **envp, t_list *lst)
{
	int		status;
	int		cnt;
	t_list	*curr;
	char	**args;

	status = 0;
	if (!ft_malloc((void **)&args, sizeof(char *) * (ft_lstsize(lst) + 2)))
		// TODO: 예외처리 필요
		return (-1);
	cnt = 0;
	args[cnt++] = ft_strdup(cmd);
	curr = lst;
	while (curr)
	{
		args[cnt++] = ft_strdup(curr->content);
		curr = curr->next;
	}
	args[cnt] = NULL;
	status = execve(args[0], args, (char **)ft_lst_to_array(*envp));
	ft_lstclear(&lst, ft_free);
	exit(status);
	return (status);
}

int	ft_cmd_fork_set(t_cmd *cmds, t_list **envp, t_check *g)
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
		status = ft_redir_parser(g);
		if (status < 0)
			return (status);
		status = ft_make_cmd(cmds->cmd, envp, cmds->args);
		exit(status);
	}
	else if (pid > 0)
	{
		wait(&pid);
		ft_pipe_connect(&status, g);
		if (status < 0)
			return (status);
		status = ft_redir_parser(g);
	}
	return (status);
}
