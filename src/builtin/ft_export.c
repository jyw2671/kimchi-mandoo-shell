/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
<<<<<<< Updated upstream
/*   By: yjung <yjung@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 21:11:40 by yjung             #+#    #+#             */
/*   Updated: 2021/05/10 21:03:21 by yjung            ###   ########.fr       */
=======
<<<<<<< HEAD
/*   By: jaeskim <jaeskim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 21:11:40 by yjung             #+#    #+#             */
/*   Updated: 2021/05/21 20:00:09 by jaeskim          ###   ########.fr       */
=======
/*   By: yjung <yjung@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 21:11:40 by yjung             #+#    #+#             */
/*   Updated: 2021/05/10 21:03:21 by yjung            ###   ########.fr       */
>>>>>>> origin/master
>>>>>>> Stashed changes
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

<<<<<<< Updated upstream
static void	ft_check_errorcase(char *args, int *status)
=======
<<<<<<< HEAD
static void	print_error(char *env)
>>>>>>> Stashed changes
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

static void	ft_find_envp(char *args, int *status, int *cnt)
{
	t_list	*env;
	char	*str;

	env = g_sh.envp;
	ft_check_errorcase(args, status);
	if (*status == 3)
		// TODO: ft_find_envp status 3 에러 출력 수정 필요
		return ;
	while (++(*cnt) >= 0 &&env && *status == 0)
	{
		if (ft_strncmp(args, env->content, ft_strlen(args)) == 0)
		{
			str = ft_strappendc(args, '=');
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
}

static void	ft_envp_store(char *args, int *status, int cnt)
{
	t_list	*curr;

	if (g_sh.envp == NULL)
	{
		// TODO: malloc 가드
		g_sh.envp = ft_lstnew(args);
		return ;
	}
	if (*status == 0)
		// TODO: malloc 가드
		ft_lstlast(g_sh.envp)->next = ft_lstnew(args);
	if (*status == 0 || *status == 1)
		return ;
	curr = g_sh.envp;
	while (cnt--)
		curr = curr->next;
	curr->content = args;
}

int		ft_export(t_list *args)
{
	char	*str;
	int		status;
	int		cnt;

	if (!args)
		ft_print_envp(EXPORT);
	while (args)
	{
		cnt = -1;
		str = ft_strchr(args->content, '=');
		if (str != 0)
			ft_find_envp(args->content, &status, &cnt);
		else
		{
			// TODO: malloc 가드
			str = ft_strndup(args->content, (char *)args->content - str);
			ft_find_envp(str, &status, &cnt);
			free(str);
		}
		if (status == 0 || status == 1 || status == 2)
			ft_envp_store(args->content, &status, cnt);
		else
			ft_error_print("export", strerror(errno));
		args = args->next;
	}
<<<<<<< Updated upstream
	return (status);
=======
	return (SUCCESS);
=======
static void	ft_check_errorcase(char *args, int *status)
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

static void	ft_find_envp(char *args, int *status, int *cnt)
{
	t_list	*env;
	char	*str;

	env = g_sh.envp;
	ft_check_errorcase(args, status);
	if (*status == 3)
		// TODO: ft_find_envp status 3 에러 출력 수정 필요
		return ;
	while (++(*cnt) >= 0 &&env && *status == 0)
	{
		if (ft_strncmp(args, env->content, ft_strlen(args)) == 0)
		{
			str = ft_strappendc(args, '=');
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
}

static void	ft_envp_store(char *args, int *status, int cnt)
{
	t_list	*curr;

	if (g_sh.envp == NULL)
	{
		// TODO: malloc 가드
		g_sh.envp = ft_lstnew(args);
		return ;
	}
	if (*status == 0)
		// TODO: malloc 가드
		ft_lstlast(g_sh.envp)->next = ft_lstnew(args);
	if (*status == 0 || *status == 1)
		return ;
	curr = g_sh.envp;
	while (cnt--)
		curr = curr->next;
	curr->content = args;
}

int		ft_export(t_list *args)
{
	char	*str;
	int		status;
	int		cnt;

	if (!args)
		ft_print_envp(EXPORT);
	while (args)
	{
		cnt = -1;
		str = ft_strchr(args->content, '=');
		if (str != 0)
			ft_find_envp(args->content, &status, &cnt);
		else
		{
			// TODO: malloc 가드
			str = ft_strndup(args->content, (char *)args->content - str);
			ft_find_envp(str, &status, &cnt);
			free(str);
		}
		if (status == 0 || status == 1 || status == 2)
			ft_envp_store(args->content, &status, cnt);
		else
			ft_error_print("export", strerror(errno));
		args = args->next;
	}
	return (status);
>>>>>>> origin/master
>>>>>>> Stashed changes
}
