/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_line.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeskim <jaeskim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 18:19:08 by jaeskim           #+#    #+#             */
/*   Updated: 2021/05/08 00:45:13 by jaeskim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*append_char_malloc(t_minishell *g, char *line, char c)
{
	char	*result;

	if (line == NULL)
		return (ft_strndup(&c, 1));
	if (g->cmd_i == g->cmd_s)
		return (ft_strappendc(line, c));
	result = ft_strndup(line, g->cmd_i);
	if (result == NULL)
	{
		ft_free(line);
		return (NULL);
	}
	result = ft_strappendc(result, c);
	if (result == NULL)
	{
		ft_free(line);
		return (NULL);
	}
	result = ft_strjoin_free(result, line + g->cmd_i, 1);
	ft_free(line);
	if (result == NULL)
		return (0);
	return (result);
}

static char	*append_char(t_minishell *g, char *line, char c)
{
	int		i;
	char	*result;

	result = append_char_malloc(g, line, c);
	if (result == NULL)
		return (NULL);
	ft_putstr_fd(result + g->cmd_i, 1);
	i = g->cmd_s - g->cmd_i;
	while (i--)
		cursor_left();
	(++g->cmd_i && ++g->cmd_s);
	return (result);
}

static char	*setup_line_empty_cmd(t_minishell *g, char *line)
{
	ft_free(g->cmd->edit_cmd);
	g->cmd->edit_cmd = NULL;
	ft_free(g->history->edit_cmd);
	g->history->edit_cmd = NULL;
	g->cmd->cmd = line;
	g->history = g->cmd;
	return (line);
}

static char	*setup_line(t_minishell *g, char *line)
{
	t_history	*history;

	if (g->cmd && g->cmd->cmd == NULL)
		return (setup_line_empty_cmd(g, line));
	if (!ft_malloc((void **)&history, sizeof(t_history)))
	{
		ft_putstr_fd(strerror(errno), 2);
		ft_free(line);
		exit_minishell(g, 1);
	}
	history->cmd = line;
	if (g->cmd == NULL)
		g->cmd = history;
	else
	{
		g->cmd->next = history;
		history->prev = g->cmd;
		g->cmd = history;
	}
	g->history = g->cmd;
	return (line);
}

char	*get_line(t_minishell *g)
{
	char	*line;
	int		c;

	(!(line = 0) && !(g->cmd_i = 0) && (g->cmd_s = 0));
	c = getch(g);
	while (c != (int) '\n')
	{
		if (is_special_key(c))
			line = handle_key_input(g, c, line);
		else
		{
			line = append_char(g, line, c);
			if (line == NULL)
			{
				ft_putstr_fd(strerror(errno), 2);
				exit_minishell(g, 1);
			}
		}
		c = getch(g);
	}
	ft_putchar_fd('\n', 1);
	return (setup_line(g, line));
}
