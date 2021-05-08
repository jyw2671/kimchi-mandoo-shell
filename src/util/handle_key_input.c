/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_key_input.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeskim <jaeskim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 18:57:48 by jaeskim           #+#    #+#             */
/*   Updated: 2021/05/08 18:31:25 by jaeskim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*handle_key_delete(t_minishell *g, char *line)
{
	char	*new_line;
	char	*new_line_front;

	new_line_front = ft_strndup(line, g->cmd_i - 1);
	if (new_line_front == NULL)
		return (0);
	if (g->cmd_i != g->cmd_s)
		new_line = ft_strjoin_free(new_line_front, line + g->cmd_i, 1);
	else
		new_line = new_line_front;
	--g->cmd_i;
	--g->cmd_s;
	cursor_left();
	delete_char();
	ft_free(line);
	return (new_line);
}

static void	handle_key_move(t_minishell *g, int keycode)
{
	if (g->cmd_i > 0 && keycode == ARROW_LEFT)
	{
		cursor_left();
		--g->cmd_i;
	}
	else if (g->cmd_i < g->cmd_s && keycode == ARROW_RIGHT)
	{
		cursor_right();
		++g->cmd_i;
	}
}

char	*handle_key_input(t_minishell *g, int keycode, char *line)
{
	if (g->cmd && is_arrow_up_down(keycode))
		return (handle_history(g, line, keycode));
	if (is_delete(keycode) && g->cmd_i > 0)
	{
		line = handle_key_delete(g, line);
		if (line == NULL)
		{
			ft_putstr_fd(strerror(errno), 2);
			exit_minishell(g, 1);
		}
		return (line);
	}
	if (is_eof(keycode) && (line == NULL || !*line))
	{
		ft_free(line);
		ft_putstr_fd("exit\n", 2);
		exit_minishell(g, 0);
	}
	if (is_arrow_left_right(keycode))
		handle_key_move(g, keycode);
	return (line);
}
