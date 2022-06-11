/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fael-bou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 12:02:22 by fael-bou          #+#    #+#             */
/*   Updated: 2022/06/10 20:05:21 by fatimzehra       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "list.h"
#include "push_swap.h"
#include <stdio.h>
#include <stdlib.h>

int ft_atoi(char *str)
{
	int i;
	int k;
	int number;

	i = 0;
	k = 1;
	number = 0;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			k *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		number = number * 10 + str[i] - '0';
		i++;
	}
	return (number * k);
}

int main (int argc, char *argv[])
{
	t_list *stack_a;
//	t_list *stack_b;
	int i;

	stack_a = NULL;
//	stack_b = NULL;
	i = 1;
	while (i < argc)
	{
		ft_lstadd_back(&stack_a, ft_lstnew(ft_atoi(argv[i])));
		i++;
	}
//	pb(&stack_a, &stack_b);
//	while (stack_b)
//	{
//		printf("stack_b %d\n", stack_b->content);
//		stack_b = stack_b->next;
//	}
//	rra(&stack_a);
	t_list *curr = stack_a;
	while (curr)
	{
		printf("stack_a->content : %d stack_a->position : %d\n", curr->content, curr->p);
		curr = curr->next;
	}
	printf("\n");
	curr = stack_a;
	position(stack_a);
	while (curr)
	{
		printf("stack_a->content : %d stack_a->position : %d\n", curr->content, curr->p);
		curr = curr->next;
	}
	printf("\n");
	sort_3(&stack_a);
	while (stack_a)
	{
		printf("stack_a->content : %d stack_a->position : %d\n", stack_a->content, stack_a->p);
		stack_a = stack_a->next;
	}
	return 0;
}
