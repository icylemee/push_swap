/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlemee <mlemee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/29 22:11:57 by mlemee            #+#    #+#             */
/*   Updated: 2025/07/09 19:48:56 by mlemee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rra(t_node **stack_a)
{
	t_node	*last;
	t_node	*a_last;

	if (!stack_a || !*stack_a || !(*stack_a)->next)
		return ;
	last = ft_find_last(*stack_a);
	a_last = last->previous;
	a_last->next = NULL;
	last->previous = NULL;
	last->next = *stack_a;
	(*stack_a)->previous = last;
	*stack_a = last;
	ft_index_maj(stack_a, NULL);
	ft_printf("rra\n");
}

void	ft_rrb(t_node **stack_b)
{
	t_node	*last;
	t_node	*a_last;

	if (!stack_b || !*stack_b || !(*stack_b)->next)
		return ;
	last = ft_find_last(*stack_b);
	a_last = last->previous;
	a_last->next = NULL;
	last->previous = NULL;
	last->next = *stack_b;
	(*stack_b)->previous = last;
	*stack_b = last;
	ft_index_maj(NULL, stack_b);
	ft_printf("rrb\n");
}

void	ft_rrr(t_node **stack_a, t_node **stack_b)
{
	ft_rra(stack_a);
	ft_rrb(stack_b);
	ft_printf("rrr\n");
}

