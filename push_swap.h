/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarlasc <amarlasc@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/22 17:35:59 by amarlasc          #+#    #+#             */
/*   Updated: 2026/07/08 17:38:02 by amarlasc         ###   ########.fr       */
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
typedef struct s_benchmark
{
	float	disorder;
	char	*strategy;
	int		total_ops;
	int		sa;
	int		sb;
	int		ss;
	int		pb;
	int		pa;
	int		ra;
	int		rb;
	int		rr;
	int		rra;
	int		rrb;
	int		rrr;
}	t_benchmark;
typedef struct s_program
{
	t_stack	*a;
	t_stack	*b;
	char	strategy;
	int		bench_enable;
	float	disorder;
}	t_program;
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
float	compute_disorder(t_stack *stack);
int		correct_stack(char **argv);
int		check_args(int argc, char **argv);
int		check_int_limits(long *nums, int count);
int		check_duplicates(long *nums, int count);
int		count_args(char	**argv);
int		ft_strcmp(const char *s1, const char *s2);
long	ft_atol(char *str);
t_stack	*create_new_stack(void);
t_stack	*create_stack(int start, int end, char **argv);
t_node	*create_node(int value, int index);
void	add_back_node(t_stack *a, t_node *node_to_add);
void	call_algorithm(t_program *program, t_benchmark *bench);
t_benchmark	*create_benchmark(void);
t_program	*set_program(int arg_type, char **argv, int argc);
void	printf_benchmark(t_benchmark *bench);
void	set_benchmark(t_benchmark *benchmark, t_program *program);
void	simple_algorithm(t_stack *a, t_stack *b);
#endif
