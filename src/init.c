/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeskim <jaeskim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 18:10:22 by jaeskim           #+#    #+#             */
/*   Updated: 2021/05/09 14:24:39 by jaeskim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	init_termcap(void)
{
	char	*termtype;
	int		success;

	termtype = getenv("TERM");
	if (termtype == 0)
	{
		ft_putstr_fd(TERM_ERROR, 2);
		exit_minishell(1);
	}
	success = tgetent(NULL, termtype);
	if (success < 0)
	{
		ft_putstr_fd(TERM_SUCCES_ERR, 2);
		exit_minishell(1);
	}
	if (success == 0)
	{
		ft_putstr_fd(TERM_NOT_DEFINE_PART1, 2);
		ft_putstr_fd(termtype, 2);
		ft_putstr_fd(TERM_NOT_DEFINE_PART2, 2);
		exit_minishell(1);
	}
}

static void	init_term(void)
{
	if (tcgetattr(STDIN_FILENO, &g_sh.term_ori) == -1)
	{
		ft_putstr_fd(strerror(errno), 2);
		exit_minishell(1);
	}
	g_sh.term_sh = g_sh.term_ori;
	g_sh.term_sh.c_lflag &= ~(ICANON | ECHO);
	g_sh.term_sh.c_lflag |= VEOF;
	g_sh.term_sh.c_cc[VMIN] = 1;
	g_sh.term_sh.c_cc[VTIME] = 0;
}

static void	init_envp(char *envp[])
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
			exit_minishell(1);
		}
		if (g_sh.envp == NULL)
			g_sh.envp = tmp_l;
		else
			ft_lstlast(g_sh.envp)->next = tmp_l;
		++i;
	}
}

void	init_minishell(char *envp[])
{
	init_envp(envp);
	init_term();
	init_termcap();
	set_handle_signal();
}
