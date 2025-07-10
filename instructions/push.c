/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlemee <mlemee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/29 18:40:54 by mlemee            #+#    #+#             */
/*   Updated: 2025/07/09 19:47:19 by mlemee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_index_maj(t_node **stack_a, t_node **stack_b)
{
	int		i;

	i = 0;
	while (*stack_a)
	{
		(*stack_a)->index = ++i;
		(*stack_a) = (*stack_a)->next;
	}
	i = 0;
	while (*stack_b)
	{
		(*stack_b)->index = ++i;
		(*stack_b) = (*stack_b)->next;
	}
}

void	ft_pb(t_node **stack_a, t_node **stack_b)
{
	t_node	*top;

	if (!stack_a || !*stack_a)
		return ;
	top = *stack_a;
	*stack_a = (*stack_a)->next;
	if (*stack_a)
		(*stack_a)->previous = NULL;
	top->next = *stack_b;
	if (*stack_b)
		(*stack_b)->previous = top;
	top->previous = NULL;
	*stack_b = top;
	ft_index_maj(stack_a, stack_b);
	ft_printf("pb\n");
}

void	ft_pa(t_node **stack_a, t_node **stack_b)
{
	t_node	*top;

	if (!stack_b || !*stack_b)
		return ;
	top = *stack_b;
	*stack_b = (*stack_b)->next;
	if (*stack_b)
		(*stack_b)->previous = NULL;
	top->next = *stack_a;
	if (*stack_a)
		(*stack_a)->previous = top;
	top->previous = NULL;
	*stack_a = top;
	ft_index_maj(stack_a, stack_b);
	ft_printf("pa\n");
}
