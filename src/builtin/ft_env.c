/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjung <yjung@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 21:09:30 by yjung             #+#    #+#             */
/*   Updated: 2021/05/07 21:23:11 by yjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_print_envp(t_list **envp, int check)
{
	t_list	**env;

	env = envp;
	//	export시
	if (check == EXPORT)
	{
		while (*env)
		{
			ft_putstr_fd("declare -x " ,STDOUT_FILENO);
			ft_putstr_fd((*env)->content, STDOUT_FILENO);
			*env = (*env)->next;
		}
		return ;
	}
	// env시
	while (*env)
	{
		// 이미 존재하던 env를 export A= 같은 명령어로 빈값으로 만들시에는
		// env에서 검색이 가능하므로
		if (strchr((*env)->content, '=') != 0)
			ft_putstr_fd((*env)->content, STDOUT_FILENO);
		*env = (*env)->next;
	}
}

int	ft_env(t_list **envp)
{
	int	status;

	status = 0;
	ft_print_envp(envp, ENV);
	return (status);
}
