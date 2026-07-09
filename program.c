/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   program.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarlasc <amarlasc@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/08 15:04:06 by amarlasc          #+#    #+#             */
/*   Updated: 2026/07/09 17:11:30 by amarlasc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	stack_start(int arg_type)
{
	if (arg_type == 3)
		return (1);
	else if (arg_type == 32 || arg_type == 31)
		return (2);
	else
		return (3);
}

t_program	*create_program(void)
{
	t_program	*program;

	program = (t_program *)malloc(sizeof(t_program));
	if (!program)
		return (NULL);
	program->a = NULL;
	program->b = NULL;
	program->strategy = 'a';
	program->bench_enable = 0;
	program->disorder = 0.0;
	return (program);
}

t_stack	*create_stack(int start, int end, char **argv)
{
	t_stack	*a;
	int		i;
	t_node	*current;

	i = 0;
	a = create_new_stack();
	while (start < end)
	{
		current = create_node(ft_atoi(argv[start]), i);
		add_back_node(a, current);
		a->size++;
		i++;
		start++;
	}
	return (a);
}

t_program	*set_program(int arg_type, char **argv, int argc)
{
	t_program	*program;

	program = create_program();
	program->strategy = choose_strategy(arg_type, argv);
	program->bench_enable = choose_bench(arg_type);
	program->a = create_stack(stack_start(arg_type), argc, argv);
	program->disorder = compute_disorder(program->a);
	return (program);
}
