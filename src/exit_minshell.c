/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_minshell.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeskim <jaeskim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/07 01:29:10 by jaeskim           #+#    #+#             */
/*   Updated: 2021/05/09 14:24:43 by jaeskim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	free_cmd_history(t_history	*cmd)
{
	t_history	*tmp;

	while (cmd)
	{
		tmp = cmd->prev;
		ft_free(cmd->cmd);
		ft_free(cmd->edit_cmd);
		ft_free(cmd);
		cmd = tmp;
	}
}

void	exit_minishell(int exitcode)
{
	ft_lstclear(&g_sh.envp, ft_free);
	free_cmd_history(g_sh.cmd);
	exit(exitcode);
}
