/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeskim <jaeskim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/09 12:22:59 by jaeskim           #+#    #+#             */
/*   Updated: 2021/05/09 15:33:56 by jaeskim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "parse_util.h"

// TODO: parse_cmd $PATH check, `~` check needs.
char	*parse_cmd(char *cmd)
{
	char	*nomal_cmd;

	nomal_cmd = normalize(cmd, NOMALIZE_CMD);
	if (nomal_cmd == NULL)
		return (PARSE_MALLOC);
	if (!ft_strncmp(nomal_cmd, "./", 2) || !ft_strncmp(nomal_cmd, "/", 1))
		return (nomal_cmd);
	if (!ft_strncmp(nomal_cmd, "~/", 2))
		return (nomal_cmd);
	return (nomal_cmd);
}
