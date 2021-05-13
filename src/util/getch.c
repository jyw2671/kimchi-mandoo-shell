/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getch.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeskim <jaeskim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 18:12:38 by jaeskim           #+#    #+#             */
/*   Updated: 2021/05/13 13:47:47 by jaeskim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	getch(void)
{
	static int	i = 0;
	static char	c[4] = {0, 0, 0, 0};

	if (i > 0 && i < 4 && c[i])
		return (c[i++]);
	i = 0;
	ft_memset(&c, 0, sizeof(c));
	tcsetattr(STDIN_FILENO, TCSANOW, &g_sh.term_sh);
	read(STDIN_FILENO, &c, sizeof(c));
	tcsetattr(STDIN_FILENO, TCSANOW, &g_sh.term_ori);
	if (c[0] == 27)
		return (c[0] | c[1] << 8 | c[2] << 16 | c[3] << 24);
	i = 1;
	return (c[0]);
}
