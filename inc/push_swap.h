/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fael-bou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 21:57:28 by fael-bou          #+#    #+#             */
/*   Updated: 2022/06/26 12:31:21 by fael-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include "list.h"

typedef struct s_ctx{
	t_list	*stack_a;
	t_list	*stack_b;
	char	**splited;
}	t_ctx;

void	pa(t_list **stack_a, t_list **stack_b);
void	pb(t_list **stack_a, t_list **stack_b);
void	sa(t_list **stack_a);
void	sb(t_list **stack_b);
void	ss(t_list **stack_a, t_list **stack_b);
void	ra(t_list **stack_a);
void	rb(t_list **stack_b);
void	rr(t_list **stack_a, t_list **stack_b);
void	rra(t_list **stack_a);
void	rrb(t_list **stack_b);
void	rrr(t_list **stack_a, t_list **stack_b);
int		ft_strlen(const char *s);
int		ft_atoi(char *str);
int		ft_strchr(char *str, char c);
int		ft_strcmp(char *s1, char *s2);
int		is_all_number(char **str);
void	ft_putstr(char *str);
char	**ft_duplicate(int argc, char **argv);
int		is_duplicated_number(char **splitted_nb);
void	free_tab(char **splitted_nb);
void	init_ctx(t_ctx *ctx);
int		free_ctx(t_ctx *ctx, int is_error);
char	**ft_split(char const *s, char c);
void	position(t_list *stack_a);
int		p_index(t_list *stack_a, int position);
void	sort_3(t_list **stack_a, int start);
void	push_node_a(t_list **stack_a, t_list **stack_b, int position, int mid);
void	push_node_b(t_list **stack_a, t_list **stack_b, int position, int mid);
void	sort_5(t_list **stack_a, t_list **stack_b);
void	sort_100(t_list **stack_a, t_list **stack_b, int chunk);
void	sort(int size_a, t_list **stack_a, t_list **stack_b);
int		is_sorted(t_list *stack_a);
int		get_closest(int position, t_list *stack_b);

void	free_tab(char **splitted_nb);
void	init_ctx(t_ctx *ctx);
int		free_ctx(t_ctx *ctx, int is_error);
#endif
