/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_algorithm.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mairuiz <mairuiz@student.42urduliz.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/02 20:14:33 by mairuiz           #+#    #+#             */
/*   Updated: 2026/07/18 14:12:54 by mairuiz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_bits(int num)
{
	int	bits;

	bits = 0;
	while (num)
	{
		bits++;
		num /= 2;
	}
	return (bits);
}

static void	check_byte(t_program *program, int bit, t_bench *bench)
{
	t_node	*current;
	t_node	*temp;
	int		n;
	int		n_times;

	current = program->a->top;
	n_times = program->a->size;
	n = 0;
	while (n < n_times)
	{
		temp = current->next;
		if (((current->index >> bit) & 1) == 0)
			pb(program, bench);
		else
			ra(program, bench);
		current = temp;
		n++;
	}
}

void	complex_algorithm(t_program *program, t_bench *bench)
{
	int	bit;
	int	rounds;

	bit = 0;
	set_stack_index(program->a);
	rounds = get_bits(program->a->size - 1);
	while (bit < rounds)
	{
		check_byte(program, bit, bench);
		while (program->b->top)
			pa(program, bench);
		bit++;
	}
}
