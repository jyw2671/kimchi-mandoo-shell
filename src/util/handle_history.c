/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_history.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeskim <jaeskim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 17:46:14 by jaeskim           #+#    #+#             */
/*   Updated: 2021/05/21 15:11:36 by jaeskim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	handle_history_prev_new(void)
{
	if (!ft_malloc((void **)&g_sh.cmd->next, sizeof(t_history)))
	{
		ft_putstr_fd(strerror(errno), 2);
		ft_free(g_sh.line);
		exit_minishell(1);
	}
	ft_free(g_sh.cmd->next->edit_cmd);
	g_sh.cmd->next->edit_cmd = g_sh.line;
	g_sh.cmd->next->prev = g_sh.cmd;
	g_sh.cmd = g_sh.cmd->next;
	g_sh.history = g_sh.cmd->prev;
}

static int	handle_history_prev(void)
{
	if (g_sh.history->prev == NULL)
		return (1);
	ft_free(g_sh.history->edit_cmd);
	g_sh.history->edit_cmd = g_sh.line;
	g_sh.history = g_sh.history->prev;
	return (0);
}

static int	handle_history_next(void)
{
	if (g_sh.history->next == NULL)
		return (1);
	ft_free(g_sh.history->edit_cmd);
	g_sh.history->edit_cmd = g_sh.line;
	g_sh.history = g_sh.history->next;
	return (0);
}

void	handle_history(int keycode)
{
	if (keycode == ARROW_UP && !g_sh.history->next && \
		!g_sh.cmd->next && g_sh.cmd->cmd)
		handle_history_prev_new();
	else if (keycode == ARROW_UP && handle_history_prev())
		return ;
	else if (keycode == ARROW_DOWN && handle_history_next())
		return ;
	delete_line();
	print_PS();
	if (g_sh.history->edit_cmd)
		g_sh.line = g_sh.history->edit_cmd;
	else
		g_sh.line = g_sh.history->cmd;
	g_sh.cmd_s = ft_strlen(g_sh.line);
	g_sh.cmd_i = g_sh.cmd_s;
	ft_putstr_fd(g_sh.line, 1);
	g_sh.line = ft_strdup(g_sh.line);
	if (g_sh.line == NULL)
	{
		ft_putstr_fd(strerror(errno), 2);
		exit_minishell(1);
	}
}
