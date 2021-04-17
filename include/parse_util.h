/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_util.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeskim <jaeskim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 13:41:05 by jaeskim           #+#    #+#             */
/*   Updated: 2021/04/17 22:58:48 by jaeskim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_UTIL_H
# define PARSE_UTIL_H

# include "minishell.h"

# define NO_COLOR "\e[0m"
# define TEXT_COLOR "\e[38;2;255;121;198m"
# define VALUE_COLOR "\e[38;2;189;147;249m"

# define TK_NONE	0
# define TK_QOUTE	1
# define TK_QOUTES	2
# define TK_ESCAPE	4

/*----------------------------------------------------------------------------*/
// TODO: 추후 삭제 or 변경 필요!
void	parse_exit(char *msg);
/*----------------------------------------------------------------------------*/

char	**tokenizer(char *line);

#endif
