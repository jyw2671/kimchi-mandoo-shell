/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getch.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeskim <jaeskim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 18:12:38 by jaeskim           #+#    #+#             */
/*   Updated: 2021/05/09 14:48:43 by jaeskim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	getch(void)
{
	int	c;

	c = 0;
	tcsetattr(STDIN_FILENO, TCSANOW, &g_sh.term_sh);
	read(STDIN_FILENO, &c, sizeof(c));
	tcsetattr(STDIN_FILENO, TCSANOW, &g_sh.term_ori);
	return (c);
}
