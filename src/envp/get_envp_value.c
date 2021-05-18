/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_envp_value.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjung <yjung@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 12:51:06 by jaeskim           #+#    #+#             */
/*   Updated: 2021/05/17 21:47:42 by yjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*get_envp_value(char *name)
{
	char	*result;
	t_list	*env;

	env = get_envp(name, g_sh.envp);
	if (!env || !ft_strchr(env->content, '='))
		result = ft_strdup("");
	else
		result = ft_strdup(env->content + ft_strlen(name) + 1);
	return (result);
}
