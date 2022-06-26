/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fael-bou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 14:09:12 by fael-bou          #+#    #+#             */
/*   Updated: 2022/06/26 13:15:08 by fael-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"
#include "push_swap.h"

void	chunk_size(t_list **stack_a, t_list **stack_b, int div)
{
	int	size;
	int	chunk;

	size = ft_lstsize(*stack_a);
	chunk = size / div;
	sort_100(stack_a, stack_b, chunk);
}

void	push_chunks_help(t_list **stack_a, t_list **stack_b, int chunk, int x)
{
	int	i;

	i = 0;
	while (i < chunk && *stack_a)
	{
		if ((*stack_a)->p <= x - (chunk / 2))
		{
			pb(stack_a, stack_b);
			if (*stack_a && (*stack_a)->p > x)
				rr(stack_a, stack_b);
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
}

void	push_chunks(t_list **stack_a, t_list **stack_b, int chunk)
{
	int	x;

	x = chunk - 1;
	while (*stack_a)
	{
		push_chunks_help(stack_a, stack_b, chunk, x);
		x += chunk;
	}
}

void	sort_100(t_list **stack_a, t_list **stack_b, int chunk)
{
	int	size;

	push_chunks(stack_a, stack_b, chunk);
	size = ft_lstsize(*stack_b);
	while (size--)
	{
		if (size == 0 || get_closest(size, *stack_b)
			< get_closest(size - 1, *stack_b))
			push_node_a(stack_a, stack_b, size, size / 2);
		else
		{
			push_node_a(stack_a, stack_b, size - 1, size / 2);
			size--;
			push_node_a(stack_a, stack_b, size + 1, size / 2);
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
