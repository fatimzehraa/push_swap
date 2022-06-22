/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fael-bou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 12:02:22 by fael-bou          #+#    #+#             */
/*   Updated: 2022/06/22 18:54:12 by fatimzehra       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "list.h"
#include "push_swap.h"
#include <stdio.h>
#include <stdlib.h>


void	print_tab(char ** tab)
{
	while (*tab)
	{
		ft_putstr(*tab);
		ft_putstr("\n");
		tab++;
	}
}


int main (int argc, char *argv[])
{
	t_ctx ctx;
	int i;

	init_ctx(&ctx);
	if (argc == 1)
		return (0);
	else if (argc == 2 && ft_strchr(argv[1], ' '))
		ctx.splited_nb = ft_split(argv[1], ' ');
	else
		ctx.splited_nb = ft_duplicate(argc, argv);
	if (!is_all_number(ctx.splited_nb) || is_duplicated_number(ctx.splited_nb))
		return (free_ctx(&ctx, 1));
	// Logique
	i = 0;
	while (ctx.splited_nb[i])
	{
		ft_lstadd_back(&(ctx.stack_a), ft_lstnew(ft_atoi(ctx.splited_nb[i]), i));
		i++;
	}
	position(ctx.stack_a);


//	t_list *curr = ctx.stack_a;
//	while (curr)
//	{
//		printf("stack_a->content : %d stack_a->position : %d stack_a->index : %d \n", curr->content, curr->p, curr->i);
//		curr = curr->next;
//	}
//	printf("\n");
	
	sort(ft_lstsize(ctx.stack_a), &(ctx.stack_a), &(ctx.stack_b));
	if (is_sorted(ctx.stack_a))
		return (free_ctx(&ctx, 0));
	else 
		return (free_ctx(&ctx, 1));
}
