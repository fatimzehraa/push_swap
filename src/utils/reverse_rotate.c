/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fael-bou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 00:14:03 by fael-bou          #+#    #+#             */
/*   Updated: 2022/06/26 12:34:41 by fael-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"
#include "push_swap.h"

void	reverse_rotate(t_list **stack)
{
	t_list	*curr;
	t_list	*befor_last;
	t_list	*last_node;

	curr = *stack;
	if (ft_lstsize(curr) < 2)
		return ;
	while (curr)
	{
		if (curr->next != NULL)
			befor_last = curr;
		curr = curr->next;
	}
	last_node = befor_last->next;
	last_node->next = *stack;
	*stack = last_node;
	befor_last->next = NULL;
}

void	rra(t_list **stack_a)
{
	reverse_rotate(stack_a);
	ft_putstr("rra");
}

void	rrb(t_list **stack_b)
{
	reverse_rotate(stack_b);
	ft_putstr("rrb");
}

void	rrr(t_list **stack_a, t_list **stack_b)
{
	reverse_rotate(stack_a);
	reverse_rotate(stack_b);
	ft_putstr("rrr");
}
