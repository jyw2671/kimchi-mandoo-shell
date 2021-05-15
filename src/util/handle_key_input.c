/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_key_input.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeskim <jaeskim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 18:57:48 by jaeskim           #+#    #+#             */
/*   Updated: 2021/05/15 22:22:18 by jaeskim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*handle_key_delete(char *line)
{
	char	*new_line;
	char	*new_line_front;

	new_line_front = ft_strndup(line, g_sh.cmd_i - 1);
	if (new_line_front == NULL)
		return (0);
	if (g_sh.cmd_i != g_sh.cmd_s)
		new_line = ft_strjoin_free(new_line_front, line + g_sh.cmd_i, 1);
	else
		new_line = new_line_front;
	--g_sh.cmd_i;
	--g_sh.cmd_s;
	cursor_left();
	delete_char();
	ft_free(line);
	return (new_line);
}

static void	handle_key_move(int keycode)
{
	if (g_sh.cmd_i > 0 && keycode == ARROW_LEFT)
	{
		cursor_left();
		--g_sh.cmd_i;
	}
	else if (g_sh.cmd_i < g_sh.cmd_s && keycode == ARROW_RIGHT)
	{
		cursor_right();
		++g_sh.cmd_i;
	}
	else if (keycode == CTRL_LEFT)
		cursor_ctrl_left();
	else if (keycode == CTRL_RIGHT)
		cursor_ctrl_right();
}

static void	handle_home_end(int keycode)
{
	if (keycode == KEY_HOME)
	{
		while (g_sh.cmd_i > 0)
		{
			cursor_left();
			--g_sh.cmd_i;
		}
	}
	else if (keycode == KEY_END)
	{
		while (g_sh.cmd_i < g_sh.cmd_s)
		{
			cursor_right();
			++g_sh.cmd_i;
		}
	}
}

void	handle_key_input(int keycode)
{
	if (g_sh.cmd && is_arrow_up_down(keycode))
		return (handle_history(keycode));
	if (is_delete(keycode) && g_sh.cmd_i > 0)
	{
		g_sh.line = handle_key_delete(g_sh.line);
		if (g_sh.line == NULL)
		{
			ft_putstr_fd(strerror(errno), 2);
			exit_minishell(1);
		}
		return ;
	}
	if (is_eof(keycode) && (g_sh.line == NULL || !*g_sh.line))
	{
		ft_free(g_sh.line);
		ft_putstr_fd("exit\n", 2);
		exit_minishell(0);
	}
	if (is_arrow_left_right(keycode))
		return (handle_key_move(keycode));
	if (keycode == KEY_HOME || keycode == KEY_END)
		handle_home_end(keycode);
}
