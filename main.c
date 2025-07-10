/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlemee <mlemee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 18:24:24 by mlemee            #+#    #+#             */
/*   Updated: 2025/07/02 18:24:30 by mlemee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_appel(int argc, char **argv)
{
	int	i;
	int	j;
	int	n;
	int	*nombres;

	i = 0;
	n = -1;
	nombres = malloc(sizeof(int) * (argc - 1));
	if (!nombres)
		ft_error_input(NULL, NULL);
	while (++i < argc)
	{
		nombres[++n] = ft_parse_args(argv[i]);
		j = n - 1;
		while (j >= 0)
		{
			if (nombres[n] == nombres[j])
				ft_error_input(NULL, nombres);
			j--;
		}
	}
	j = push_swap(nombres, argc - 1);
	if (!j)
		ft_error_input(NULL, nombres);
}

int	main(int argc, char *argv[])
{
	int	*nombres;
	int	*size_tab;
	int	i;
	int	j;

	if (argc == 2)
	{
		nombres = ft_parsing(argv[1], &size_tab);
		j = push_swap(nombres, *size_tab);
		if (!j)
			ft_error_input(NULL, nombres);
	}
	else if (argc > 2)
	{
		ft_appel(argc, argv);
	}
	return (0);
}































// int	main(int argc, char *argv[])
// {
// 	int	*nombres;
// 	int	i;
// 	int	j;

// 	if (argc == 2)
// 	{
// 		nombres = ft_parsing(argv[1]);
// 		push_swap(nombres);
// 	}
// 	else if (argc > 2)
// 	{
// 		i = -1;
// 		nombres = malloc(sizeof(int) * (argc - 1));
// 		if (!nombres)
// 			ft_error_input(NULL, NULL);
// 		while (++i <= argc)
// 		{
// 			j = i - 1;
// 			nombres[i] = ft_parse_args(argv[i]);
// 			while (j >= 0)
// 			{
// 				if (nombres[i] == nombres[j])
// 					ft_error_input(NULL, nombres);
// 				j--;
// 			}
// 		}
// 		push_swap(nombres);
// 	}
// 	retrun (0);
// }
