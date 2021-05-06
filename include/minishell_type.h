/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_type.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeskim <jaeskim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 12:34:36 by jaeskim           #+#    #+#             */
/*   Updated: 2021/05/06 16:56:22 by jaeskim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_TYPE_H
# define MINISHELL_TYPE_H

typedef struct s_history
{
	char				*cmd;
	char				*edit_cmd;
	struct s_history	*next;
	struct s_history	*prev;
}	t_history;

typedef struct s_minishell
{
	t_history		*cmd;
	t_history		*history;
	int				cmd_i;
	int				cmd_s;
	t_list			*env;
	struct termios	term_sh;
	struct termios	term_ori;
}	t_minishell;

/*
** t_AST type define
**
** FT_CMD -> t_cmd
** FT_PIPE -> t_pipe
** FT_REDIRECT -> t_redirect
** FT_CTR_OP -> t_ctr_op
*/

# define FT_CMD			1
# define FT_PIPE		2
# define FT_REDIRECT	3
# define FT_CTR_OP		4

typedef struct s_AST
{
	int		type;
	void	*data;
}	t_AST;

typedef struct s_cmd
{
	char	*cmd;
	t_list	*args;
}	t_cmd;

typedef struct s_pipe
{
	t_AST	*left;
	t_AST	*right;
}	t_pipe;

/*
** t_redirect type define
**
** FT_FD_IN -> `<`
** FT_FD_OUT -> `>`
** FT_FD_APPEND -> `>>`
** FT_FD_HEREDOC -> `<<`
*/

# define FT_FD_IN		1
# define FT_FD_OUT		2
# define FT_FD_APPEND	3
# define FT_FD_HEREDOC	4

typedef struct s_redirect
{
	int		type;
	t_AST	*AST;
	char	*file;
}	t_redirect;

/*
** t_cond type define
**
** FT_OR -> `||`
** FT_AND -> `&&`
*/

# define FT_OR	1
# define FT_AND	2

typedef struct s_ctr_op
{
	int		type;
	t_AST	*left;
	t_AST	*right;
}	t_ctr_op;

#endif
