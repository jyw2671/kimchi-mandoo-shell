/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjung <yjung@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 17:46:29 by yjung             #+#    #+#             */
/*   Updated: 2021/05/21 22:35:55 by yjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_error_print(char *msg, char *args, char *val)
{
	ft_putstr_fd("minishell: ", STDERR_FILENO);
	ft_putstr_fd(msg, STDERR_FILENO);
	if (args)
	{
		ft_putstr_fd(": ", STDERR_FILENO);
		ft_putstr_fd(args, STDERR_FILENO);
	}
	if (val)
	{
		ft_putstr_fd(": ", STDERR_FILENO);
		ft_putstr_fd(val, STDERR_FILENO);
	}
	ft_putchar_fd('\n', 1);
}
