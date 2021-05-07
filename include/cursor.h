/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cursor.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeskim <jaeskim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 15:29:48 by jaeskim           #+#    #+#             */
/*   Updated: 2021/05/06 15:18:10 by jaeskim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURSOR_H
# define CURSOR_H

# include "minishell.h"

int		putchar_tc(int tc);
void	delete_line(void);
void	delete_char(void);
void	cursor_left(void);
void	cursor_right(void);

#endif
