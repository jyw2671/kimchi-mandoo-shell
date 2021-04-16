/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeskim <jaeskim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 19:40:29 by yjung             #+#    #+#             */
/*   Updated: 2021/04/16 19:59:21 by jaeskim          ###   ########.fr       */
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

static char	**init_envp(int argc, char *argv[], char *envp[])
{
	int		i;
	char	**env;

	(void)argc;
	(void)argv;
	env = (char **)ft_calloc(sizeof(char *), (envp_len(envp) + 1));
	if (!env)
		exit(1);
	i = -1;
	while (envp[++i])
	{
		env[i] = ft_strdup(envp[i]);
		if (!env[i])
			exit(1);
	}
	env[i] = 0;
	return (env);
}

int	main(int argc, char *argv[], char *envp[])
{
	char	**env;
	t_list	*ASTs;

	printf("minishell!\n");
	env = init_envp(argc, argv, envp);
	ASTs = parse_line(argv[argc - 1]);
	exec_cmd(ASTs, env);
	return (0);
}
