/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeskim <jaeskim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 14:26:57 by jaeskim           #+#    #+#             */
/*   Updated: 2021/05/21 17:29:36 by jaeskim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	ps2(int	out)
{
	print_PS2();
	get_line();
	if (g_sh.line)
		write(out, g_sh.line, ft_strlen(g_sh.line));
	write(out, "\n", 1);
}

int	heredoc(char *eof)
{
	int		io[2];

	if (pipe(io) < 0)
		return (-1);
	g_sh.isps2 = 1;
	ps2(io[1]);
	while (g_sh.signal != SIGINT && \
		!g_sh.eof && (ft_strcmp(g_sh.line, eof) != 0))
		ps2(io[1]);
	g_sh.isps2 = 0;
	close(io[1]);
	if (g_sh.signal == SIGINT)
	{
		close(io[0]);
		return (-1);
	}
	return (io[0]);
}
