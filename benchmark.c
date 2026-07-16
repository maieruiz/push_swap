/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   benchmark.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarlasc <amarlasc@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/08 15:02:38 by amarlasc          #+#    #+#             */
/*   Updated: 2026/07/16 16:29:01 by amarlasc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_bench	*create_benchmark(void)
{
	t_bench	*benchmark;

	benchmark = (t_bench *)malloc(sizeof(t_bench));
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
	return (benchmark);
}

void	set_bench(t_bench *benchmark, t_program *program)
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

char	*comp_class(t_program *p)
{
	if (p->strategy == 'a')
	{
		if (p->disorder < 0.2)
			return ("O(n²)");
		else if (0.2 <= p->disorder && p->disorder < 0.5)
			return ("O(n√n)");
		else
			return ("O(n log n)");
	}
	else if (p->strategy == 's')
		return ("O(n²)");
	else if (p->strategy == 'm')
		return ("O(n√n)");
	else
		return ("O(n log n)");
}

void	printf_benchmark(t_bench *b, t_program *p)
{
	ft_printf(2, "[bench] disorder: %i.", ((int)(p->disorder * 10000)) / 100);
	ft_printf(2, "%i%%\n", ((int)(p->disorder * 10000)) % 100);
	ft_printf(2, "[bench] strategy: %s / %s\n", b->strategy, comp_class(p));
	ft_printf(2, "[bench] total_ops: %i\n", b->total_ops);
	ft_printf(2, "[bench] sa: %i sb: %i ", b->sa, b->sb);
	ft_printf(2, "ss: %i pa: %i pb: %i\n", b->ss, b->pa, b->pb);
	ft_printf(2, "[bench] ra: %i rb: %i rr: %i ", b->ra, b->rb, b->rr);
	ft_printf(2, "rra: %i rrb: %i rrr: %i\n", b->rra, b->rrb, b->rrr);
}
