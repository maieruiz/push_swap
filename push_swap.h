/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mairuiz <mairuiz@student.42urduliz.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/22 17:35:59 by amarlasc          #+#    #+#             */
/*   Updated: 2026/07/06 00:01:40 by mairuiz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stddef.h>
# include <stdio.h>
# include <unistd.h>
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


void	sa(t_stack *a, t_benchmark *bench);
void	sb(t_stack *b, t_benchmark *bench);
void	ss(t_stack *a, t_stack *b, t_benchmark *bench);
void	pb(t_stack *a, t_stack *b, t_benchmark *bench);
void	pa(t_stack *a, t_stack *b, t_benchmark *bench);
void	ra(t_stack *a, t_benchmark *bench);
void	rb(t_stack *a, t_benchmark *bench);
void	rr(t_stack *a, t_stack *b, t_benchmark *bench);
void	rra(t_stack *a, t_benchmark *bench);
void	rrb(t_stack *b, t_benchmark *bench);
void	rrr(t_stack *a, t_stack *b, t_benchmark *bench);
int		check_args(int argc, char **argv);
t_stack	*create_new_stack(void);
t_stack	*create_stack(int start, int end, char **argv);
t_node	*create_node(int value, int index);
void	add_back_node(t_stack *a, t_node *node_to_add);
void	call_algorithm(t_program *program, t_benchmark *bench);
t_benchmark	*crete_benchmark(void);
t_program	*set_program(int arg_type, char **argv, int argc);
void	printf_benchmark(t_benchmark *bench);
void	set_benchmark(t_benchmark *benchmark, t_program *program);
#endif
