/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_algorithm.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarlasc <amarlasc@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/02 20:12:57 by mairuiz           #+#    #+#             */
/*   Updated: 2026/07/16 16:32:18 by amarlasc         ###   ########.fr       */
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

void	rotate_to_min(t_stack *a, int pos_min, t_bench *bench)
{
	int	medium_line;
	int	moves;

	medium_line = a->size / 2;
	moves = pos_min;
	if (pos_min <= medium_line)
	{
		while (moves != 0)
		{
			ra(a, bench);
			moves--;
		}
	}
	else
	{
		moves = a->size - pos_min;
		while (moves != 0)
		{
			rra(a, bench);
			moves--;
		}
	}
}

float	is_sorted(t_stack *a, t_stack *b, t_bench *bench)
{
	float	ret;

	ret = compute_disorder(a);
	if (ret == 0.0f)
	{
		while (b->top)
			pa(a, b, bench);
		return (0);
	}
	return (ret);
}

void	simple_algorithm(t_stack *a, t_stack *b, t_bench *bench)
{
	int	pos_min;

	while (a->top)
	{
		if (is_sorted(a, b, bench) == 0.0f)
			break ;
		pos_min = find_min(a);
		rotate_to_min(a, pos_min, bench);
		if (is_sorted(a, b, bench) == 0.0f)
			break ;
		pb(a, b, bench);
	}
	while (b->top)
		pa(a, b, bench);
}
