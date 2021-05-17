/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_d_lstclear.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjung <yjung@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 12:33:26 by jaeskim           #+#    #+#             */
/*   Updated: 2021/05/12 13:37:41 by yjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
void	ft_d_lstclear(t_d_list **lst, void (*del)(void*))
{
	t_d_list	*tmp;

	while (*lst)
	{
		tmp = (*lst)->next;
		if (del)
			del((*lst)->content);
		free(*lst);
		*lst = tmp;
	}
	*lst = 0;
}
