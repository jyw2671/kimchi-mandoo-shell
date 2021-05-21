/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjung <yjung@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
<<<<<<< HEAD:src/cursor/clear_line.c
/*   Created: 2021/05/16 16:26:23 by jaeskim           #+#    #+#             */
/*   Updated: 2021/05/16 16:29:08 by jaeskim          ###   ########.fr       */
=======
/*   Created: 2021/04/14 13:45:21 by jaeskim           #+#    #+#             */
/*   Updated: 2021/05/09 15:58:23 by yjung            ###   ########.fr       */
>>>>>>> origin/master:src/exec/exec.c
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

<<<<<<< HEAD:src/cursor/clear_line.c
void	clear_line(void)
{
	tputs(tgetstr("cl", NULL), 1, putchar_tc);
	print_PS1();
	ft_putstr_fd(g_sh.line, 1);
=======
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
	}
	return (status);
>>>>>>> origin/master:src/exec/exec.c
}
