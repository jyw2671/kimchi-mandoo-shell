/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjung <yjung@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 21:11:40 by yjung             #+#    #+#             */
/*   Updated: 2021/05/16 18:22:26 by yjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	print_error(char *env)
{
	ft_putstr_fd("minishell: export: `", 2);
	ft_putstr_fd("'", 2);
	ft_putstr_fd(env, 2);
	ft_putstr_fd("': not a valid identifier\n", 2);
}

static int	check_envp_name(char *arg)
{
	char	*ptr;
	int		len;

	ptr = ft_strchr(arg, '=');
	if (ptr)
		len = ptr - arg;
	else
		len = ft_strlen(arg);
	while (--len >= 0)
	{
		if ((len == 0 && !(ft_isalpha(arg[len]) || arg[len] == '_')) \
			|| !(ft_isalnum(arg[len]) || arg[len] == '_'))
			return (WRONG_NAME);
	}
	return (0);
}

int	ft_export(t_list *args)
{
	char	*value;

	if (!args)
		print_envp(1);
	while (args)
	{
		value = ft_strdup(args->content);
		if (value == NULL)
			return (MALLOC_FAIL);
		if (check_envp_name(value) == WRONG_NAME)
		{
			print_error(value);
			ft_free(value);
		}
		else if (set_envp(value) == MALLOC_FAIL)
			return (MALLOC_FAIL);
		args = args->next;
	}
	return (0);
}
