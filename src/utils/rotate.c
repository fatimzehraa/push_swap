/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fael-bou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 15:21:38 by fael-bou          #+#    #+#             */
/*   Updated: 2022/06/26 12:34:24 by fael-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "list.h"
#include "push_swap.h"

void	rotate(t_list **stack)
{
	t_list	*last_node;

	if (ft_lstsize(*stack) < 2)
		return ;
	last_node = ft_lstlast(*stack);
	last_node->next = *stack;
	*stack = (*stack)->next;
	last_node->next->next = NULL;
}

void	ra(t_list **stack_a)
{
	rotate(stack_a);
	ft_putstr("ra");
}

void	rb(t_list **stack_b)
{
	rotate(stack_b);
	ft_putstr("rb");
}

void	rr(t_list **stack_a, t_list **stack_b)
{
	rotate(stack_a);
	rotate(stack_b);
	ft_putstr("rr");
}
