/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjung <yjung@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 13:45:21 by jaeskim           #+#    #+#             */
/*   Updated: 2021/05/17 18:01:17 by yjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	exec_cmd(t_list *ASTs)
{
	int		status;
	t_check	g;

	status = 0;
	while (ASTs)
	{
		ft_memset(&g, 0, sizeof(t_check));
		g.save_in = -1;
		g.save_out = -1;
		status = exec_tree_parser(ASTs->content, &g);
		ASTs = ASTs->next;
	}
	return (status);
}
