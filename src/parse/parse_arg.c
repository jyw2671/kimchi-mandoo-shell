/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeskim <jaeskim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 09:31:53 by jaeskim           #+#    #+#             */
/*   Updated: 2021/05/11 15:38:28 by jaeskim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_list	*parse_arg(char *arg)
{
	t_list	*token;

	if (!ft_malloc((void **)&token, sizeof(t_list)))
		return (NULL);
	token->content = normalize(&arg, NORMALIZE_CMD);
	if (token->content == NULL)
	{
		free(token);
		return (NULL);
	}
	return (token);
}
