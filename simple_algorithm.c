/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_algorithm.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mairuiz <mairuiz@student.42urduliz.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/02 20:12:57 by mairuiz           #+#    #+#             */
/*   Updated: 2026/07/06 14:24:20 by mairuiz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_min(t_stack *a)
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

void	simple_algorithm(t_stack *a, t_stack *b, t_benchmark bench)
{
	
}
