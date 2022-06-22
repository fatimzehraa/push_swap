/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fael-bou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 21:56:23 by fael-bou          #+#    #+#             */
/*   Updated: 2022/06/21 17:14:07 by fatimzehra       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"
#include "push_swap.h"
#include <stdio.h>

void pa(t_list **stack_a, t_list **stack_b)
{
	t_list *tmp;

	if (*stack_b == NULL)
		return ;
	tmp = (*stack_b)->next;
	ft_lstadd_front(stack_a, *stack_b);
	*stack_b = tmp;
	ft_putstr("pa");
}

void pb(t_list **stack_a, t_list **stack_b)
{
	t_list *tmp;

	if (*stack_a == NULL)
		return ;
	tmp = (*stack_a)->next;
	ft_lstadd_front(stack_b, *stack_a);
	*stack_a = tmp;
	ft_putstr("pb");
}

void	push_node_b(t_list **stack_a, t_list **stack_b, int position, int mid)
{
	if (p_index(*stack_a, position) < mid)
	{
		while (*stack_a)
		{
			if ((*stack_a)->p == position)
				break ;
			ra(stack_a);
		}
		pb(stack_a, stack_b);
	}
	else
	{
		while (*stack_a)
		{
			if ((*stack_a)->p == position)
				break ;
			rra(stack_a);
		}
		pb(stack_a, stack_b);
	}
}

void	push_node_a(t_list **stack_a, t_list **stack_b, int position, int mid)
{
	if (p_index(*stack_b, position) < mid)
	{
		while (*stack_b)
		{
			if ((*stack_b)->p == position)
				break ;
			rb(stack_b);
		}
		pa(stack_a, stack_b);
	}
	else
	{
		while (*stack_b)
		{
			if ((*stack_b)->p == position)
				break ;
			rrb(stack_b);
		}
		pa(stack_a, stack_b);
	}
}
