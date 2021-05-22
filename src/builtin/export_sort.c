/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjung <yjung@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 16:16:05 by yjung             #+#    #+#             */
/*   Updated: 2021/05/22 14:32:43 by yjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	compare_ascii(char c, int *flag)
{
	if ('0' <= c && c <= '9')
		*flag = 4;
	else if ('A' <= c && c <= 'Z')
		*flag = 3;
	else if (c == '_')
		*flag = 2;
	else if (c >= 'a' && c <= 'z')
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
		if (a[cnt] != b[cnt])
		{
			compare_ascii(a[cnt], &flag_a);
			compare_ascii(b[cnt], &flag_b);
			if (flag_a != flag_b)
				return (flag_a < flag_b);
			return (a[cnt] > b[cnt]);
		}
		++cnt;
	}
	return (2);
}

int	compare(t_list *a, t_list *b)
{
	void	*ptr;
	int		size[2];
	int		status;

	ptr = ft_strchr(a->content, '=');
	if (ptr)
		size[0] = ptr - a->content;
	else
		size[0] = ft_strlen(a->content);
	ptr = ft_strchr(b->content, '=');
	if (ptr)
		size[1] = ptr - b->content;
	else
		size[1] = ft_strlen(b->content);
	status = compare_cnt(a->content, b->content);
	if (status == 2)
		return (size[0] > size[1]);
	return (status);
}
