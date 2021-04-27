/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_AST_util.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeskim <jaeskim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 18:14:08 by jaeskim           #+#    #+#             */
/*   Updated: 2021/04/26 18:16:39 by jaeskim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "parse_util.h"

void	print_depth(int depth)
{
	while (depth--)
		printf("\t");
}
