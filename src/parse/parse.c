/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeskim <jaeskim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 13:39:46 by jaeskim           #+#    #+#             */
/*   Updated: 2021/04/28 16:31:51 by jaeskim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "parse_util.h"

t_list	*parse_line(char *line)
{
	t_list	*result;

	result = lexical_analyzer(line);
	if (result < (t_list *)PARSE_ERROR_COUNT)
		return (result);
	result = syntax_analyzer(result);
	return (result);
}
