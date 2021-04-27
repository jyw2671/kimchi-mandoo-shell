/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeskim <jaeskim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 13:39:46 by jaeskim           #+#    #+#             */
/*   Updated: 2021/04/27 14:17:50 by jaeskim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "parse_util.h"

t_list	*parse_line(char *line)
{
	t_list	*result;
	t_list	*curr;

	printf("%sCMD: %s%s%s\n", TEXT_COLOR, VALUE_COLOR, line, NO_COLOR);
	printf("%s=============================================================%s\n",
		TEXT_COLOR, NO_COLOR);
	result = lexical_analyzer(line);
	if (result == PARSE_MALLOC)
		printf("%sERROR: Memory allocation failure%s\n", TEXT_COLOR, NO_COLOR);
	else if (result == (t_list *)PARSE_INVAILD)
		printf("%sERROR: Invaild command%s\n", TEXT_COLOR, NO_COLOR);
	else if (result == (t_list *)PARSE_UNEXPECT)
		printf("%sbash: syntax error near unexpected token%s\n", \
			TEXT_COLOR, NO_COLOR);
	else
	{
		result = syntax_analyzer(result);
		if (result == PARSE_MALLOC)
			printf("%sERROR: Memory allocation failure%s\n",
				TEXT_COLOR, NO_COLOR);
		else
		{
			curr = result;
			while (curr)
			{
				print_AST(curr->content, 0);
				curr = curr-> next;
			}
		}
	}
	return (result);
}
