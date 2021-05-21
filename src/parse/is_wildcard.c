/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_wildcard.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeskim <jaeskim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 21:41:11 by jaeskim           #+#    #+#             */
/*   Updated: 2021/05/17 22:51:59 by jaeskim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "parse_util.h"

int	is_wildcard(char *str)
{
	int		flag;

	flag = TK_NONE;
	while (*str)
	{
		if (flag == TK_NONE && *str == '*')
			return (1);
		if (!(flag & ~(TK_QOUTES)) && *str == '"')
			flag ^= TK_QOUTES;
		else if (!(flag & ~(TK_QOUTE)) && *str == '\'')
			flag ^= TK_QOUTE;
		else if (!(flag & ~(TK_QOUTE)) && *str == '\\')
			flag |= TK_ESCAPE;
		else if ((flag & TK_ESCAPE) && *(str - 1) != '\\')
			flag &= ~TK_ESCAPE;
		++str;
	}
	return (0);
}
