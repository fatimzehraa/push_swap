/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fael-bou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 11:58:56 by fael-bou          #+#    #+#             */
/*   Updated: 2022/06/21 10:32:07 by fatimzehra       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"
#include "push_swap.h"
#include <stdio.h>

void	swap(t_list **stack) {
	t_list *node_1;
	t_list *node_2;
	t_list *tmp;

	if (ft_lstsize(*stack) > 1)
	{
		node_1 = (*stack);
		node_2 = (*stack)->next;
		tmp = node_2->next;
		node_2->next = node_1;
		node_1->next = tmp;
		*stack = node_2;
	}
}

void	sa(t_list **stack_a)
{
	swap(stack_a);
	ft_putstr("sa");
}

void	sb(t_list **stack_b)
{
	swap(stack_b);
	ft_putstr("sb");
}

void	ss(t_list **stack_a, t_list **stack_b)
{
	swap(stack_a);
	swap(stack_b);
	ft_putstr("ss");
}
