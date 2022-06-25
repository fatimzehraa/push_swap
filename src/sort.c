/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fatimzehra </var/spool/mail/fatimzehra>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 14:09:12 by fatimzehra        #+#    #+#             */
/*   Updated: 2022/06/25 20:48:13 by fatimzehra       ###   ########.fr       */
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

void	sort_3(t_list **stack_a, int start)
{
	if ((*stack_a)->p == start + 1 && (*stack_a)->next->p == start + 0)
		sa(stack_a);
	else if ((*stack_a)->p == start + 2 && (*stack_a)->next->p == start + 0)
		ra(stack_a);
	else if ((*stack_a)->p == start + 1 && (*stack_a)->next->p == start + 2)
		rra(stack_a);
	if (is_sorted(*stack_a))
		return;
	else
		sa(stack_a);
	sort_3(stack_a, start);
}
void	sort_5(t_list **stack_a, t_list **stack_b)
{
	int size;

	size = ft_lstsize(*stack_a);
	if (size > 3)
		push_node_b(stack_a, stack_b, 0, size/2);
	if (size > 4)
		push_node_b(stack_a, stack_b, 1, size/2);
	sort_3(stack_a, size - 3);
	pa(stack_a, stack_b);
	pa(stack_a, stack_b);
}


void	chunk_size(t_list **stack_a, t_list **stack_b, int div)
{
	int size;
	int chunk;

	size = ft_lstsize(*stack_a);
	chunk = size/div;

	sort_100(stack_a, stack_b, chunk);
}

void	push_chunks1(t_list **stack_a, t_list **stack_b, int chunk)
{
	int x;
	int i;

	x = chunk - 1;
	while (*stack_a)
	{
		i = 0;
		while (i < chunk && *stack_a)
		{
			if ((*stack_a)->p <= x - (chunk/2))
			{
				pb(stack_a, stack_b);
				if (*stack_a) 
				{		
					if ((*stack_a)->p > x)
						rr(stack_a, stack_b);
					else 
						rb(stack_b);
				}
				else
					rb(stack_b);
				i++;
			}
			else if ((*stack_a)->p <= x)
			{
				pb(stack_a, stack_b);
				i++;
			}
			else
				ra(stack_a);
		}
		x += chunk;
	}
}

void	sort_100(t_list **stack_a, t_list **stack_b, int chunk)
{
	int size;

	push_chunks(stack_a, stack_b, chunk);
	size = ft_lstsize(*stack_b);
	while (size--)
	{
		if (size == 0 
				|| get_closest(size, *stack_b) < get_closest(size-1, *stack_b))
			push_node_a(stack_a, stack_b, size, size/2);
		else 
		{
			push_node_a(stack_a, stack_b, size - 1, size/2);
			size--;
			push_node_a(stack_a, stack_b, size + 1, size/2);
			sa(stack_a);
		}
	}
}


void	sort(int size_a, t_list **stack_a, t_list **stack_b)
{
	if (size_a == 1)
		return ;
	else if (size_a == 2)
	{
		if (is_sorted(*stack_a))
			return ;
		sa(stack_a);
	}
	else if (size_a == 3)
		sort_3(stack_a, 0);
	else if (size_a <= 5)
		sort_5(stack_a, stack_b);
	else if (size_a <= 200)
		chunk_size(stack_a, stack_b, 5);
	else 
		chunk_size(stack_a, stack_b, 9);

}
