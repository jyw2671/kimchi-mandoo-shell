/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeskim <jaeskim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 13:39:46 by jaeskim           #+#    #+#             */
/*   Updated: 2021/04/22 03:20:00 by jaeskim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "parse_util.h"

char	*get_typestr(int type)
{
	if (type == LX_CMD)
		return ("CMD");
	if (type == LX_REDIRECT)
		return ("REDIRECT");
	if (type == LX_PIPE)
		return ("PIPE");
	if (type == LX_CTR_OP)
		return ("CTR_OP");
	if (type == LX_FILE)
		return ("FILE");
	if (type == LX_SEPERATOR)
		return ("SEPERATOR");
	if (type == LX_ARG)
		return ("ARG");
	return ("NONE");
}

void	print_types(t_list *curr)
{
	t_type	*data;

	printf("%s[ ", TEXT_COLOR);
	while (curr && curr->content)
	{
		data = curr->content;
		printf("%s{\"%s%s%s\" : \"%s%s%s\" }, ", \
			TEXT_COLOR, VALUE_COLOR, get_typestr(data->type), TEXT_COLOR,
			VALUE_COLOR, data->value, TEXT_COLOR);
		curr = curr->next;
	}
	printf("]%s\n", NO_COLOR);
}

t_list	*parse_line(char *line)
{
	t_list	*types;

	printf("%sCMD: %s%s%s\n", TEXT_COLOR, VALUE_COLOR, line, NO_COLOR);
	printf("%s=============================================================%s\n",
		TEXT_COLOR, NO_COLOR);
	types = lexical_analyzer(line);
	if (types == PARSE_MALLOC)
		printf("%sERROR: Memory allocation failure%s\n", TEXT_COLOR, NO_COLOR);
	else if (types == (t_list *)PARSE_INVAILD)
		printf("%sERROR: Invaild command%s\n", TEXT_COLOR, NO_COLOR);
	else if (types == (t_list *)PARSE_UNEXPECT)
		printf("%sbash: syntax error near unexpected token `?'%s\n", \
			TEXT_COLOR, NO_COLOR);
	else
		print_types(types);
	return (0);
}
