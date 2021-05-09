/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjung <yjung@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 21:06:12 by yjung             #+#    #+#             */
/*   Updated: 2021/05/09 15:59:29 by yjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_echo(t_check *g, t_list *args)
{
	int	status;

	(void)g;
	status = 0;
	// -n 옵션은 라인 끝에서 new line 을 제외시킨다
	if (ft_strcmp(args->content, "-n") == 0)
		status = 1;
	args = args->next;
	while (args)
	{
		write(1, args->content, ft_strlen(args->content));
		args = args->next;
		if (args)
			write(1, " ", 1);
	}
	if (status != 1)
		write(1, "\n", 1);
	return (0);
}

// envp 치환해주는 함수
