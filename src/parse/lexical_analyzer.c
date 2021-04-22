/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexical_analyzer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeskim <jaeskim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 23:44:09 by jaeskim           #+#    #+#             */
/*   Updated: 2021/04/22 03:19:59 by jaeskim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "parse_util.h"

static t_list	*destructor(t_list *result, void *err)
{
	t_list	*prev;

	while (result)
	{
		if (result->content)
		{
			ft_free(((t_type *)result->content)->value);
			ft_free(result->content);
		}
		prev = result;
		result = result->next;
		free(prev);
	}
	return (err);
}

static void	token_lexer(t_type *data, char **line, int *status)
{
	if (ft_strchr("<>|&;", **line))
	{
		data->value = get_static_token(line, status);
		if (*status & LX_REDIRECT)
			data->type = LX_REDIRECT;
		else
			data->type = *status & ~LX_CMD;
	}
	else
	{
		data->value = get_token(line);
		if (*status & LX_REDIRECT)
		{
			data->type = LX_FILE;
			*status &= ~LX_REDIRECT;
		}
		else if (*status & LX_CMD)
			data->type = LX_ARG;
		else
		{
			*status = (*status & LX_REDIRECT) + LX_CMD;
			data->type = LX_CMD;
		}
	}
}

static void	skip_IFS(char **line)
{
	while (**line && ft_strchr(TK_IFS, **line))
		++(*line);
}

static int	check_token_lexer(t_type *data, char **line, int *status, char **e)
{
	token_lexer(data, line, status);
	if (data->value <= (char *)PARSE_ERROR)
	{
		*e = data->value;
		data->value = NULL;
		return (0);
	}
	return (1);
}

t_list	*lexical_analyzer(char *line)
{
	t_list	*curr;
	t_list	*result;
	int		status;
	char	*err;

	status = 0;
	if (!ft_malloc((void **)&result, sizeof(t_list)))
		return (PARSE_MALLOC);
	skip_IFS(&line);
	curr = result;
	while (*line)
	{
		if (!ft_malloc(&curr->content, sizeof(t_type)))
			return (destructor(result, PARSE_MALLOC));
		if (!check_token_lexer(curr->content, &line, &status, &err))
			return (destructor(result, err));
		if (!ft_malloc((void **)&curr->next, sizeof(t_list)))
			return (destructor(result, PARSE_MALLOC));
		curr = curr->next;
		skip_IFS(&line);
	}
	if (status & ~LX_CMD)
		return (destructor(result, (char *)PARSE_UNEXPECT));
	return (result);
}
