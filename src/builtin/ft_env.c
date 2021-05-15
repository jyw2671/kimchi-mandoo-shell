/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjung <yjung@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 21:09:30 by yjung             #+#    #+#             */
/*   Updated: 2021/05/15 15:01:52 by yjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_print_envp(int check)
{
	t_list	*env;

	env = g_sh.envp;
	//	export시
	if (check == EXPORT)
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
	// env시
	while (env)
	{
		// 이미 존재하던 env를 export A= 같은 명령어로 빈값으로 만들시에는
		// env에서 검색이 가능하므로
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
	ft_print_envp(ENV);
	return (status);
}
