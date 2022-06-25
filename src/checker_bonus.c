/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fatimzehra </var/spool/mail/fatimzehra>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 09:08:42 by fatimzehra        #+#    #+#             */
/*   Updated: 2022/06/25 19:49:18 by fatimzehra       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"
#include "push_swap.h"
#include "get_next_line.h"
#include <unistd.h>

int	do_instructions(t_list **stack_a, t_list **stack_b, char * instraction)
{
	if (ft_strcmp(instraction, "sa\n") == 0)
		sa(stack_a);
	else if (ft_strcmp(instraction, "sb\n") == 0)
		sb(stack_b);
	else if (ft_strcmp(instraction, "ss\n") == 0)
		ss(stack_a, stack_b);
	else if (ft_strcmp(instraction, "pa\n") == 0)
		pa(stack_a, stack_b);
	else if (ft_strcmp(instraction, "pb\n") == 0)
		pb(stack_a, stack_b);
	else if (ft_strcmp(instraction, "ra\n") == 0)
		ra(stack_a);
	else if (ft_strcmp(instraction, "rb\n") == 0)
		rb(stack_b);
	else if (ft_strcmp(instraction, "rr\n") == 0)
		rr(stack_a, stack_b);
	else if (ft_strcmp(instraction, "rra\n") == 0)
		rra(stack_a);
	else if (ft_strcmp(instraction, "rrb\n") == 0)
		rrb(stack_b);
	else if (ft_strcmp(instraction, "rrr\n") == 0)
		rrr(stack_a, stack_b);
	else
		return (0);
	return (1);
}

void	check(t_list *stack_a, t_list *stack_b)
{
	if (is_sorted(stack_a) && stack_b == NULL)
		ft_putstr("OK");
	else 
		ft_putstr("KO");
}
	

int	main(int argc, char**argv)
{
	t_ctx	ctx;
	int		i;

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
	while (1)
	{
		char *line;
		line = get_next_line(0);
		if (line == 0)
			break;
		if (!do_instructions(&ctx.stack_a, &ctx.stack_b, line))
			return (free_ctx(&ctx, 1));
	}
	check(ctx.stack_a, ctx.stack_b);
	return (free_ctx(&ctx, 0));
}
