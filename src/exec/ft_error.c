/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjung <yjung@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 17:46:29 by yjung             #+#    #+#             */
<<<<<<< Updated upstream
/*   Updated: 2021/05/03 15:47:47 by yjung            ###   ########.fr       */
=======
<<<<<<< HEAD
/*   Updated: 2021/05/15 19:20:36 by yjung            ###   ########.fr       */
=======
/*   Updated: 2021/05/03 15:47:47 by yjung            ###   ########.fr       */
>>>>>>> origin/master
>>>>>>> Stashed changes
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_error_print(char *msg, char *val)
{
	ft_putstr_fd("minishell: ", STDERR_FILENO);
	ft_putstr_fd(msg, STDERR_FILENO);
	if (val)
	{
		ft_putstr_fd(": ", STDERR_FILENO);
		ft_putendl_fd(val, STDERR_FILENO);
	}
	ft_putchar_fd('\n', 1);
}
