/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjung <yjung@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 21:09:30 by yjung             #+#    #+#             */
/*   Updated: 2021/05/16 19:56:41 by yjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	print_error(char *env)
{
	ft_putstr_fd("env: ", 2);
	ft_putstr_fd(env, 2);
	ft_putstr_fd(": No such file or directory\n", 2);
}

static void	print_env(void)
{
	t_list	*env;

	env = g_sh.envp;
	while (env)
	{
		if (strchr(env->content, '=') != 0)
			ft_putstr_fd(env->content, STDOUT_FILENO);
		env = env->next;
		ft_putstr_fd("\n", STDOUT_FILENO);
	}
}

int	ft_env(t_list *args)
{
	if (args == NULL)
		print_env();
	else
	{
		print_error(args->content);
		return (FAIL);
	}
	return (SUCCESS);
}
