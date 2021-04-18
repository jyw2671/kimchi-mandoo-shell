/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_to_array.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeskim <jaeskim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 15:14:51 by jaeskim           #+#    #+#             */
/*   Updated: 2021/04/18 15:41:28 by jaeskim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	**ft_lst_to_array(t_list **lst)
{
	int		i;
	t_list	*tmp;
	void	**result;

	result = malloc(sizeof(void *) * (ft_lstsize(*lst) + 1));
	if (result == NULL)
		return (0);
	i = 0;
	while (*lst)
	{
		result[i++] = (*lst)->content;
		tmp = *lst;
		*lst = (*lst)->next;
		free(*lst);
	}
	result[i] = 0;
	return (result);
}
