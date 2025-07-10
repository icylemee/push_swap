/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlemee <mlemee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 19:26:37 by mlemee            #+#    #+#             */
/*   Updated: 2025/07/09 20:47:28 by mlemee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>
#include <stdlib.h>

t_node	*ft_create_node(int value)
{
	t_node	*new;

	new = malloc(sizeof(t_node));
	if (!new)
		return (printf("Error malloc node\n"), NULL);
	new->value = value;
	new->next = NULL;
	new->previous = NULL;
	return (new);
}

t_node	*ft_find_last(t_node *stack)
{
	while (stack->next)
		stack = stack->next;
	return (stack);
}

void	ft_add_back(t_node **stack, t_node *new)
{
	t_node	*last;

	if (!stack || !new)
		return ;
	if (!*stack)
	{
		*stack = new;
		return ;
	}
	last = ft_find_last(*stack);
	last->next = new;
	new->previous = last;
}

void	ft_fill_stack(int *tab, int argc, t_node *a, t_node *b)
{
	int		i;
	int		j;
	t_node	*new;

	i = -1;
	j = 0;
	while (++i <= argc)
	{
		new = ft_create_node(tab[i]);
		if (!new)
			return (ft_free(&a), 0);
		new->index = ++j;
		new->cost = 0;
		new->target = NULL;
		ft_add_back(&a, new);
	}
}

void	ft_free(t_node **head) 
{
	int		i;
	t_node	*temp;

	if (!head)
		return ;
	while ((*head)->next)
	{
		temp = (*head)->next;
		free(*head);
		*head = temp;
	}
}

void	ft_check_quick_sort(int argc, t_node **stack_a, t_node **stack_b)
{
	if (argc == 2)
		ft_two(stack_a);
	else if (argc == 3)
		ft_three(stack_a);
	else if (argc == 4)
		ft_four(stack_a, stack_b);
}

int	push_swap(int *tab, int argc)
{
	t_node	*a;
	t_node	*b;

	a = NULL;
	b = NULL;
	ft_fill_stack(tab, argc, a, b);
	if (argc < 5)
		ft_check_quick_sort(argc, &a, &b);
	else 
	{
		ft_pb(&a, &b);
		ft_pb(&a, &b);
		ft_sort(&a, &b)
	}
	
}
void	ft_fill_target(t_node *stack_a, t_node **stack_b)
{
	t_node *save;

	save = *stack_b;
	while (save)
	{
		if (stack_a->value > save->value)
			stack_a->target = save;
		save = save->next;
	}
	save = *stack_b;
	while (save)
	{
		if (stack_a->value > save->value && save->value > stack_a->target->value)
			stack_a->target = save;
		save = save->next;
	}
}


void	ft_sort(t_node **stack_a, t_node **stack_b)
{
	t_node	*tmp;

	tmp = *stack_a;
	while (tmp)
	{
		ft_fill_target(tmp, stack_b);
		tmp = tmp->next;
	}
}

// int main(void)
// {
// 	int tab[] = {1,2,3,4,5,6,7,8,9,10};

// 	push_swap(tab, 10);
// }


	// i = -1;
	// while (++i <= argc - 1)
	// {
	// 	printf("%d\n", a->value);
	// 	a = a->next;
	// }
	// return (1);