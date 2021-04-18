/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeskim <jaeskim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 20:24:25 by jaeskim           #+#    #+#             */
/*   Updated: 2021/04/18 15:44:40 by jaeskim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "parse_util.h"

static int	check_flag(int flag, char **line)
{
	if (!(flag & TK_ESCAPE) && !(flag & TK_QOUTE) && !(flag & TK_QOUTES))
	{
		if (**line == '\\')
			flag |= TK_ESCAPE;
		else if (**line == '\'')
			flag |= TK_QOUTE;
		else if (**line == '"')
			flag |= TK_QOUTES;
	}
	else if (!(flag & TK_ESCAPE))
	{
		if (flag & TK_QOUTE && **line == '\'')
			flag ^= TK_QOUTE;
		if (flag & TK_QOUTES && **line == '"')
			flag ^= TK_QOUTES;
	}
	else if (flag & TK_ESCAPE && *(*line - 1) == '\\')
		flag ^= TK_ESCAPE;
	return (flag);
}

static char	*strdup_move(char *str, char **line, int n)
{
	*line += n;
	return (ft_strdup(str));
}

static char	*get_static_token(char **line)
{
	char	*token;

	token = 0;
	if (!ft_strncmp(*line, "<<", 2))
		token = strdup_move("<<", line, 2);
	else if (!ft_strncmp(*line, ">>", 2))
		token = strdup_move(">>", line, 2);
	else if (!ft_strncmp(*line, "<", 1))
		token = strdup_move("<", line, 1);
	else if (!ft_strncmp(*line, ">", 1))
		token = strdup_move(">", line, 1);
	else if (!ft_strncmp(*line, "&&", 2))
		token = strdup_move("&&", line, 2);
	else if (!ft_strncmp(*line, "||", 2))
		token = strdup_move("||", line, 2);
	else if (!ft_strncmp(*line, "|", 1))
		token = strdup_move("|", line, 1);
	if (token == NULL)
		parse_exit("ERROR: Memory allocation failure\n");
	return (token);
}

static char	*get_token(char **line)
{
	int		flag;
	char	*token;
	char	temp[2];

	flag = TK_NONE;
	token = ft_strdup("");
	temp[1] = 0;
	if (token == NULL)
		parse_exit("ERROR: Memory allocation failure\n");
	while (**line && !(flag == TK_NONE && ft_strchr(" <>|&;", **line)))
	{
		flag = check_flag(flag, line);
		temp[0] = **line;
		token = ft_strjoin_free(token, temp, 1);
		if (token == NULL)
			parse_exit("ERROR: Memory allocation failure\n");
		++(*line);
	}
	if (flag != TK_NONE)
		parse_exit("ERROR: Invaild command\n");
	return (token);
}

char	**tokenizer(char *line)
{
	t_list	*token;

	token = ft_lstnew(0);
	if (token == NULL)
		parse_exit("ERROR: Memory allocation failure\n");
	while (*line && *line == ' ')
		++line;
	while (*line)
	{
		if (ft_strchr("<>|&;", *line))
			ft_lstlast(token)->content = get_static_token(&line);
		else
			ft_lstlast(token)->content = get_token(&line);
		ft_lstlast(token)->next = ft_lstnew(0);
		while (*line && *line == ' ')
			++line;
	}
	return ((char **)ft_lst_to_array(&token));
}
