/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeskim <jaeskim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 18:13:06 by jaeskim           #+#    #+#             */
/*   Updated: 2021/05/07 23:34:17 by jaeskim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTIL_H
# define UTIL_H

# include "minishell.h"

int		getch(t_minishell *g);
void	print_PS1(void);
char	*get_line(t_minishell *g);
char	*handle_key_input(t_minishell *g, int keycode, char *line);
char	*handle_history(t_minishell *g, char *line, int keycode);

int		is_special_key(int keycode);
int		is_delete(int keycode);
int		is_arrow_left_right(int keycode);
int		is_arrow_up_down(int keycode);
int		is_eof(int keycode);

void	set_handle_signal(void);
void	un_set_handle_signal(void);

#endif
