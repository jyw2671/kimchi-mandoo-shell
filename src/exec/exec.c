/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjung <yjung@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 13:45:21 by jaeskim           #+#    #+#             */
/*   Updated: 2021/05/12 15:24:26 by yjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// void	lst_free(t_d_list **lst)
// {
// 	if ((*lst)->next)
// 		lst_free(lst->next);
// 	if ((*lst)->prev)
// 		lst_free(&(lst->prev));
// 	if ((*lst)->content)
// 		free_pipe((*lst)->content);
// 	free(lst);
// }

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
		status = ft_tree_parser(ASTs->content, &g);
		if (status != 0)
			return (status);
		ASTs = ASTs->next;
		// if (g.pipe_fd)
		// 	lst_free(&g.pipe_fd);
	}
	return (status);
}
