/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_util.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeskim <jaeskim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 13:41:05 by jaeskim           #+#    #+#             */
/*   Updated: 2021/04/22 03:43:52 by jaeskim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_UTIL_H
# define PARSE_UTIL_H

# include "minishell.h"

# define NO_COLOR "\e[0m"
# define TEXT_COLOR "\e[38;2;255;121;198m"
# define VALUE_COLOR "\e[38;2;189;147;249m"

# define TK_IFS		" \n\t"
# define TK_NONE	0
# define TK_QOUTE	1
# define TK_QOUTES	2
# define TK_ESCAPE	4

# define LX_NONE		0
# define LX_CMD			1
# define LX_ARG			2
# define LX_REDIRECT	4
# define LX_FILE		8
# define LX_PIPE		16
# define LX_CTR_OP		32
# define LX_SEPERATOR	64

typedef struct s_type
{
	int		type;
	char	*value;
}	t_type;

char	*get_token(char **line);
char	*get_static_token(char **line, int *status);
t_list	*lexical_analyzer(char *line);

#endif
