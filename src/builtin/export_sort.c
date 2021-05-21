/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjung <yjung@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 16:16:05 by yjung             #+#    #+#             */
/*   Updated: 2021/05/21 17:16:46 by yjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	compare_ascii(char a, int *flag)
{
	if (97 <= (int)a && (int)a <= 122)
		*flag = 4;
	else if (65 <= (int)a && (int)a <= 90)
		*flag = 3;
	else if (48 <= (int)a && (int)a <= 57)
		*flag = 2;
	else if ((int)a == 95)
		*flag = 1;
}

static int	compare_cnt(char *a, char *b)
{
	int	cnt;
	int	flag_a;
	int	flag_b;

	cnt = 0;
	while (a[cnt] && b[cnt])
	{
		flag_a = 0;
		flag_b = 0;
		if (a[cnt] == '=' || b[cnt] == '=')
			break ;
		compare_ascii(a[cnt], &flag_a);
		compare_ascii(b[cnt], &flag_b);
		if (flag_a > flag_b)
			return (0);
		if (flag_a < flag_b)
			return (1);
		if ((int)a[cnt] > (int)b[cnt])
			return (1);
		if ((int)a[cnt] < (int)b[cnt])
			return (0);
		++cnt;
	}
	return (2);
}

int	compare(t_list *a, t_list *b)
{
	int		status;

	status = compare_cnt(a->content, b->content);
	if (status == 2 && ft_strchr(a->content, '=') > ft_strchr(b->content, '='))
		return (0);
	else if (status == 2)
		return (1);
	return (status);
}
