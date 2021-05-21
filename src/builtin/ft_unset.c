/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjung <yjung@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 21:07:43 by yjung             #+#    #+#             */
<<<<<<< Updated upstream
/*   Updated: 2021/05/09 16:01:58 by yjung            ###   ########.fr       */
=======
<<<<<<< HEAD
/*   Updated: 2021/05/21 18:43:15 by yjung            ###   ########.fr       */
=======
/*   Updated: 2021/05/09 16:01:58 by yjung            ###   ########.fr       */
>>>>>>> origin/master
>>>>>>> Stashed changes
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

<<<<<<< Updated upstream
int	ft_unset(t_check *g, t_list *args)
=======
<<<<<<< HEAD
static void	print_error(char *env)
>>>>>>> Stashed changes
{
	int	status;

<<<<<<< Updated upstream
=======
	cmp = args;
	while (cmp)
	{
		ptr = ft_strchr(cmp->content, '=');
		if (ptr)
			print_error(cmp->content);
		else
			remove_envp(cmp->content);
		cmp = cmp->next;
	}
	return (SUCCESS);
=======
int	ft_unset(t_check *g, t_list *args)
{
	int	status;

>>>>>>> Stashed changes
	status = 0;
	// TODO:unset 구현 필요
	(void)g;
	(void)args;
	return (status);
<<<<<<< Updated upstream
=======
>>>>>>> origin/master
>>>>>>> Stashed changes
}
