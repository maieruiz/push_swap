/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarlasc <amarlasc@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/28 15:03:37 by mairuiz           #+#    #+#             */
/*   Updated: 2026/07/09 17:33:57 by amarlasc         ###   ########.fr       */
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
		ft_printf("Error\n");
		return ;
	}
	else
		program = set_program(arg_type, argv, argc);
	call_algorithm(program, benchmark);
	if (program->bench_enable == 1)
	{
		set_benchmark(benchmark, program);
		//printf_benchmark(benchmark);
	}
}

int	main(int argc, char **argv)
{
	push_swap(argc, argv);
}
