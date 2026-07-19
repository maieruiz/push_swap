/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mairuiz <mairuiz@student.42urduliz.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/22 17:35:59 by amarlasc          #+#    #+#             */
/*   Updated: 2026/07/19 11:01:16 by mairuiz          ###   ########.fr       */
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
typedef struct s_bench
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
}	t_bench;
typedef struct s_flag
{
	char	strategy;
	int		bench;
}	t_flag;
typedef struct s_program
{
	t_stack	*a;
	t_stack	*b;
	t_flag	*flag;
	float	disorder;
}	t_program;
typedef struct s_chunk
{
	int	chunk_size;
	int	min;
	int	max;
}	t_chunk;
void		sa(t_program *program, t_bench *bench);
void		sb(t_program *program, t_bench *bench);
void		ss(t_program *program, t_bench *bench);
void		pb(t_program *program, t_bench *bench);
void		pa(t_program *program, t_bench *bench);
void		ra(t_program *program, t_bench *bench);
void		rb(t_program *program, t_bench *bench);
void		rr(t_program *program, t_bench *bench);
void		rra(t_program *program, t_bench *bench);
void		rrb(t_program *program, t_bench *bench);
void		rrr(t_program *program, t_bench *bench);
char		choose_strategy(int arg_type, char **argv);
int			choose_bench(int arg_type);
int			validate_format(char **argv);
int			is_valid_number(char *str);
long		*convert_to_long(char **argv);
float		compute_disorder(t_stack *stack);
int			correct_stack(char **argv);
int			check_args(int argc, char **argv, t_program *program);
int			check_int_limits(long *nums, int count);
int			check_duplicates(long *nums, int count);
int			count_args(char	**argv);
int			ft_strcmp(const char *s1, const char *s2);
long		ft_atol(char *str);
t_program	*create_program(void);
t_stack		*create_new_stack(void);
t_stack		*fill_stack(int start, int end, char **argv, t_stack *a);
t_node		*create_new_node(int value);
void		add_back_node(t_stack *a, t_node *node_to_add);
void		call_algorithm(t_program *program, t_bench *bench);
t_bench		*create_benchmark(void);
void		printf_benchmark(t_bench *b, t_program *p);
t_program	*set_program(int arg_type, char **argv, int argc);
void		set_bench(t_bench *benchmark, t_program *program);
void		simple_algorithm(t_program *program, t_bench *bench);
void		medium_algorithm(t_program *program, t_bench *bench);
void		complex_algorithm(t_program *program, t_bench *bench);
void		adaptive_algorithm(t_program *program, t_bench *bench);
void		set_stack_index(t_stack *a);
void		next_chunk(t_chunk	*chunk);
t_chunk		*set_chunk(t_chunk *chunk, int chunk_num);
t_chunk		*create_chunk(void);
void		superfree(t_bench *bench, t_program *program);
void		free_program(t_program *program);
#endif
