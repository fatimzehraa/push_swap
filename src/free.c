/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fael-bou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 12:26:00 by fael-bou          #+#    #+#             */
/*   Updated: 2022/06/26 12:26:32 by fael-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_tab(char **splited)
{
	int	i;

	i = 0;
	while (splited[i])
	{
		free(splited[i]);
		i++;
	}
	free(splited);
}

void	init_ctx(t_ctx *ctx)
{
	ctx->stack_a = NULL;
	ctx->stack_b = NULL;
	ctx->splited = NULL;
}

int	free_ctx(t_ctx *ctx, int is_error)
{
	if (ctx->splited != NULL)
		free_tab(ctx->splited);
	if (ctx->stack_a != NULL)
		ft_lstclear(&(ctx->stack_a));
	if (ctx->stack_b != NULL)
		ft_lstclear(&(ctx->stack_b));
	if (is_error)
		ft_putstr("Error\n");
	return (0);
}
