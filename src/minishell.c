/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeskim <jaeskim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 19:40:29 by yjung             #+#    #+#             */
/*   Updated: 2021/05/07 03:58:17 by jaeskim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	minishell(t_minishell *g)
{
	t_list	*tmp;
	t_list	*ASTs;
	char	*line;

	print_PS1();
	line = get_line(g);
	if (line == NULL)
		return ;
	ASTs = parse_line(line);
	if (ASTs < (t_list *)PARSE_ERROR_COUNT)
		print_parse_err(ASTs);
	else
	{
		while (ASTs)
		{
			print_AST(ASTs->content, 0);
			tmp = ASTs;
			ASTs = ASTs->next;
			free_AST(tmp->content);
			free(tmp);
		}
	}
}

int	main(int argc, char *argv[], char *envp[])
{
	t_minishell	g;

	(void)argc;
	(void)argv;
	init_minishell(&g, envp);
	while (1)
		minishell(&g);
	return (0);
}
