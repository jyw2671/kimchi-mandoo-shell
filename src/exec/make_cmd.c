/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjung <yjung@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 15:45:20 by yjung             #+#    #+#             */
/*   Updated: 2021/05/22 11:00:03 by yjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	parse_cmd_err_check(char *args, char *print_args)
{
	if ((int)args == PARSE_MALLOC)
		ft_error_print(PARSE_MALLOC_MSG, NULL, strerror(errno));
	else if ((int)args == PARSE_CMD_NONE)
	{
		if (print_args != NULL)
			ft_error_print(print_args, PARSE_CMD_NONE_MSG, NULL);
		else
			ft_error_print(PARSE_CMD_NONE_MSG, NULL, strerror(errno));
	}
	else
		return (SUCCESS);
	return (FAIL);
}

char	**make_args(char *cmd, t_list *args_lst, int *status)
{
	char	**args;
	int		cnt;

	cnt = 0;
	if (!ft_malloc((void **)&args, sizeof(char *) * (ft_lstsize(args_lst) + 2)))
	{
		*status = MALLOC_FAIL;
		return (NULL);
	}
	args[cnt++] = ft_strdup(cmd);
	while (args_lst)
	{
		args[cnt] = args_lst->content;
		if (parse_cmd_err_check(args[cnt], NULL) == -1)
		{
			*status = MALLOC_FAIL;
			free(args);
			return (NULL);
		}
		args_lst = args_lst->next;
		cnt++;
	}
	args[cnt] = NULL;
	return (args);
}

int	ft_make_cmd(char *cmd, t_list *args_lst)
{
	int		status;
	char	**args;
	char	*path;

	status = 0;
	args = make_args(cmd, args_lst, &status);
	if (status == MALLOC_FAIL)
		return (FAIL);
	path = parse_cmd(args[0]);
	if (parse_cmd_err_check(path, args[0]) == -1)
		return (FAIL);
	status = execve(path, args, (char **)ft_lst_to_array(g_sh.envp));
	free(args);
	free(path);
	return (status);
}
