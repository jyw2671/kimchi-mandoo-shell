/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeskim <jaeskim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 13:45:21 by jaeskim           #+#    #+#             */
/*   Updated: 2021/05/08 23:23:33 by jaeskim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	exec_cmd(t_list *ASTs, t_list **envp)
{
	int		status;
	t_check	g;

	status = 0;
	while (ASTs)
	{
		ft_memset(&g, 0, sizeof(t_check));
		g.save_in = -1;
		g.save_out = -1;
		status = ft_tree_parser(ASTs->content, envp, &g);
		if (status != 0)
			return (status);
		ASTs = ASTs->next;
	}
	return (status);
}
