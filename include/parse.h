/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeskim <jaeskim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 13:41:05 by jaeskim           #+#    #+#             */
/*   Updated: 2021/04/16 21:39:58 by jaeskim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H

# include "minishell.h"

t_list	*parse_line(char *line);
char	*parse_cmd(char *cmd, char **envp);
char	*parse_arg(char *arg, char **envp);

#endif
