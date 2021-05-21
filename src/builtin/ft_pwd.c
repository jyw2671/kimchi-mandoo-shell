/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjung <yjung@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 21:16:26 by yjung             #+#    #+#             */
<<<<<<< Updated upstream
/*   Updated: 2021/05/08 20:53:16 by yjung            ###   ########.fr       */
=======
<<<<<<< HEAD
/*   Updated: 2021/05/17 19:45:06 by yjung            ###   ########.fr       */
=======
/*   Updated: 2021/05/08 20:53:16 by yjung            ###   ########.fr       */
>>>>>>> origin/master
>>>>>>> Stashed changes
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

<<<<<<< Updated upstream
int	ft_pwd(t_check *g)
=======
<<<<<<< HEAD
int	ft_pwd(void)
=======
int	ft_pwd(t_check *g)
>>>>>>> origin/master
>>>>>>> Stashed changes
{
	char	name[PATH_MAX];
	int		status;

<<<<<<< Updated upstream
	(void)g;
=======
<<<<<<< HEAD
=======
	(void)g;
>>>>>>> origin/master
>>>>>>> Stashed changes
	status = 0;
	if (getcwd(name, PATH_MAX) == NULL)
	{
		ft_error_print("pwd", strerror(errno));
<<<<<<< Updated upstream
		return (1);
=======
<<<<<<< HEAD
		return (FAIL);
=======
		return (1);
>>>>>>> origin/master
>>>>>>> Stashed changes
	}
	else
		ft_putendl_fd(name, STDOUT_FILENO);
	return (status);
}
