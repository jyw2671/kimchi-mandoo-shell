/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjung <yjung@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 21:07:43 by yjung             #+#    #+#             */
/*   Updated: 2021/05/22 15:23:09 by yjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	print_error(char *env)
{
	ft_putstr_fd("minishell: unset: `", STDERR_FILENO);
	ft_putstr_fd("'", STDERR_FILENO);
	ft_putstr_fd(env, STDERR_FILENO);
	ft_putstr_fd("': not a valid identifier\n", STDERR_FILENO);
}

int	ft_unset(t_list *args)
{
	char	*ptr;
	t_list	*cmp;
	int		status;

	status = 0;
	cmp = args;
	while (cmp)
	{
		ptr = ft_strchr(cmp->content, '=');
		if (ptr)
		{
			print_error(cmp->content);
			status = 1;
		}
		else
			remove_envp(cmp->content);
		cmp = cmp->next;
	}
	return (status);
}
