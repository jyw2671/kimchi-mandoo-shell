/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeskim <jaeskim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 18:10:22 by jaeskim           #+#    #+#             */
/*   Updated: 2021/05/07 23:23:03 by jaeskim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	init_termcap(t_minishell *g)
{
	char	*termtype;
	int		success;

	termtype = getenv("TERM");
	if (termtype == 0)
	{
		ft_putstr_fd(TERM_ERROR, 2);
		exit_minishell(g, 1);
	}
	success = tgetent(NULL, termtype);
	if (success < 0)
	{
		ft_putstr_fd(TERM_SUCCES_ERR, 2);
		exit_minishell(g, 1);
	}
	if (success == 0)
	{
		ft_putstr_fd(TERM_NOT_DEFINE_PART1, 2);
		ft_putstr_fd(termtype, 2);
		ft_putstr_fd(TERM_NOT_DEFINE_PART2, 2);
		exit_minishell(g, 1);
	}
}

static void	init_term(t_minishell *g)
{
	if (tcgetattr(STDIN_FILENO, &g->term_ori) == -1)
	{
		ft_putstr_fd(strerror(errno), 2);
		exit_minishell(g, 1);
	}
	g->term_sh = g->term_ori;
	g->term_sh.c_lflag &= ~(ICANON | ECHO);
	g->term_sh.c_lflag |= VEOF;
	g->term_sh.c_cc[VMIN] = 1;
	g->term_sh.c_cc[VTIME] = 0;
}

static void	init_envp(t_minishell *g, char *envp[])
{
	int		i;
	char	*tmp_s;
	t_list	*tmp_l;

	i = 0;
	while (envp[i])
	{
		tmp_s = ft_strdup(envp[i]);
		tmp_l = ft_lstnew(tmp_s);
		if (tmp_s == NULL || tmp_l == NULL)
		{
			ft_putstr_fd(strerror(errno), 2);
			exit_minishell(g, 1);
		}
		if (g->env == NULL)
			g->env = tmp_l;
		else
			ft_lstlast(g->env)->next = tmp_l;
		++i;
	}
}

void	init_minishell(t_minishell *g, char *envp[])
{
	ft_memset(g, 0, sizeof(t_minishell));
	init_envp(g, envp);
	init_term(g);
	init_termcap(g);
	set_handle_signal();
}
