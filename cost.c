/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlemee <mlemee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 15:46:24 by mlemee            #+#    #+#             */
/*   Updated: 2025/07/09 18:01:51 by mlemee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_index_biggest(t_node **stack)
{
	t_node	*biggest;
	t_node	*tmp;

	if (!stack || !*stack)
		return (-1);
	tmp = *stack;
	biggest = tmp;
	tmp = tmp->next;
	while (tmp)
	{
		if (tmp->value > biggest->value)
			biggest = tmp;
	tmp = tmp->next;
	}
	return (biggest->index);
}

int	ft_index_lowest(t_node **stack)
{
	t_node	*lowest;
	t_node	*tmp;

	if (!stack || !*stack)
		return (-1);
	tmp = *stack;
	lowest = tmp;
	tmp = tmp->next;
	while (tmp)
	{
		if (tmp->value > lowest->value)
			lowest = tmp;
	tmp = tmp->next;
	}
	return (lowest->index);
}

int	ft_cost_biggest(t_node **stack)
{
	int		med;
	int		cost;
	int		indexbig;
	int		len;

	len = ft_find_last(*stack)->index;
	indexbig = ft_index_biggest(stack);
	if (len % 2 == 0)
		med = len / 2;
	else if (len % 2 != 0)
		med = (len / 2) + 1;
	if (indexbig <= med)
		cost = indexbig - 1;
	else if (indexbig > med)
		cost = len - indexbig + 1;
	return (cost);
}

int	ft_cost_lowest(t_node **stack)
{
	int		med;
	int		cost;
	int		indexlow;
	int		len;

	len = ft_find_last(*stack)->index;
	indexlow = ft_index_lowest(stack);
	if (len % 2 == 0)
		med = len / 2;
	else if (len % 2 != 0)
		med = (len / 2) + 1;
	if (indexlow <= med)
		cost = indexlow - 1;
	else if (indexlow > med)
		cost = len - indexlow + 1;
	return (cost);
}