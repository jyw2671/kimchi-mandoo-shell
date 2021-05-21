/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjung <yjung@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/08 23:02:36 by jaeskim           #+#    #+#             */
<<<<<<< Updated upstream
/*   Updated: 2021/05/09 18:38:25 by yjung            ###   ########.fr       */
=======
<<<<<<< HEAD
/*   Updated: 2021/05/21 16:17:14 by yjung            ###   ########.fr       */
=======
/*   Updated: 2021/05/09 18:38:25 by yjung            ###   ########.fr       */
>>>>>>> origin/master
>>>>>>> Stashed changes
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTIN_H
# define BUILTIN_H

# include "minishell.h"

<<<<<<< Updated upstream
int		ft_echo(t_check *g, t_list *args);
int		ft_cd(t_check *g, t_list *args);
int		ft_export(t_list *args);
=======
<<<<<<< HEAD
int		ft_echo(t_list *args);
int		ft_cd(t_list *args);
int		ft_export(t_list *args);
int		compare(t_list *a, t_list *b);
int		ft_unset(t_list *args);
int		ft_env(t_list *args);
int		ft_pwd(void);
int		ft_exit(void);
=======
int		ft_echo(t_check *g, t_list *args);
int		ft_cd(t_check *g, t_list *args);
int		ft_export(t_list *args);
>>>>>>> Stashed changes
int		ft_unset(t_check *g, t_list *args);
int		ft_env(void);
void	ft_print_envp(int check);
int		ft_pwd(t_check *g);
<<<<<<< Updated upstream
=======
>>>>>>> origin/master
>>>>>>> Stashed changes

#endif
