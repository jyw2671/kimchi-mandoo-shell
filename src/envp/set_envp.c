/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_envp.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjung <yjung@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 17:42:02 by yjung             #+#    #+#             */
/*   Updated: 2021/05/16 19:03:05 by yjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static t_list	*new_envp(char *value)
{
	t_list	*reuslt;

	if (!ft_malloc((void **)&reuslt, sizeof(t_list)))
		return (NULL);
	reuslt->content = value;
	return (reuslt);
}

int	set_envp(char *value)
{
	t_list	*envp;

	if (g_sh.envp == NULL)
	{
		g_sh.envp = new_envp(value);
		if (g_sh.envp == NULL)
			return (MALLOC_FAIL);
		return (SUCCESS);
	}
	envp = get_envp(value, g_sh.envp);
	if (envp)
	{
		ft_free(envp->content);
		envp->content = value;
		return (SUCCESS);
	}
	envp = ft_lstlast(g_sh.envp);
	envp->next = new_envp(value);
	if (envp->next == NULL)
		return (MALLOC_FAIL);
	return (SUCCESS);
}
