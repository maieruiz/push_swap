/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   program.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mairuiz <mairuiz@student.42urduliz.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/05 23:50:41 by mairuiz           #+#    #+#             */
/*   Updated: 2026/07/06 00:06:09 by mairuiz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_program	*create_program(void)
{
	t_program	*program;

	program = (t_program *)malloc(sizeof(t_program));
	if (!program)
		return (NULL);
	program->a = create_new_stack();
	program->b = create_new_stack();
	program->strategy = 'a';
	program->bench_enable = 0;
	program->disorder = 0.0;
	return (program);
}

t_program	*set_program(int arg_type, char **argv, int argc)
{
	t_program	*program;

	program = create_program();
	program->strategy = choose_stategy(arg_type, argv);
	program->bench_enable = choose_bench(arg_type);
	program->a = create_stack(stack_start(arg_type), argc, argv);
	program->disorder = compute_disorder(program->a);
}