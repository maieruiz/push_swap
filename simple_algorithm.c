/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_algorithm.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarlasc <amarlasc@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/02 20:12:57 by mairuiz           #+#    #+#             */
/*   Updated: 2026/07/08 18:03:32 by amarlasc         ###   ########.fr       */
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

static void	move_a_top(t_stack *a, t_stack *b)
{
	int	pos_min;
	int	medium_line;
	int	rra_moves;
	int	counter_moves;

	pos_min = find_min(a);
	medium_line = a->size / 2;
	while (a->top)
	{
		if (pos_min <= medium_line)
		{
			counter_moves = pos_min;
			while (counter_moves != 0)
			{
				ra(a);
				counter_moves--;
			}
		}
		else
		{
			counter_moves = 0;
			rra_moves = a->size - pos_min;
			while (counter_moves < rra_moves)
			{
				rra(a);
				counter_moves++;
			}
		}
		pb(a, b);
	}
}

void	simple_algorithm(t_stack *a, t_stack *b)
{
	while (a->top)
	{
		if (compute_disorder(a) == 0)
		{
			while (b->top)
				pa(a, b);
			return ;
		}
		move_a_top (a, b);
	}
	while (b->top)
		pa(a, b);
}
