/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeskim <jaeskim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 13:39:46 by jaeskim           #+#    #+#             */
/*   Updated: 2021/04/16 20:57:25 by jaeskim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "parse_util.h"

t_list	*parse_line(char *line)
{
	int		i;
	char	**tokens;

	printf("%sCMD: %s%s%s\n", TEXT_COLOR, VALUE_COLOR, line, NO_COLOR);
	printf("%s=============================================================%s\n",
		TEXT_COLOR, NO_COLOR);
	tokens = tokenizer(line);
	printf("[ ");
	i = 0;
	while (tokens[i])
	{
		printf("%s\"%s%s%s\"%s, ", \
			TEXT_COLOR, VALUE_COLOR, tokens[i], TEXT_COLOR, NO_COLOR);
		free(tokens[++i]);
	}
	printf("]\n");
	free(tokens);
	return (0);
}
