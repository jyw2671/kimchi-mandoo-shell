/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjung <yjung@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 13:41:05 by jaeskim           #+#    #+#             */
<<<<<<< Updated upstream
/*   Updated: 2021/05/10 20:54:56 by yjung            ###   ########.fr       */
=======
<<<<<<< HEAD
/*   Updated: 2021/05/21 19:56:51 by jaeskim          ###   ########.fr       */
=======
/*   Updated: 2021/05/10 20:54:56 by yjung            ###   ########.fr       */
>>>>>>> origin/master
>>>>>>> Stashed changes
/*                                                                            */
/* ************************************************************************** */

#ifndef EXEC_H
# define EXEC_H

# include "minishell.h"
# include <fcntl.h>
# include <errno.h>
# include <string.h>

<<<<<<< Updated upstream
// # define SIDE_OUT	0;
// # define SIDE_IN	1;
=======
<<<<<<< HEAD
# define PARSE_ARG_ERR	1
>>>>>>> Stashed changes

# define EXPORT	1
# define ENV	2

typedef struct s_pi_fd
{
<<<<<<< Updated upstream
	int		pi_in;
	int		pi_out;
=======
	int		pi_read;
	int		pi_write;
	int		check;
=======
// # define SIDE_OUT	0;
// # define SIDE_IN	1;

# define EXPORT	1
# define ENV	2

typedef struct s_pi_fd
{
	int		pi_in;
	int		pi_out;
>>>>>>> origin/master
>>>>>>> Stashed changes
}	t_pi_fd;

typedef struct s_check
{
<<<<<<< Updated upstream
	int		fd_in;
	int		fd_out;
	int		save_in;
	int		save_out;
	int		pipe_cnt;
	int		pipe_check;
	int		pipe_close;
	int		fd_i;
	int		fd_o;
	t_list	*pipe_fd;
=======
<<<<<<< HEAD
	int			fd_in;
	int			fd_out;
	int			redir_in;
	int			save_in;
	int			save_out;
	int			pipe_cnt;
	t_d_list	*pipe_fd;
>>>>>>> Stashed changes
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
<<<<<<< Updated upstream
=======
void	ft_pipe_write_close(t_check *g, int check);
int		heredoc(char *eof);
=======
	int		fd_in;
	int		fd_out;
	int		save_in;
	int		save_out;
	int		pipe_cnt;
	int		pipe_check;
	int		pipe_close;
	int		fd_i;
	int		fd_o;
	t_list	*pipe_fd;
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
>>>>>>> origin/master
>>>>>>> Stashed changes
// pipe.c
int		ft_pipe_exec(t_pipe	*pipes, t_check *g);
void	ft_pipe_connect(int *status, t_check *g);
void	ft_pipe_close(t_check *g);
<<<<<<< Updated upstream
// exec_util.c
int		ft_ctr_op_exec(t_ctr_op *ctr, t_check *g);
int		ft_tree_parser(t_AST *cmds, t_check *g);
int		ft_make_cmd(char *cmd, t_list *lst);
int		parse_cmd_err_check(char *args);
// ft_error.c
void	ft_error_print(char *msg, char *val);
=======
<<<<<<< HEAD
// make_cmd.c
int		ft_make_cmd(char *cmd, t_list *args_lst);
int		parse_cmd_err_check(char *args);
// ft_error.c
void	ft_error_print(char *msg, char *val);
// free_exec.c
int		ft_free_cmd(void *target, int ret);
void	free_pipe(void *data);
void	free_g(t_check *g);
// parse_cmd.c
t_cmd	*parse_t_cmd(t_cmd *cmds, int *status);
t_list	*parse_cmd_args(t_list *args_lst);
// builtin_parser.c
int		builtin_parser(t_cmd *cmds, t_check *g);
=======
// exec_util.c
int		ft_ctr_op_exec(t_ctr_op *ctr, t_check *g);
int		ft_tree_parser(t_AST *cmds, t_check *g);
int		ft_make_cmd(char *cmd, t_list *lst);
int		parse_cmd_err_check(char *args);
// ft_error.c
void	ft_error_print(char *msg, char *val);
>>>>>>> origin/master
>>>>>>> Stashed changes

#endif
