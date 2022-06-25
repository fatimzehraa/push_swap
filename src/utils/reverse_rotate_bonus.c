/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fatimzehra </var/spool/mail/fatimzehra>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 14:49:00 by fatimzehra        #+#    #+#             */
/*   Updated: 2022/06/25 14:49:16 by fatimzehra       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "list.h"
#include "push_swap.h"

void	reverse_rotate(t_list **stack)
{

	t_list *curr;
	t_list *befor_last;
	t_list *last_node;

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
}

void	rrb(t_list **stack_b)
{
	reverse_rotate(stack_b);
}

void rrr(t_list **stack_a, t_list **stack_b)
{
	reverse_rotate(stack_a);
	reverse_rotate(stack_b);
}
