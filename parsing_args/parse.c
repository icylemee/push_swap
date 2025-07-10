/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlemee <mlemee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 18:25:24 by mlemee            #+#    #+#             */
/*   Updated: 2025/06/28 18:39:30 by mlemee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_parse_args(char *s)
{
	int	nb;

	ft_check_charac(s);
	ft_check_number(NULL, s);
	ft_check_int_limits(NULL, s);
	nb = ft_atoi(s);
	return (nb);
}
