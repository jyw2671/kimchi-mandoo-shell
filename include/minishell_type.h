/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_type.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeskim <jaeskim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 12:34:36 by jaeskim           #+#    #+#             */
/*   Updated: 2021/04/16 21:40:33 by jaeskim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_TYPE_H
# define MINISHELL_TYPE_H

/*
** t_AST type define
**
** FT_CMD -> t_cmd
** FT_PIPE -> t_pipe
** FT_REDIRECT -> t_redirect
** FT_CONDITION -> t_cond
*/

# define FT_CMD			1
# define FT_PIPE		2
# define FT_REDIRECT	3
# define FT_CONDITION	4

typedef struct s_AST
{
	int		type;
	void	*data;
}	t_AST;

typedef struct s_cmd
{
	char	*cmd;
	char	**args;
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

typedef struct s_cond
{
	int		type;
	t_AST	*left;
	t_AST	*right;
}	t_cond;

#endif
