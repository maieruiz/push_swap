/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_algorithm.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarlasc <amarlasc@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/02 20:14:33 by mairuiz           #+#    #+#             */
/*   Updated: 2026/07/14 13:51:32 by amarlasc         ###   ########.fr       */
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

static void	check_byte(t_stack *a, t_stack *b, int bit, t_benchmark *bench)
{
	t_node	*current;
	t_node	*temp;
	int		n;
	int		n_times;

	current = a->top;
	n_times = a->size;
	n = 0;
	while (n < n_times)
	{
		temp = current->next;
		if (((current->index >> bit) & 1) == 0)
			pb(a, b, bench);
		else
			ra(a, bench);
		current = temp;
		n++;
	}
}

void	complex_algorithm(t_stack *a, t_stack *b, t_benchmark *bench)
{
	int	bit;
	int	rounds;

	bit = 0;
	set_stack_index(a);
	rounds = get_bits(a->size - 1);
	while (bit < rounds)
	{
		check_byte(a, b, bit, bench);
		print_stack("STACK A", a);
		print_stack("STACK B", b);
		while (b->top)
			pa(a, b, bench);
		bit++;
	}
}
