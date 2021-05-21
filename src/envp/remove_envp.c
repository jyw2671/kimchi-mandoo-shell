/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_envp.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjung <yjung@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 21:05:42 by yjung             #+#    #+#             */
/*   Updated: 2021/05/21 19:12:18 by yjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static t_list	*get_envp_cnt(char *name, t_list *envp, int *cnt)
{
	char	*ptr;
	int		len;

	ptr = ft_strchr(name, '=');
	if (ptr)
		len = ptr - name;
	else
		len = ft_strlen(name);
	*cnt = 0;
	while (envp && ++(*cnt) >= 0)
	{
		if (!ft_strncmp(envp->content, name, len))
		{
			if (*(char *)(envp->content + len) == '=' || \
				*(char *)(envp->content + len) == '\0')
				return (envp);
		}
		envp = envp->next;
	}
	*cnt = 0;
	return (NULL);
}

static t_list	*envp_cnt(t_list *envp, int cnt)
{
	if (cnt <= 0)
		return (NULL);
	while (--cnt > 0)
		envp = envp->next;
	return (envp);
}

int	remove_envp(char *value)
{
	t_list	*envp;
	t_list	*pre;
	t_list	*nex;
	int		cnt;

	envp = get_envp_cnt(value, g_sh.envp, &cnt);
	if (envp)
	{
		pre = envp_cnt(g_sh.envp, cnt - 1);
		if (envp->next == NULL)
			nex = NULL;
		else
			nex = envp->next;
		ft_lstdelone(envp, ft_free);
		if (pre)
			pre->next = nex;
		return (SUCCESS);
	}
	return (SUCCESS);
}
