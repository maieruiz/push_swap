/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   benchmark.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarlasc <amarlasc@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/08 15:02:38 by amarlasc          #+#    #+#             */
/*   Updated: 2026/07/08 15:02:48 by amarlasc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_benchmark	*crete_benchmark(void)
{
	t_benchmark	*benchmark;

	benchmark = (t_benchmark *)malloc(sizeof(t_benchmark));
	if (!benchmark)
		return (NULL);
	benchmark->disorder = 0.0;
	benchmark->strategy = 0;
	benchmark->total_ops = 0;
	benchmark->sa = 0;
	benchmark->sb = 0;
	benchmark->ss = 0;
	benchmark->pb = 0;
	benchmark->pa = 0;
	benchmark->ra = 0;
	benchmark->rb = 0;
	benchmark->rr = 0;
	benchmark->rra = 0;
	benchmark->rrb = 0;
	benchmark->rrr = 0;
}

void	set_benchmark(t_benchmark *benchmark, t_program *program)
{
	benchmark->disorder = program->disorder;
	if (program->strategy == 's')
		benchmark->strategy = "Simple";
	else if (program->strategy == 'm')
		benchmark->strategy = "Medium";
	else if (program->strategy == 'c')
		benchmark->strategy = "Complex";
	else if (program->strategy == 'a')
		benchmark->strategy = "Adaptive";
}

void	printf_benchmark(t_benchmark *bench)
{
}
