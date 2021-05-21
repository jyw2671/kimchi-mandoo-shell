/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjung <yjung@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 21:09:30 by yjung             #+#    #+#             */
<<<<<<< Updated upstream
/*   Updated: 2021/05/09 16:27:36 by yjung            ###   ########.fr       */
=======
<<<<<<< HEAD
/*   Updated: 2021/05/16 19:56:41 by yjung            ###   ########.fr       */
=======
/*   Updated: 2021/05/09 16:27:36 by yjung            ###   ########.fr       */
>>>>>>> origin/master
>>>>>>> Stashed changes
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

<<<<<<< Updated upstream
void	ft_print_envp(int check)
=======
<<<<<<< HEAD
static void	print_error(char *env)
{
	ft_putstr_fd("env: ", 2);
	ft_putstr_fd(env, 2);
	ft_putstr_fd(": No such file or directory\n", 2);
}

static void	print_env(void)
=======
void	ft_print_envp(int check)
>>>>>>> origin/master
>>>>>>> Stashed changes
{
	t_list	*env;

	env = g_sh.envp;
<<<<<<< Updated upstream
	//	export시
	if (check == EXPORT)
	{
		while (env)
		{
			ft_putstr_fd("declare -x " ,STDOUT_FILENO);
			ft_putstr_fd(env->content, STDOUT_FILENO);
			env = env->next;
		}
		return ;
	}
	// env시
	while (env)
	{
		// 이미 존재하던 env를 export A= 같은 명령어로 빈값으로 만들시에는
		// env에서 검색이 가능하므로
=======
<<<<<<< HEAD
	while (env)
	{
=======
	//	export시
	if (check == EXPORT)
	{
		while (env)
		{
			ft_putstr_fd("declare -x " ,STDOUT_FILENO);
			ft_putstr_fd(env->content, STDOUT_FILENO);
			env = env->next;
		}
		return ;
	}
	// env시
	while (env)
	{
		// 이미 존재하던 env를 export A= 같은 명령어로 빈값으로 만들시에는
		// env에서 검색이 가능하므로
>>>>>>> origin/master
>>>>>>> Stashed changes
		if (strchr(env->content, '=') != 0)
			ft_putstr_fd(env->content, STDOUT_FILENO);
		env = env->next;
		ft_putstr_fd("\n", STDOUT_FILENO);
	}
}

<<<<<<< Updated upstream
int	ft_env(void)
{
=======
<<<<<<< HEAD
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
=======
int	ft_env(void)
{
>>>>>>> Stashed changes
	int	status;

	status = 0;
	ft_print_envp(ENV);
	return (status);
<<<<<<< Updated upstream
=======
>>>>>>> origin/master
>>>>>>> Stashed changes
}
