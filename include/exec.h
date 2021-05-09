/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeskim <jaeskim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 13:41:05 by jaeskim           #+#    #+#             */
/*   Updated: 2021/05/09 00:15:57 by jaeskim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXEC_H
# define EXEC_H

# include "minishell.h"
# include <fcntl.h>
# include <errno.h>
# include <string.h>

// # define SIDE_OUT	0;
// # define SIDE_IN	1;

# define EXPORT	1
# define ENV	2

typedef struct s_pi_fd
{
	int		pi_in;
	int		pi_out;
}	t_pi_fd;

typedef struct s_check
{
	int		fd_in;
	int		fd_out;
	int		save_in;
	int		save_out;
	int		pipe_cnt;
	t_list	*pipe_fd;
}	t_check;

int		exec_cmd(t_list *ASTs, t_list **envp);
// ft_cmd.c
int		ft_cmd_exec(t_cmd *cmds, t_list **envp, t_check *g);
int		ft_cmd_pipe_set(t_cmd *cmds, t_list **envp, t_check *g);
// redirection.c
int		ft_redir_exec(t_redirect *redir, t_list **envp, t_check *g);
int		ft_redir_parser(t_check *g);
int		ft_redir_connect(t_check *g);
int		ft_redir_close(t_check *g);
// pipe.c
int		ft_pipe_exec(t_pipe	*pipes, t_list **envp, t_check *g);
void	ft_pipe_connect(int *status, t_check *g);
// exec_util.c
int		ft_ctr_op_exec(t_ctr_op *ctr, t_list **envp, t_check *g);
int		ft_tree_parser(t_AST *cmds, t_list **envp, t_check *g);
int		ft_cmd_fork_set(t_cmd *cmds, t_list **envp, t_check *g);
void	ft_print_envp(t_list **envp, int check);
// ft_error.c
void	ft_error_print(char *msg, char *val);

#endif
