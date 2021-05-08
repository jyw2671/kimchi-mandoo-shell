/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getch.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeskim <jaeskim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 18:12:38 by jaeskim           #+#    #+#             */
/*   Updated: 2021/05/07 23:18:41 by jaeskim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	getch(t_minishell *g)
{
	int		c;

	c = 0;
	tcsetattr(STDIN_FILENO, TCSANOW, &g->term_sh);
	read(STDIN_FILENO, &c, sizeof(c));
	tcsetattr(STDIN_FILENO, TCSANOW, &g->term_ori);
	return (c);
}
