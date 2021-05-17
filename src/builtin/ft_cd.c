/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjung <yjung@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 21:13:05 by yjung             #+#    #+#             */
/*   Updated: 2021/05/17 18:17:06 by yjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_cd(t_check *g, t_list *args)
{
	int		status;
	char	*path;

	(void)g;
	status = 0;
	if (!args)
		return (status);
	path = strdup(args->content);
	if (path == NULL)
		return (MALLOC_FAIL);
	status = chdir(path);
	if (status < 0)
	{
		ft_error_print("cd", strerror(errno));
		free(path);
		return (1);
	}
	free(path);
	return (status);
}
