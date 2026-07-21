/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium_algorithm.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mairuiz <mairuiz@student.42urduliz.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/10 19:23:50 by mairuiz           #+#    #+#             */
/*   Updated: 2026/07/19 10:56:37 by mairuiz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_top_in_chunk(t_stack *a, int min, int max)
{
	if (min <= a->top->index && a->top->index <= max)
		return (1);
	return (0);
}

static void	push_to_b(t_program *program, t_bench *bench, t_chunk *chu)
{
	int	chunk_cont;
	int	chunk_total;
	int	sub_chunk_cont;

	chunk_cont = 0;
	chunk_total = program->a->size / chu->chunk_size;
	while (chunk_cont < chunk_total)
	{
		sub_chunk_cont = 0;
		while (sub_chunk_cont < chu->chunk_size)
		{
			if (is_top_in_chunk(program->a, chu->min, chu->max) == 1)
			{
				pb(program, bench);
				sub_chunk_cont++;
			}
			else
				ra(program, bench);
		}
		next_chunk(chu);
		chunk_cont++;
	}
	while (program->a->top)
		pb(program, bench);
}

static int	find_max(t_stack *b, int ind_to_find)
{
	t_node	*current;
	int		pos;

	current = b->top;
	pos = 0;
	while (current)
	{
		if (current->index == ind_to_find)
		{
			return (pos);
		}
		pos++;
		current = current->next;
	}
	return (-1);
}

static void	push_to_a(t_program *program, t_bench *bench)
{
	int	ind_to_push;
	int	medium_line;
	int	ind_pos;

	medium_line = program->b->size / 2;
	ind_to_push = program->b->size - 1;
	while (ind_to_push >= 0)
	{
		if (program->b->top->index == ind_to_push)
		{
			pa(program, bench);
			medium_line = program->b->size / 2;
			ind_to_push--;
		}
		else
		{
			ind_pos = find_max(program->b, ind_to_push);
			if (ind_pos < medium_line)
				rb(program, bench);
			else
				rrb(program, bench);
		}
	}
}

void	medium_algorithm(t_program *program, t_bench *bench)
{
	t_chunk	*chunk;

	set_stack_index(program->a);
	chunk = set_chunk(create_chunk(), program->a->size);
	push_to_b(program, bench, chunk);
	push_to_a(program, bench);
	free(chunk);
}
