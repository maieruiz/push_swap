/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium_algorithm.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mairuiz <mairuiz@student.42urduliz.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/10 19:23:50 by mairuiz           #+#    #+#             */
/*   Updated: 2026/07/14 17:42:53 by mairuiz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_top_in_chunk(t_stack *a, int min, int max)
{
	if (min <= a->top->index && a->top->index <= max)
		return (1);
	return (0);
}

static void	push_to_b(t_stack *a, t_stack *b, t_benchmark *bench, t_chunk *chu)
{
	int	chunk_cont;
	int	chunk_total;
	int	sub_chunk_cont;

	chunk_cont = 0;
	chunk_total = a->size / chu->chunk_size;
	while (chunk_cont < chunk_total)
	{
		sub_chunk_cont = 0;
		while (sub_chunk_cont < chu->chunk_size)
		{
			if (is_top_in_chunk(a, chu->min, chu->max) == 1)
			{
				pb(a, b, bench);
				sub_chunk_cont++;
			}
			else
				ra(a, bench);
		}
		next_chunk(chu);
		chunk_cont++;
	}
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

static void	push_to_a(t_stack *a, t_stack *b, t_benchmark *bench)
{
	int	ind_to_push;
	int	medium_line;
	int	ind_pos;

	medium_line = b->size / 2;
	ind_to_push = b->size - 1;
	while (ind_to_push >= 0)
	{
		printf("1\n");
		printf("ind_to_push: %i\n", ind_to_push);
		printf("1\n");
		//printf("b->top->value: %i\n", b->top->value);
		//printf("b->top->index: %i\n", b->top->index);
		if (b->top->index == ind_to_push)
		{
			pa(a, b, bench);
			medium_line = b->size / 2;
			ind_to_push--;
		}
		else
		{
			ind_pos = find_max(b, ind_to_push);
			if (ind_pos < medium_line)
				rb(b, bench);
			else
				rrb(b, bench);
		}
	}
}

void	medium_algorithm(t_stack *a, t_stack *b, t_benchmark *bench)
{
	t_chunk	*chunk;

	set_stack_index(a);
	chunk = set_chunk(create_chunk(), a->size);
	printf("chunck_size: %i\n", chunk->chunk_size);
	push_to_b(a, b, bench, chunk);
	print_stack("STACK AA:", a);
	print_stack("STACK BB:", b);
	push_to_a(a, b, bench);
}
