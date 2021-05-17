/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   envp.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjung <yjung@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/09 12:23:37 by jaeskim           #+#    #+#             */
/*   Updated: 2021/05/17 21:19:52 by yjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENVP_H
# define ENVP_H

# include "minishell.h"

t_list	*get_envp(char *name, t_list *envp);
char	*get_envp_value(char *name);
int		set_envp(char *env);
int		remove_envp(char *value);

#endif
