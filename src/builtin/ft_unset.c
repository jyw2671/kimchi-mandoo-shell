/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjung <yjung@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 21:07:43 by yjung             #+#    #+#             */
/*   Updated: 2021/05/16 21:36:48 by yjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	print_error(char *env)
{
	ft_putstr_fd("minishell: unset: `", 2);
	ft_putstr_fd("'", 2);
	ft_putstr_fd(env, 2);
	ft_putstr_fd("': not a valid identifier\n", 2);
}

int	ft_unset(t_list *args)
{
	char	*ptr;

	while (args)
	{
		ptr = ft_strchr(args->content, '=');
		if (ptr)
			print_error(args->content);
		else
			remove_envp(args->content);
		args = args->next;
	}
	return (SUCCESS);
}
