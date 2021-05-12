/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjung <yjung@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 13:41:05 by jaeskim           #+#    #+#             */
/*   Updated: 2021/05/12 20:09:49 by yjung            ###   ########.fr       */
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

# define PIPE_R_ONLY	0
# define PIPE_W_ONLY	1
# define PIPE_R_W		2

typedef struct s_pi_fd
{
	int		pi_read;
	int		pi_write;
	int		check;
}	t_pi_fd;

typedef struct s_check
{
	int			fd_in;
	int			fd_out;
	int			redir_in;
	int			save_in;
	int			save_out;
	int			pipe_cnt;
	t_d_list	*pipe_fd;
}	t_check;

int		exec_cmd(t_list *ASTs);
// ft_cmd.c
int		ft_cmd_exec(t_cmd *cmds, t_check *g);
int		ft_built_cmd_set(t_cmd *cmds, t_check *g);
int		ft_cmd_set(t_cmd *cmds, t_check *g);
// redirection.c
int		ft_redir_exec(t_redirect *redir, t_check *g);
int		ft_redir_connect(t_check *g);
int		ft_redir_close(t_check *g);
void	ft_pipe_write_close(t_check *g, int check);
// pipe.c
int		ft_pipe_exec(t_pipe	*pipes, t_check *g);
void	ft_pipe_connect(int *status, t_check *g);
void	ft_pipe_close(t_check *g);
// exec_util.c
int		ft_ctr_op_exec(t_ctr_op *ctr, t_check *g);
int		ft_tree_parser(t_AST *cmds, t_check *g);
int		ft_make_cmd(char *cmd, t_list *lst);
int		parse_cmd_err_check(char *args);
// ft_error.c
void	ft_error_print(char *msg, char *val);
// free_exec.c
void	free_pipe(void *data);

#endif
