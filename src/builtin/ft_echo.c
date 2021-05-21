/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjung <yjung@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 21:06:12 by yjung             #+#    #+#             */
<<<<<<< Updated upstream
/*   Updated: 2021/05/10 21:03:39 by yjung            ###   ########.fr       */
=======
<<<<<<< HEAD
/*   Updated: 2021/05/18 15:17:56 by yjung            ###   ########.fr       */
=======
/*   Updated: 2021/05/10 21:03:39 by yjung            ###   ########.fr       */
>>>>>>> origin/master
>>>>>>> Stashed changes
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

<<<<<<< Updated upstream
int	ft_echo(t_check *g, t_list *args)
=======
<<<<<<< HEAD
int	ft_echo(t_list *args)
>>>>>>> Stashed changes
{
	int	status;

	(void)g;
	status = 0;
	// -n 옵션은 라인 끝에서 new line 을 제외시킨다
	if (ft_strcmp(args->content, "-n") == 0)
		status = 1;
<<<<<<< Updated upstream
	args = args->next;
=======
		args = args->next;
	}
=======
int	ft_echo(t_check *g, t_list *args)
{
	int	status;

	(void)g;
	status = 0;
	// -n 옵션은 라인 끝에서 new line 을 제외시킨다
	if (ft_strcmp(args->content, "-n") == 0)
		status = 1;
	args = args->next;
>>>>>>> origin/master
>>>>>>> Stashed changes
	while (args)
	{
		ft_putstr_fd(args->content, STDOUT_FILENO);
		args = args->next;
		if (args)
			ft_putstr_fd(" ", STDOUT_FILENO);
	}
	if (status != 1)
		ft_putstr_fd("\n", STDOUT_FILENO);
	return (0);
}
<<<<<<< Updated upstream

// envp 치환해주는 함수
=======
<<<<<<< HEAD
=======

// envp 치환해주는 함수
>>>>>>> origin/master
>>>>>>> Stashed changes
