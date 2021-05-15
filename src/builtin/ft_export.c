/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjung <yjung@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 21:11:40 by yjung             #+#    #+#             */
/*   Updated: 2021/05/15 22:33:52 by yjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	check_errorcase(char *args, int *status)
{
	int	cnt_w;

	cnt_w = 0;
	while (args[cnt_w])
	{
		if (cnt_w == 0 && ft_isdigit(args[cnt_w]))
			*status = 3;
		else if (!(ft_isalnum(args[cnt_w]) != 0 || args[cnt_w] == '_'))
			*status = 3;
		if (*status == 3)
			break ;
		cnt_w++;
	}
}

static int	find_envp(char *args, int *status, int *cnt)
{
	t_list	*env;
	char	*str;

	env = g_sh.envp;
	check_errorcase(args, status);
	if (*status == 3)
		return (0);
	while (++(*cnt) >= 0 &&env && *status == 0)
	{
		if (ft_strncmp(args, env->content, ft_strlen(args)) == 0)
		{
			str = ft_strappendc(args, '=');
			if (str == NULL)
				return (MALLOC_FAIL);
			if ((ft_strlen(str) - 1) == ft_strlen(env->content))
				*status = 1;
			else if (ft_strncmp(str, env->content, ft_strlen(str)) == 0)
				*status = 2;
			free(str);
			if (*status == 1 || *status == 2)
				break ;
		}
		env = env->next;
	}
	return (0);
}

static int	envp_store(char *args, int *status, int cnt)
{
	t_list	*curr;

	if (g_sh.envp == NULL)
	{
		g_sh.envp = ft_lstnew(args);
		if (g_sh.envp == NULL)
			return (MALLOC_FAIL);
		return (0);
	}
	if (*status == 0)
	{
		ft_lstlast(g_sh.envp)->next = ft_lstnew(args);
		if (ft_lstlast(g_sh.envp)->next == NULL)
			return (MALLOC_FAIL);
	}
	if (*status == 0 || *status == 1)
		return (0);
	curr = g_sh.envp;
	while (cnt--)
		curr = curr->next;
	curr->content = args;
	return (0);
}

static int	equal_check(char *args, int *status, int *cnt)
{
	char	*str;

	str = ft_strchr(args, '=');
	if (str != 0)
	{
		if (find_envp(args, status, cnt) == MALLOC_FAIL)
			return (MALLOC_FAIL);
	}
	else
	{
		str = ft_strndup(args, args - str);
		if (str == NULL)
			return (MALLOC_FAIL);
		if (find_envp(str, status, cnt) == MALLOC_FAIL)
			return (MALLOC_FAIL);
		free(str);
	}
	return (0);
}

int	ft_export(t_check *g, t_list *args)
{
	int		status;
	int		cnt;

	// TODO: envp sort 필요
	status = 0;
	if (ft_redir_connect(g, 1) == DUP_ERROR)
		return (DUP_ERROR);
	if (!args)
		print_envp(1);
	while (args)
	{
		cnt = -1;
		if (equal_check(args->content, &status, &cnt) == MALLOC_FAIL)
			return (MALLOC_FAIL);
		if (status == 0 || status == 1 || status == 2)
		{
			if (envp_store(args->content, &status, cnt) == MALLOC_FAIL)
				return (MALLOC_FAIL);
		}
		args = args->next;
	}
	if (ft_redir_close(g) < 0)
		return (DUP_ERROR);
	return (status);
}
