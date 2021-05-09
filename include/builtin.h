/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeskim <jaeskim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/08 23:02:36 by jaeskim           #+#    #+#             */
/*   Updated: 2021/05/08 23:18:09 by jaeskim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTIN_H
# define BUILTIN_H

# include "minishell.h"

int		ft_echo(t_check *g, t_list *args, t_list **envp);
int		ft_cd(t_check *g, t_list *args, t_list **envp);
int		ft_export(t_list *args, t_list **envp);
int		ft_unset(t_check *g, t_list *args, t_list **envp);
int		ft_env(t_list **envp);
int		ft_pwd(t_check *g);

#endif
