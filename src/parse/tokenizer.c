/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeskim <jaeskim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 20:24:25 by jaeskim           #+#    #+#             */
/*   Updated: 2021/04/20 18:59:35 by jaeskim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "parse_util.h"

static void	*free_tokenizer(t_list *token, void *ret)
{
	ft_lstclear(&token, ft_free);
	return (ret);
}

static int	check_flag(int flag, char **line)
{
	if (flag == TK_NONE)
	{
		if (**line == '\'')
			flag |= TK_QOUTE;
		if (**line == '"')
			flag |= TK_QOUTES;
	}
	else if (!(flag & TK_ESCAPE))
	{
		if (**line == '\\')
			flag |= TK_ESCAPE;
		else if (flag & TK_QOUTE && **line == '\'')
			flag ^= TK_QOUTE;
		else if (flag & TK_QOUTES && **line == '"')
			flag ^= TK_QOUTES;
	}
	else if (flag & TK_ESCAPE && *(*line - 1) == '\\')
		flag ^= TK_ESCAPE;
	return (flag);
}

static char	*get_static_token(char **line)
{
	char	*token;

	token = 0;
	if (!ft_strncmp(*line, "<<", 2))
		token = ft_strndup_move("<<", 2, line);
	else if (!ft_strncmp(*line, ">>", 2))
		token = ft_strndup_move(">>", 2, line);
	else if (!ft_strncmp(*line, "<", 1))
		token = ft_strndup_move("<", 1, line);
	else if (!ft_strncmp(*line, ">", 1))
		token = ft_strndup_move(">", 1, line);
	else if (!ft_strncmp(*line, "&&", 2))
		token = ft_strndup_move("&&", 2, line);
	else if (!ft_strncmp(*line, "||", 2))
		token = ft_strndup_move("||", 2, line);
	else if (!ft_strncmp(*line, "|", 1))
		token = ft_strndup_move("|", 1, line);
	return (token);
}

static char	*get_token(char **line)
{
	int		flag;
	char	*token;
	char	temp[2];

	if (ft_strchr("<>|&;", **line))
		return (get_static_token(line));
	flag = TK_NONE;
	token = ft_strdup("");
	temp[1] = 0;
	if (token == NULL)
		return (0);
	while (**line && !(flag == TK_NONE && ft_strchr(" \n\t<>|&;", **line)))
	{
		flag = check_flag(flag, line);
		temp[0] = **line;
		token = ft_strjoin_free(token, temp, 1);
		if (token == NULL)
			return ((char *)ft_free_ret(token, (char *)PARSE_MALLOC));
		++(*line);
	}
	if (flag != TK_NONE)
		return ((char *)ft_free_ret(token, (char *)PARSE_INVAILD));
	return (token);
}

char	**tokenizer(char *line)
{
	t_list	*curr;
	t_list	*token;

	token = ft_lstnew(0);
	if (token == NULL)
		return (PARSE_MALLOC);
	while (*line && ft_strchr(TK_IFS, *line))
		++line;
	curr = token;
	while (*line)
	{
		curr->content = get_token(&line);
		if (curr->content == (void *)PARSE_INVAILD)
		{
			curr->content = NULL;
			return ((char **)free_tokenizer(token, (void *)PARSE_INVAILD));
		}
		curr->next = ft_lstnew(0);
		if (curr->next == NULL || curr->content == NULL)
			return ((char **)free_tokenizer(token, (void *)PARSE_MALLOC));
		curr = curr->next;
		while (*line && ft_strchr(TK_IFS, *line))
			++line;
	}
	return ((char **)ft_lst_to_array(&token));
}
