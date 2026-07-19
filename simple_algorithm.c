/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_algorithm.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mairuiz <mairuiz@student.42urduliz.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/02 20:12:57 by mairuiz           #+#    #+#             */
/*   Updated: 2026/07/18 17:40:57 by mairuiz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	find_min(t_stack *a)
{
	t_node	*current;
	t_node	*current_min;
	int		pos;
	int		pos_min;

	current = a->top;
	current_min = a->top;
	pos = 0;
	pos_min = 0;
	while (current->next)
	{
		if (current_min->value > current->next->value)
		{
			current_min = current->next;
			pos_min = pos + 1;
		}
		pos++;
		current = current->next;
	}
	return (pos_min);
}

static void	rotate_to_min(t_program *program, int pos_min, t_bench *bench)
{
	int	medium_line;
	int	moves;

	medium_line = program->a->size / 2;
	moves = pos_min;
	if (pos_min <= medium_line)
	{
		while (moves != 0)
		{
			ra(program, bench);
			moves--;
		}
	}
	else
	{
		moves = program->a->size - pos_min;
		while (moves != 0)
		{
			rra(program, bench);
			moves--;
		}
	}
}

static float	is_sorted(t_program *program, t_bench *bench)
{
	float	ret;

	ret = compute_disorder(program->a);
	if (ret == 0.0f)
	{
		while (program->b->top)
			pa(program, bench);
		return (0);
	}
	return (ret);
}

void	simple_algorithm(t_program *program, t_bench *bench)
{
	int	pos_min;

	while (program->a->top)
	{
		if (is_sorted(program, bench) == 0.0f)
			break ;
		pos_min = find_min(program->a);
		rotate_to_min(program, pos_min, bench);
		if (is_sorted(program, bench) == 0.0f)
			break ;
		pb(program, bench);
	}
	while (program->b->top)
		pa(program, bench);
}
