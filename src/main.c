/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fael-bou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 12:02:22 by fael-bou          #+#    #+#             */
/*   Updated: 2022/06/01 19:39:46 by fael-bou         ###   ########.fr       */
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
	i = 1;
	while (i < argc)
	{
		ft_lstadd_front(&stack_a, ft_lstnew(ft_atoi(argv[i])));
		i++;
	}
	printf("hh\n");
	sa(&stack_a);
	printf("%p\n", stack_a);
	while (stack_a)
	{
		printf("%d\n", stack_a->content);
		stack_a = stack_a->next;
	}
	return 0;
}
