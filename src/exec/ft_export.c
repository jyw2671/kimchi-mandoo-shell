/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjung <yjung@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 21:11:40 by yjung             #+#    #+#             */
/*   Updated: 2021/05/08 21:21:17 by yjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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

static void	ft_find_envp(char *args, t_list **envp, int *status, int *cnt)
{
	t_list	**env;
	char	*str;

	env = envp;
	ft_check_errorcase(args, status);
	if (*status == 3)
		// TODO: ft_find_envp status 3 에러 출력 수정 필요
		return ;
	while (++(*cnt) >= 0 &&*env && *status == 0)
	{
		if (ft_strncmp(args, (*env)->content, ft_strlen(args)) == 0)
		{
			str = ft_strappendc(args, '=');
			if ((ft_strlen(str) - 1) == ft_strlen((*env)->content))
				*status = 1;
			else if (ft_strncmp(str, (*env)->content, ft_strlen(str)) == 0)
				*status = 2;
			free(str);
			if (*status == 1 || *status == 2)
				break ;
		}
		*env = (*env)->next;
	}
}

t_list	*ft_lstcnt(t_list *lst, int cnt)
{
	if (!lst)
		return (0);
	while (cnt > 0)
	{
		lst = lst->next;
		cnt--;
	}
	return (lst);
}

static void	ft_envp_store(char *args, t_list **envp, int *status, int cnt)
// double quotes 제거 후 저장해주는 logic 추가
{
	// char	*ptr;

	// while (ft_strchr(args, '\"') == 0)
	// {
	// 	ptr = ft_strchr(args, '\"');
	// 	ft_strjoin(ft_strndup(args, (ft_strlen(args) - ft_strlen(ptr))), \
	// 		ft_strndup(ptr + 1, ft_strlen(ptr + 1)));
	// }
	if (!args)
		return ;
	if (*status == 0)
		ft_lstlast(*envp)->next = ft_lstnew(args);
	if (*status == 0 || *status == 1)
		return ;
	if (cnt == 0)
		(*envp)->content = args;
	else
		ft_lstcnt((*envp), cnt)->content = args;
}

int		ft_export(t_list *args, t_list **envp)
{
	char	*str;
	int		status;
	int		cnt;

	if (!args)
		ft_print_envp(envp, EXPORT);
	while (args)
	{
		cnt = -1;
		if (ft_strchr(args->content, '=') != 0)
			ft_find_envp(args->content, envp, &status, &cnt);
		else
		{
			str = ft_strndup(ft_strchr(args->content, '=') + 1, \
				ft_strlen(ft_strchr(args->content, '=') + 1));
			ft_find_envp(str, envp, &status, &cnt);
			free(str);
		}
		if (status == 0 || status == 1 || status == 2)
			ft_envp_store(args->content, envp, &status, cnt);
		else
			ft_error_print("export", strerror(errno));
		args = args->next;
	}
	return (status);
}
