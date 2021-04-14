/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjung <yjung@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 19:40:29 by yjung             #+#    #+#             */
/*   Updated: 2021/04/14 19:49:03 by yjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	envp_len(char **envp)
{
	int		i;
	int		cnt;

	i = -1;
	cnt = 0;
	while (envp[++i])
		cnt++;
	return (cnt);
}

static void	init_envp(int argc, char *argv[], char *envp[], char **env)
{
	int	i;

	(void)argc;
	(void)argv;
	env = (char **)ft_calloc(sizeof(char *), (envp_len(envp) + 1));
	if (!env)
		exit_shell();
	i = -1;
	while (envp[++i])
	{
		env[i] = ft_strdup(envp[i]);
		// if (!env[i])
		// 	exit_shell();
	}
}

int	main(int argc, char *argv[], char *envp[])
{
	char	**env;

	init_envp(argc, argv, envp, &env);
	printf("minishell!\n");
	exec_cmd(parse_cmd(argv[argc - 1]));
	return (0);
}
