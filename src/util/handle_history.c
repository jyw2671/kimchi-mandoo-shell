/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_history.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeskim <jaeskim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 17:46:14 by jaeskim           #+#    #+#             */
/*   Updated: 2021/05/07 01:52:28 by jaeskim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	handle_history_prev_new(t_minishell *g, char *line)
{
	if (!ft_malloc((void **)&g->cmd->next, sizeof(t_history)))
	{
		ft_putstr_fd(strerror(errno), 2);
		ft_free(line);
		exit_minishell(g, 1);
	}
	ft_free(g->cmd->next->edit_cmd);
	g->cmd->next->edit_cmd = line;
	g->cmd->next->prev = g->cmd;
	g->cmd = g->cmd->next;
	g->history = g->cmd->prev;
}

static int	handle_history_prev(t_minishell *g, char *line)
{
	if (g->history->prev == NULL)
		return (1);
	ft_free(g->history->edit_cmd);
	g->history->edit_cmd = line;
	g->history = g->history->prev;
	return (0);
}

static int	handle_history_next(t_minishell *g, char *line)
{
	if (g->history->next == NULL)
		return (1);
	ft_free(g->history->edit_cmd);
	g->history->edit_cmd = line;
	g->history = g->history->next;
	return (0);
}

char	*handle_history(t_minishell *g, char *line, int keycode)
{
	char	*result;

	if (keycode == ARROW_UP && \
		g->cmd == g->history && !g->cmd->next && g->cmd->cmd)
		handle_history_prev_new(g, line);
	else if (keycode == ARROW_UP && handle_history_prev(g, line))
		return (line);
	else if (keycode == ARROW_DOWN && handle_history_next(g, line))
		return (line);
	delete_line();
	print_PS1();
	if (g->history->edit_cmd)
		result = g->history->edit_cmd;
	else
		result = g->history->cmd;
	g->cmd_s = ft_strlen(result);
	g->cmd_i = g->cmd_s;
	ft_putstr_fd(result, 1);
	result = ft_strdup(result);
	if (result == NULL)
	{
		ft_putstr_fd(strerror(errno), 2);
		exit_minishell(g, 1);
	}
	return (result);
}
