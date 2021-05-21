/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjung <yjung@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 19:40:29 by yjung             #+#    #+#             */
/*   Updated: 2021/05/21 13:12:01 by yjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "parse_util.h"

t_minishell	g_sh;

static void	minishell(void)
{
	t_list	*tmp;
	t_list	*ASTs;

	print_PS1();
	get_line();
	if (g_sh.line == NULL)
		return ;
	ASTs = parse_line(g_sh.line);
	if (ASTs < (t_list *)PARSE_ERROR_COUNT)
		print_parse_err(ASTs);
	else
	{
		tmp = ASTs;
		while (tmp)
		{
			print_AST(tmp->content, 0);
			tmp = tmp->next;
		}
		exec_cmd(ASTs);
		ft_lstclear(&ASTs, free_AST);
	}
}

int	main(int argc, char *argv[], char *envp[])
{
	(void)argc;
	(void)argv;
	init_minishell(envp);
	while (1)
		minishell();
	return (0);
}
