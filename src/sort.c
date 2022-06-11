/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fatimzehra </var/spool/mail/fatimzehra>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 14:09:12 by fatimzehra        #+#    #+#             */
/*   Updated: 2022/06/11 19:42:47 by fatimzehra       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"
#include "push_swap.h"

int	is_sorted(t_list *stack_a)
{
	int pos;
	if (stack_a == NULL)
		return 0;
	pos = stack_a->p;
	while (stack_a)
	{
		if (pos > stack_a->p)
			return (0);
		pos = stack_a->p;
		stack_a = stack_a->next;
	}
	return (1);
}

void	sort_3(t_list **stack_a)
{
	if ((*stack_a)->p == 1 && (*stack_a)->next->p == 0)
		sa(stack_a);
	else if ((*stack_a)->p == 2 && (*stack_a)->next->p == 0)
		ra(stack_a);
	else if ((*stack_a)->p == 1 && (*stack_a)->next->p == 2)
		rra(stack_a);
	if (is_sorted(*stack_a))
		return;
	else
		sa(stack_a);
	sort_3(stack_a);
}
