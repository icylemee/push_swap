/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlemee <mlemee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/29 18:41:09 by mlemee            #+#    #+#             */
/*   Updated: 2025/07/09 19:49:28 by mlemee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_ra(t_node **stack_a)
{
	t_node	*tmp;
	t_node	*last;

	if (!stack_a || !*stack_a || !(*stack_a)->next)
		return ;
	last = ft_find_last(*stack_a);
	tmp = *stack_a;
	(*stack_a) = tmp->next;
	if (*stack_a)
		(*stack_a)->previous = NULL;
	tmp->previous = last;
	tmp->next = NULL;
	last->next = tmp;
	ft_index_maj(stack_a, NULL);
	ft_printf("ra\n");
}

void	ft_rb(t_node **stack_b)
{
	t_node	*tmp;
	t_node	*last;

	if (!stack_b || !*stack_b || !(*stack_b)->next)
		return ;
	last = ft_find_last(*stack_b);
	tmp = *stack_b;
	(*stack_b) = (*stack_b)->next;
	if (*stack_b)
		(*stack_b)->previous = NULL;
	tmp->previous = last;
	tmp->next = NULL;
	last->next = tmp;
	ft_index_maj(NULL, stack_b);
	ft_printf("rb\n");
}

void	ft_rr(t_node **stack_a, t_node **stack_b)
{
	ft_ra(stack_a);
	ft_rb(stack_b);
	ft_printf("rr\n");
}
