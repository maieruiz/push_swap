/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mairuiz <mairuiz@student.42urduliz.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/06 17:13:56 by amarlasc          #+#    #+#             */
/*   Updated: 2026/07/18 14:02:00 by mairuiz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_program *program, t_bench *bench)
{
	int	temp_value;
	int	temp_index;

	if (program->a->size < 2)
		return ;
	temp_value = program->a->top->value;
	temp_index = program->a->top->index;
	program->a->top->value = program->a->top->next->value;
	program->a->top->index = program->a->top->next->index;
	program->a->top->next->value = temp_value;
	program->a->top->next->index = temp_index;
	bench->sa++;
	bench->total_ops++;
	write(1, "sa\n", 3);
}

void	sb(t_program *program, t_bench *bench)
{
	int	temp_value;
	int	temp_index;

	if (program->b->size < 2)
		return ;
	temp_value = program->b->top->value;
	temp_index = program->b->top->index;
	program->b->top->value = program->b->top->next->value;
	program->b->top->index = program->b->top->next->index;
	program->b->top->next->value = temp_value;
	program->b->top->next->index = temp_index;
	bench->sb++;
	bench->total_ops++;
	write(1, "sb\n", 3);
}

void	ss(t_program *program, t_bench *bench)
{
	sa(program, bench);
	sb(program, bench);
	bench->ss++;
	bench->total_ops++;
	write(1, "ss\n", 3);
}
