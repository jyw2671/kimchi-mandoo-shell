/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjung <yjung@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 21:16:26 by yjung             #+#    #+#             */
/*   Updated: 2021/05/08 20:53:16 by yjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_pwd(t_check *g)
{
	char	name[PATH_MAX];
	int		status;

	(void)g;
	status = 0;
	if (getcwd(name, PATH_MAX) == NULL)
	{
		ft_error_print("pwd", strerror(errno));
		return (1);
	}
	else
		ft_putendl_fd(name, STDOUT_FILENO);
	return (status);
}
