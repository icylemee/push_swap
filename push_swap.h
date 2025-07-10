/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlemee <mlemee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 19:12:57 by mlemee            #+#    #+#             */
/*   Updated: 2025/07/09 19:47:58 by mlemee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <../libft/libft.h>
# include <../get_next_line/get_next_line.h>
# include <../ft_printf/ft_printf.h>

# define LOWEST 0
# define BIGGEST 1

typedef struct	s_node	t_node;

struct s_node
{
	int		value;
	int		cost;
	int		index;
	t_node	*target;
	t_node	*next;
	t_node	*previous;
};

long long int	ft_atoi_long(const char *nptr);
char			**ft_free_split(char **split);
void			ft_error_input(char **nums, int *nb);
void			ft_check_charac(char *s);
void			ft_check_number(char **nums, char *s);
void			ft_check_int_limits(char **nums, char *s);
int				*ft_check_double(char **nums);
int				ft_count_line(char **split);
int				*ft_parsing(char *s, int *size_tab);
int				ft_parse_args(char *s);
void			ft_appel(int argc, char **argv);
t_node			*ft_find_last(t_node *stack);

void			ft_pb(t_node **stack_a, t_node **stack_b);
void			ft_pa(t_node **stack_a, t_node **stack_b);
void			ft_rra(t_node **stack_a);
void			ft_rrb(t_node **stack_b);
void			ft_rrr(t_node **stack_a, t_node **stack_b);
void			ft_ra(t_node **stack_a);
void			ft_rb(t_node **stack_b);
void			ft_rr(t_node **stack_a, t_node **stack_b);
void			ft_sa(t_node **stack_a);
void			ft_sb(t_node **stack_b);
void			ft_ss(t_node **stack_a, t_node **stack_b);
void			ft_index_maj(t_node **stack_a, t_node **stack_b);

int	ft_index_biggest(t_node **stack);
int	ft_index_lowest(t_node **stack);
int	ft_cost_biggest(t_node **stack);
int	ft_cost_lowest(t_node **stack);

void	ft_two(t_node **stack);
void	ft_three(t_node **stack);



#endif