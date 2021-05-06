/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strappendc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeskim <jaeskim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 18:48:08 by jaeskim           #+#    #+#             */
/*   Updated: 2021/04/29 18:48:52 by jaeskim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strappendc(char *str, char c)
{
	int		len;
	char	*result;

	len = ft_strlen(str);
	if (!ft_malloc((void **)&result, sizeof(char *) * (len + 2)))
	{
		free(str);
		return (0);
	}
	ft_memmove(result, str, sizeof(char) * len);
	result[len] = c;
	free(str);
	return (result);
}
