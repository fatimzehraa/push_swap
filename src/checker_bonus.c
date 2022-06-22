/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fatimzehra </var/spool/mail/fatimzehra>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 09:08:42 by fatimzehra        #+#    #+#             */
/*   Updated: 2022/06/22 16:33:42 by fatimzehra       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"
#include "push_swap.h"
#include "get_next_line.h"

void	do_instructions(t_list **stack_a, t_list **stack_b, char * instraction)
{
	if (ft_strcmp(instraction, "sa\n"))
		sa(stack_a);
	if (ft_strcmp(instraction, "sb\n"))
		sb(stack_a);
	if (ft_strcmp(instraction, "ss\n"))
		ss(stack_a, stack_b);
	if (ft_strcmp(instraction, "pa\n"))
		pa(stack_a, stack_b);
	if (ft_strcmp(instraction, "pb\n"))
		pb(stack_a, stack_b);
	if (ft_strcmp(instraction, "ra\n"))
		ra(stack_a);
	if (ft_strcmp(instraction, "rb\n"))
		rb(stack_a);
	if (ft_strcmp(instraction, "rr\n"))
		rr(stack_a, stack_b);
	if (ft_strcmp(instraction, "rra\n"))
		rra(stack_a);
	if (ft_strcmp(instraction, "rrb\n"))
		rrb(stack_a);
	if (ft_strcmp(instraction, "rrr\n"))
		rrr(stack_a, stack_b);
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
	while (get_next_line(1))
		do_instructions(&ctx.stack_a, &ctx.stack_b, get_next_line(1));
	check(ctx.stack_a, ctx.stack_b);
	return (free_ctx(&ctx, 0));
}
