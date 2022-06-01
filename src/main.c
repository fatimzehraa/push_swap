#include <stdio.h>
#include <stdlib.h>

t_list *lst_new(int content)
{
	t_list *node;

	node = (t_list *)maloc(sizeof(t_list));
	if (node == NULL)
		return (NULL);
	node->content = content;
	node->next = NULL;
	return (node);
}

void lst_add_front(t_list **list, t_list *node)
{
	if (list == NULL)
		return;
	node->next = *list;
	*list = node;
}

void push(t_list **x, int value)
{
	lst_add_front(x, lst_new(value));
	

}

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
	t_list *a;
	t_list *b;
	int i;

	i = 0;
	a = lst_new(ft_atoi(argv[i]));
	while (i <= argc)
	{
		lst_add_front(&a, lst_new(ft_atoi(argv[i])));
	}
	return 0;
}
