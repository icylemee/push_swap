/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlemee <mlemee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 19:21:53 by mlemee            #+#    #+#             */
/*   Updated: 2025/07/02 18:24:48 by mlemee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_error_input(char **nums, int *nb)
{
	if (nb)
		free(nb);
	if (nums)
		ft_free_split(nums);
	write(2, "Error\n", 6);
	exit (0);
}

void	ft_check_number(char **nums, char *s)
{
	int	i;

	i = 0;
	if (s[i] == '+' || s[i] == '-')
		i ++;
	if (!s[i] || s[i] == '+' || s[i] == '-')
		ft_error_input(nums, NULL);
	while (s[i] >= '0' && s[i] <= '9')
		i++;
	if (s[i] != '\0')
		ft_error_input(nums, NULL);
}

void	ft_check_int_limits(char **nums, char *s)
{
	long long int	atoi;

	atoi = ft_atoi_long(s);
	if (atoi > 2147483647 || atoi < -2147483648)
		ft_error_input(nums, NULL);
}

int	*ft_check_double(char **nums)
{
	int	*tab;
	int	i;
	int	j;
	int	size;

	size = ft_count_line(nums);
	tab = malloc(sizeof(int) * size);
	if (!tab)
		ft_error_input(nums, NULL);
	i = -1;
	while (nums[++i])
	{
		j = i - 1;
		tab[i] = ft_atoi(nums[i]);
		while (j >= 0)
		{
			if (tab[i] == tab[j])
				ft_error_input(nums, tab);
			j--;
		}
	}
	return (tab);
}

int	*ft_parsing(char *s, int *size_tab)
{
	char	**nums;
	int		i;
	int		*tab;

	i = -1;
	ft_check_charac(s);
	nums = ft_split(s, ' ');
	if (!nums)
		ft_error_input(NULL, NULL);
	while (nums[++i])
	{
		ft_check_number(nums, nums[i]);
		ft_check_int_limits(nums, nums[i]);
	}
	*size_tab = i;
	tab = ft_check_double;
	return (ft_free_split(nums), tab);
}
