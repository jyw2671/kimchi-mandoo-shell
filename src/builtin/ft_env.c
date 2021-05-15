/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjung <yjung@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 21:09:30 by yjung             #+#    #+#             */
/*   Updated: 2021/05/15 22:15:48 by yjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	print_envp(int is_export)
{
	t_list	*env;

	env = g_sh.envp;
	if (is_export)
	{
		while (env)
		{
			ft_putstr_fd("declare -x " ,STDOUT_FILENO);
			ft_putstr_fd(env->content, STDOUT_FILENO);
			env = env->next;
			ft_putstr_fd("\n", STDOUT_FILENO);
		}
		return ;
	}
	while (env)
	{
		if (strchr(env->content, '=') != 0)
			ft_putstr_fd(env->content, STDOUT_FILENO);
		env = env->next;
		ft_putstr_fd("\n", STDOUT_FILENO);
	}
}

int	ft_env(void)
{
	int	status;

	status = 0;
	print_envp(0);
	return (status);
}
