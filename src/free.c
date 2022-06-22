/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fatimzehra </var/spool/mail/fatimzehra>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 09:14:38 by fatimzehra        #+#    #+#             */
/*   Updated: 2022/06/21 09:15:22 by fatimzehra       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_tab(char **splitted_nb)
{
	int	i;

	i = 0;
	while (splitted_nb[i])
	{
		free(splitted_nb[i]);
		i++;
	}
	free(splitted_nb);
}

void	init_ctx(t_ctx *ctx)
{
	ctx->stack_a = NULL;
	ctx->stack_b = NULL;
	ctx->splited_nb = NULL;
}

int	free_ctx(t_ctx *ctx, int is_error)
{
	if (ctx->splited_nb != NULL)
		free_tab(ctx->splited_nb);
	if (ctx->stack_a != NULL)
		ft_lstclear(&(ctx->stack_a));
	if (ctx->stack_b != NULL)
		ft_lstclear(&(ctx->stack_b));
	if (is_error)
		ft_putstr("Error\n");
	return (is_error);
}
