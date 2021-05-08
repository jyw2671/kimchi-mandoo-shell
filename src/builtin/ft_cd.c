/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjung <yjung@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 21:13:05 by yjung             #+#    #+#             */
/*   Updated: 2021/05/08 20:45:25 by yjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_cd(t_check *g, t_list *args, t_list **envp)
{
	int		status;
	char	*path;

	// TODO: 구현 필요
	(void)g;
	(void)args;
	(void)envp;
	status = 0;
	status = chdir(path);
	if (status < 0)
	{
		ft_error_print("cd", strerror(errno));
		return (1);
	}
	// ft_cmd_check();
	return (status);
}
