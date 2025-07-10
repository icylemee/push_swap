/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlemee <mlemee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/29 18:41:00 by mlemee            #+#    #+#             */
/*   Updated: 2025/07/09 19:50:10 by mlemee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sa(t_node **stack_a)
{
	t_node	*tmp;
	t_node	*tmp2;

	if (!(*stack_a)->next || !stack_a || !*stack_a)
		return ;
	tmp = *stack_a;
	(*stack_a) = (*stack_a)->next;
	if (*stack_a)
		(*stack_a)->previous = NULL;
	tmp->previous = *stack_a;
	if ((*stack_a)->next)
	{
		tmp->next = (*stack_a)->next;
		tmp2 = tmp->next;
		tmp2->previous = tmp;
	}
	else
		tmp->next = NULL;
	(*stack_a)->next = tmp;
	ft_index_maj(stack_a, NULL);
	ft_printf("sa\n");
}

void	ft_sb(t_node **stack_b)
{
	t_node	*tmp;
	t_node	*tmp2;

	if (!(*stack_b)->next || !stack_b || !*stack_b)
		return ;
	tmp = *stack_b;
	(*stack_b) = (*stack_b)->next;
	if (*stack_b)
		(*stack_b)->previous = NULL;
	tmp->previous = *stack_b;
	if ((*stack_b)->next)
	{
		tmp->next = (*stack_b)->next;
		tmp2 = tmp->next;
		tmp2->previous = tmp;
	}
	else
		tmp->next = NULL;
	(*stack_b)->next = tmp;
	ft_index_maj(NULL, stack_b);
	ft_printf("sb\n");
}

void	ft_ss(t_node **stack_a, t_node **stack_b)
{
	ft_sa(stack_a);
	ft_sb(stack_b);
	ft_printf("ss\n");
}
