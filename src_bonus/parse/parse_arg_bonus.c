/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_arg_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeskim <jaeskim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 09:31:53 by jaeskim           #+#    #+#             */
/*   Updated: 2021/05/17 22:52:00 by jaeskim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "parse_util.h"
#include <glob.h>

static t_list	*free_ret(t_list *target, t_list *ret, glob_t *glob)
{
	if (target)
		ft_lstclear(&target, ft_free);
	if (glob)
		globfree(glob);
	return (ret);
}

static t_list	*new_wildcard_lst(char *arg, int index)
{
	glob_t	globbuf;
	t_list	*result;
	t_list	**curr;
	char	*regex;

	regex = normalize(&arg, NORMALIZE_ARG);
	if (regex == NULL)
		return (PARSE_MALLOC);
	curr = &result;
	glob(regex, GLOB_MARK | GLOB_NOSORT, NULL, &globbuf);
	if (globbuf.gl_matchc == 0)
		return (free_ret(NULL, (t_list *)PARSE_WILDCARD, &globbuf));
	while (index < globbuf.gl_matchc)
	{
		if (!ft_malloc((void **)curr, sizeof(t_list)))
			return (free_ret(result, PARSE_MALLOC, &globbuf));
		(*curr)->content = ft_strdup(globbuf.gl_pathv[index++]);
		if ((*curr)->content == NULL)
			return (free_ret(result, PARSE_MALLOC, &globbuf));
		curr = &(*curr)->next;
	}
	globfree(&globbuf);
	return (result);
}

static t_list	*normalize_arg(char *arg)
{
	t_list	*result;

	if (is_wildcard(arg))
		return (new_wildcard_lst(arg, 0));
	if (!ft_malloc((void **)&result, sizeof(t_list)))
		return (PARSE_MALLOC);
	result->content = normalize(&arg, NORMALIZE_CMD);
	if (result->content == NULL)
	{
		ft_free(result);
		return (PARSE_MALLOC);
	}
	return (result);
}

t_list	*parse_arg(t_list *args)
{
	t_list	*result;
	t_list	**curr;

	result = NULL;
	curr = &result;
	while (args)
	{
		*curr = normalize_arg(args->content);
		if (*curr == PARSE_MALLOC)
			return (free_ret(result, PARSE_MALLOC, NULL));
		if (*curr == (t_list *)PARSE_WILDCARD)
		{
			*curr = NULL;
			return (free_ret(result, (t_list *)PARSE_WILDCARD, NULL));
		}
		args = args->next;
		curr = &ft_lstlast(*curr)->next;
	}
	return (result);
}
