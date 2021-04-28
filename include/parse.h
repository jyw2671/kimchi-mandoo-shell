/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeskim <jaeskim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 13:41:05 by jaeskim           #+#    #+#             */
/*   Updated: 2021/04/28 16:18:47 by jaeskim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H

# include "minishell.h"

# define PARSE_ERROR_COUNT	3
# define PARSE_MALLOC		0
# define PARSE_MALLOC_MSG	"Memory allocation failure\n"
# define PARSE_INVAILD		1
# define PARSE_INVAILD_MSG	"Invaild command\n"
# define PARSE_UNEXPECT		2
# define PARSE_UNEXPECT_MSG	"syntax error near unexpected token\n"

t_list	*parse_line(char *line);
char	*parse_cmd(char *cmd, char **envp);
char	*parse_arg(char *arg, char **envp);

#endif
