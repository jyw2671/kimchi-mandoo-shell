/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_util.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeskim <jaeskim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 18:59:24 by jaeskim           #+#    #+#             */
/*   Updated: 2021/05/15 22:27:07 by jaeskim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_arrow_up_down(int keycode)
{
	if (keycode == ARROW_UP)
		return (1);
	if (keycode == ARROW_DOWN)
		return (1);
	return (0);
}

int	is_arrow_left_right(int keycode)
{
	if (keycode == ARROW_LEFT)
		return (1);
	if (keycode == ARROW_RIGHT)
		return (1);
	if (keycode == CTRL_LEFT)
		return (1);
	if (keycode == CTRL_RIGHT)
		return (1);
	return (0);
}

int	is_delete(int keycode)
{
	if (keycode == DELETE)
		return (1);
	return (0);
}

int	is_eof(int keycode)
{
	if (keycode == EOF_CHAR)
		return (1);
	return (0);
}

int	is_special_key(int keycode)
{
	if (is_arrow_left_right(keycode) || \
		is_arrow_up_down(keycode) || \
		is_delete(keycode) || \
		is_eof(keycode) || \
		keycode == KEY_HOME || \
		keycode == KEY_END || \
		keycode == '\t')
		return (1);
	return (0);
}
