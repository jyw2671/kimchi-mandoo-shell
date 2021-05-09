/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_envp.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeskim <jaeskim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/09 12:24:13 by jaeskim           #+#    #+#             */
/*   Updated: 2021/05/09 15:36:35 by jaeskim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_list	*get_envp(char *target, t_list *envp)
{
	int		len;

	len = ft_strlen(target);
	while (envp)
	{
		if (!ft_strncmp(envp->content, target, len))
		{
			if (*(char *)(envp->content + len) == '=' || \
				*(char *)(envp->content + len) == '\0')
				return (envp);
		}
		envp = envp->next;
	}
	return (NULL);
}
