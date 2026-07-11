/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium_algorithm.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mairuiz <mairuiz@student.42urduliz.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/10 19:23:50 by mairuiz           #+#    #+#             */
/*   Updated: 2026/07/11 20:11:38 by mairuiz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_top_in_chunk(t_stack *a, int min, int max)
{
	if (min <= a->top->index && a->top->index <= max)
		return (1);
	return (0);
}

void push_to_b(t_stack *a, t_stack *b, t_benchmark *bench, t_chunk *chunk)
{
	int	chunk_cont;
	int	sub_chunk_cont;

	chunk_cont = 0;
	while (chunk_cont < chunk->chunk_size)
	{
		sub_chunk_cont = 0;
		while (sub_chunk_cont < chunk->chunk_size)
		{
			if (is_top_in_chunk(a, chunk->min, chunk->max) == 1)
				pb(a, b, bench);
			else
				ra(a, bench);
			sub_chunk_cont++;
		}
		next_chunk(chunk);
		chunk_cont++;
	}
}

void	medium_algorithm(t_stack *a, t_stack *b, t_benchmark *bench)
{
	t_chunk	*chunk;

	set_stack_index(a);
	chunk = set_chunk(create_chunk(), a->size);
	push_to_b(a, b, bench, chunk);
	push_to_a(a, b, bench, chunk);
}
