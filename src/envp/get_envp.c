/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_envp.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjung <yjung@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/09 12:24:13 by jaeskim           #+#    #+#             */
/*   Updated: 2021/05/16 17:49:52 by yjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_list	*get_envp(char *name, t_list *envp)
{
	char	*ptr;
	int		len;

	ptr = ft_strchr(name, '=');
	if (ptr)
		len = ptr - name;
	else
		len = ft_strlen(name);
	while (envp)
	{
		if (!ft_strncmp(envp->content, name, len))
		{
			if (*(char *)(envp->content + len) == '=' || \
				*(char *)(envp->content + len) == '\0')
				return (envp);
		}
		envp = envp->next;
	}
	return (NULL);
}
