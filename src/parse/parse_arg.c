<<<<<<< Updated upstream
// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   parse_arg.c                                        :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: jaeskim <jaeskim@student.42seoul.kr>       +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2021/05/07 06:51:49 by jaeskim           #+#    #+#             */
// /*   Updated: 2021/05/07 06:54:40 by jaeskim          ###   ########.fr       */
// /*                                                                            */
// /* ************************************************************************** */
=======
<<<<<<< HEAD
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeskim <jaeskim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 09:31:53 by jaeskim           #+#    #+#             */
/*   Updated: 2021/05/17 21:30:36 by jaeskim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
>>>>>>> Stashed changes

// #include "minishell.h"
// #include "parse_util.h"

// t_list	*parse_arg(char *arg, t_list *envp)
// {
// 	t_list	*result;
// 	int		flag;
// 	char	*arg;

<<<<<<< Updated upstream
=======
static int	new_arg(t_list **target, char *value)
{
	if (!ft_malloc((void **)target, sizeof(t_list)))
		return (-1);
	(*target)->content = normalize(&value, NORMALIZE_CMD);
	if ((*target)->content == NULL)
	{
		ft_free((*target));
		return (-1);
	}
	return (0);
}

t_list	*parse_arg(t_list *args)
{
	t_list	*result;
	t_list	**curr;

	curr = &result;
	while (args)
	{
		if (new_arg(curr, args->content) == -1)
			return (destrocter(result, PARSE_MALLOC));
		args = args->next;
		curr = &(*curr)->next;
	}
	return (result);
}
=======
// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   parse_arg.c                                        :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: jaeskim <jaeskim@student.42seoul.kr>       +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2021/05/07 06:51:49 by jaeskim           #+#    #+#             */
// /*   Updated: 2021/05/07 06:54:40 by jaeskim          ###   ########.fr       */
// /*                                                                            */
// /* ************************************************************************** */

// #include "minishell.h"
// #include "parse_util.h"

// t_list	*parse_arg(char *arg, t_list *envp)
// {
// 	t_list	*result;
// 	int		flag;
// 	char	*arg;

>>>>>>> Stashed changes
// 	flag = NULL;
// 	arg = NULL;
// 	while (*arg)
// 	{
// 		if
// 	}
// }
<<<<<<< Updated upstream
=======
>>>>>>> origin/master
>>>>>>> Stashed changes
