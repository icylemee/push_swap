/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlemee <mlemee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 18:48:46 by mlemee            #+#    #+#             */
/*   Updated: 2025/07/09 19:25:00 by mlemee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_two_b(t_node **stack)
{
	if ((*stack)->value > (*stack)->next->value)
		return ;
	else
		ft_sb(stack);
}
void	ft_two_a(t_node **stack)
{
	if ((*stack)->value < (*stack)->next->value)
		return ;
	else
		ft_sa(stack);
}

void	ft_three_b(t_node **stack)
{
	if ((*stack)->value < (*stack)->next->value
		&& (*stack)->next->value < (*stack)->next->next->value) //123
		{
			ft_sb(stack);
			ft_rrb(stack);
		}
	if ((*stack)->value > (*stack)->next->value
		&& (*stack)->next->value < (*stack)->next->next->value) //213 ou 312
	{
		if ((*stack)->value < (*stack)->next->next->value) //213
			ft_rrb(stack);
		else //312
		{
			ft_sb(stack);
			ft_rb(stack);
		}
	}
	if ((*stack)->value > (*stack)->next->value
		&& (*stack)->next->value > (*stack)->next->next->value) // 321
		return ;
	if ((*stack)->value < (*stack)->next->value
		&& (*stack)->next->value > (*stack)->next->next->value) //231 ou 132
	{
		if ((*stack)->value < (*stack)->next->next->value) // 132
			ft_rb(stack);
		else //231
			ft_sb(stack);
	}
}

void	ft_three_a(t_node **stack)
{
	if ((*stack)->value < (*stack)->next->value
		&& (*stack)->next->value < (*stack)->next->next->value) //123
		return ;
	if ((*stack)->value > (*stack)->next->value
		&& (*stack)->next->value < (*stack)->next->next->value) //213 ou 312
	{
		if ((*stack)->value < (*stack)->next->next->value) //213
			ft_sa(stack);
		else //312
			ft_ra(stack);
	}
	if ((*stack)->value > (*stack)->next->value
		&& (*stack)->next->value > (*stack)->next->next->value) // 321
	{
		ft_sa(stack);
		ft_rra(stack);
	}
	if ((*stack)->value < (*stack)->next->value
		&& (*stack)->next->value > (*stack)->next->next->value) //231 ou 132
	{
		if ((*stack)->value < (*stack)->next->next->value) // 132
		{
			ft_sa(stack);
			ft_ra(stack);
		}
		else //231
			ft_rra(stack);
	}
}

void	ft_instruc_bis(t_node **stack, int cost, int med, int index)
{
	int	i;

	i = -1;
	if (index <= med)
	{
		while (++i <= cost)
			ft_ra(stack);
	}
	else if (index > med)
	{
		while (++i <= cost)
			ft_rra(stack);
	}
}

void	ft_instruc(t_node **stack, int cost, int b_or_l)
{
	int		med;
	int		index;
	int		len;

	len = ft_find_last(*stack)->index;
	if (len % 2 == 0)
			med = len / 2;
	else if (len % 2 != 0)
			med = (len / 2) + 1;
	if (b_or_l == LOWEST)
	{
		index = ft_index_lowest(stack);
		ft_instruc_bis(stack, cost, med, index);
	}
	else if (b_or_l == BIGGEST)
	{
		index = ft_index_bigest(stack);
		ft_instruc_bis(stack, cost, med, index);
	}
}

void	ft_four(t_node **stack_a, t_node **stack_b)
{
	int	cost_lowest;
	int	cost_biggest;

	cost_biggest = ft_cost_biggest(stack_a);
	cost_lowest = ft_cost_lowest(stack_a);
	if (cost_lowest <= cost_biggest)
	{
		ft_instruc(stack_a, cost_lowest, LOWEST);
		ft_pb(stack_a, stack_b);
		ft_three(stack_a);
		ft_pa(stack_a, stack_b);
	}
	else if (cost_biggest <= cost_lowest)
	{
		ft_instruc(stack_a, cost_biggest, BIGGEST);
		ft_pb(stack_a, stack_b);
		ft_three(stack_a);
		ft_pa(stack_a, stack_b);
		ft_ra(stack_a);
	}
}
// void	ft_five(t_node **stack_a, t_node **stack_b)
// {
// 	int	total_cost_lowest;
// 	int	total_cost_biggest;

// 	cost_biggest = ft_cost_biggest(stack_a) + ft_cost_secondbig(stack_a);
// 	cost_lowest = ft_cost_lowest(stack_a) + ft_cost_secondlow(stack_a)
// 	if (cost_lowest <= cost_biggest)
// 	{
// 		ft_instruc(stack_a, cost_lowest, LOWEST);
// 		ft_pb(stack_a, stack_b);
// 		ft_instruc(stack_a, cost_lowest, LOWEST);
// 		ft_pb(stack_a, stack_b);
// 		ft_three(stack_a);
// 		ft_pa(stack_a, stack_b);
// 		ft_pa(stack_a, stack_b);
// 	}
// 	else if (cost_biggest <= cost_lowest)
// 	{
// 		ft_instruc(stack_a, cost_lowest, BIGGEST);
// 		ft_pb(stack_a, stack_b);
// 		ft_instruc(stack_a, cost_lowest, BIGGEST);
// 		ft_pb(stack_a, stack_b);
// 		ft_three(stack_a);
// 		ft_pa(stack_a, stack_b);
// 		ft_pa(stack_a, stack_b);
// 		ft_sa(stack_a);
// 		ft_ra(stack_a);
// 		ft_ra(stack_a);
// 	}
// }
