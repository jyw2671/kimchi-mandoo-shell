/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_util.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeskim <jaeskim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 18:14:08 by jaeskim           #+#    #+#             */
/*   Updated: 2021/05/07 05:21:01 by jaeskim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "parse_util.h"

void	print_parse_err(t_list *err)
{
	if (err == (t_list *)PARSE_MALLOC)
		ft_putstr_fd(PARSE_MALLOC_MSG, 2);
	if (err == (t_list *)PARSE_UNEXPECT)
		ft_putstr_fd(PARSE_UNEXPECT_MSG, 2);
	if (err == (t_list *)PARSE_INVAILD)
		ft_putstr_fd(PARSE_INVAILD_MSG, 2);
}

void	print_depth(int depth)
{
	while (depth--)
		printf("\t");
}
