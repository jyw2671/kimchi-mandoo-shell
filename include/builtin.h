/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjung <yjung@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/08 23:02:36 by jaeskim           #+#    #+#             */
/*   Updated: 2021/05/16 20:52:09 by yjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTIN_H
# define BUILTIN_H

# include "minishell.h"

int		ft_echo(t_check *g, t_list *args);
int		ft_cd(t_check *g, t_list *args);
int		ft_export(t_list *args);
int		ft_unset(t_list *args);
int		ft_env(t_list *args);
int		ft_pwd(t_check *g);
int		ft_exit(void);

#endif
