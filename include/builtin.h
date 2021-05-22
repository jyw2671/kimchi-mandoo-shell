/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjung <yjung@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/08 23:02:36 by jaeskim           #+#    #+#             */
/*   Updated: 2021/05/22 13:16:23 by yjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTIN_H
# define BUILTIN_H

# include "minishell.h"

int		ft_echo(t_list *args);
int		ft_cd(t_list *args);
int		ft_export(t_list *args);
int		compare(t_list *a, t_list *b);
int		ft_unset(t_list *args);
int		ft_env(t_list *args, t_check *g);
int		ft_pwd(void);
int		ft_exit(void);

#endif
