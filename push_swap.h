/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarlasc <amarlasc@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/22 17:35:59 by amarlasc          #+#    #+#             */
/*   Updated: 2026/07/06 17:17:20 by amarlasc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stddef.h>
# include <stdio.h>
# include <unistd.h>
# include <limits.h>
# include "libft/libft.h"

typedef struct s_node
{
	int				value;
	int				index;
	struct s_node	*prev;
	struct s_node	*next;
}	t_node;
typedef struct s_stack
{
	t_node	*top;
	int		size;
}	t_stack;

void	sa(t_stack *a);
void	sb(t_stack *b);
void	ss(t_stack *a, t_stack *b);
void	pb(t_stack *a, t_stack *b);
void	pa(t_stack *a, t_stack *b);
void	ra(t_stack *a);
void	rb(t_stack *a);
void	rr(t_stack *a, t_stack *b);
void	rra(t_stack *a);
void	rrb(t_stack *b);
void	rrr(t_stack *a, t_stack *b);
int		validate_format(char **argv);
int		is_valid_number(char *str);
long	*convert_to_long(char **argv);
int		correct_stack(char **argv);
int		check_args(int argc, char **argv);
int		check_int_limits(long *nums, int count);
int		check_duplicates(long *nums, int count);
int		count_args(char	**argv);
int		ft_strcmp(const char *s1, const char *s2);
long	ft_atol(char *str);
#endif
