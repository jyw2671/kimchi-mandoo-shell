/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_AST.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeskim <jaeskim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 14:34:08 by jaeskim           #+#    #+#             */
/*   Updated: 2021/05/07 03:30:48 by jaeskim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "parse_util.h"

void	free_CMD(t_cmd *cmd)
{
	ft_free(cmd->cmd);
	ft_lstclear(&cmd->args, ft_free);
	ft_free(cmd);
}

void	free_PIPE(t_pipe *pipe)
{
	free_AST(pipe->left);
	free_AST(pipe->right);
	ft_free(pipe);
}

void	free_CTR_OP(t_ctr_op *ctr)
{
	free_AST(ctr->left);
	free_AST(ctr->right);
	ft_free(ctr);
}

void	free_REDIRECT(t_redirect *redirect)
{
	free_AST(redirect->AST);
	ft_free(redirect->file);
	ft_free(redirect);
}

void	free_AST(void *data)
{
	t_AST	*AST;

	AST = data;
	if (AST->type == FT_CMD && AST->data)
		free_CMD(AST->data);
	else if (AST->type == FT_PIPE)
		free_PIPE(AST->data);
	else if (AST->type == FT_CTR_OP)
		free_CTR_OP(AST->data);
	else if (AST->type == FT_REDIRECT)
		free_REDIRECT(AST->data);
	ft_free(AST);
}
