/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mairuiz <mairuiz@student.42urduliz.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/28 15:03:37 by mairuiz           #+#    #+#             */
/*   Updated: 2026/07/13 18:50:02 by mairuiz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	choose_strategy(int arg_type, char **argv)
{
	if (arg_type == 32)
		return (argv[1][2]);
	else if (arg_type == 321)
		return (argv[2][2]);
	else
		return ('a');
}

int	choose_bench(int arg_type)
{
	if (arg_type == 321 || arg_type == 31)
		return (1);
	else
		return (0);
}

int	stack_start(int arg_type)
{
	if (arg_type == 3)
		return (1);
	else if (arg_type == 32 || arg_type == 31)
		return (2);
	else
		return (3);
}

void	print_stack(char *name, t_stack *stack)
{
	t_node	*current;

	printf("\n%s\n", name);
	current = stack->top;
	while (current)
	{
		printf("value=%d  ", current->value);
		printf("index=%d", current->index);
		printf("\n");
		current = current->next;
	}
	printf("size: %i\n", stack->size);
}

void	push_swap(int argc, char **argv)
{
	int			arg_type;
	t_program	*program;
	t_benchmark	*benchmark;

	benchmark = create_benchmark();
	arg_type = check_args(argc, argv);
	if (arg_type == 0)
		return ;
	else if (arg_type == -1)
	{
		ft_printf(1, "Error\n");
		return ;
	}
	else
		program = set_program(arg_type, argv, argc);
	ft_printf(1, "%i\n", program->a->size);
	call_algorithm(program, benchmark);
	print_stack("A", program->a);
	set_benchmark(benchmark, program);
	printf_benchmark(benchmark, program);
	if (program->bench_enable == 1)
	{
		set_benchmark(benchmark, program);
		printf_benchmark(benchmark, program);
	}
}

int	main(int argc, char **argv)
{
	push_swap(argc, argv);
}
