/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjung <yjung@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 21:09:30 by yjung             #+#    #+#             */
/*   Updated: 2021/05/22 13:41:25 by yjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	print_error(char *env, t_check *g)
{
	ft_putstr_fd("env: ", 2);
	ft_putstr_fd(env, 2);
	if (g->args_check)
		ft_putstr_fd(": Permission denied\n", 2);
	else
		ft_putstr_fd(": No such file or directory\n", 2);
}

static void	print_env(void)
{
	t_list	*env;

	env = g_sh.envp;
	while (env)
	{
		if (strchr(env->content, '=') != 0)
			ft_putendl_fd(env->content, STDOUT_FILENO);
		env = env->next;
	}
}

int	ft_env(t_list *args, t_check *g)
{
	if (args == NULL)
		print_env();
	else
	{
		print_error(args->content, g);
		if (g->args_check)
			return (126);
		else
			return (127);
	}
	return (SUCCESS);
}
