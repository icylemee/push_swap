/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_long.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlemee <mlemee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 15:05:20 by mlemee            #+#    #+#             */
/*   Updated: 2025/06/28 17:08:08 by mlemee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

long long int	ft_atoi_long(const char *nptr)
{
	int				i;
	int				neg;
	long long int	result;

	i = 0;
	result = 0;
	neg = 1;
	if (nptr[i] == '+' || nptr[i] == '-')
	{
		if (nptr[i] == '-')
			neg = -1;
		i ++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		result *= 10;
		result += (nptr[i] - '0');
		i ++;
	}
	if (neg == -1)
		result = result * neg;
	return (result);
}

// int main(int argc, char *argv[])
// {
// 	if (argc == 2)
// 	{
// 		printf("ma fonction : %lld\n", ft_atoi_long(argv[1]));
// 		printf("VRAIE fonction : %d\n", atoi(argv[1]));
// 	}
// }
