/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarlasc <amarlasc@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/06 17:13:56 by amarlasc          #+#    #+#             */
/*   Updated: 2026/07/09 16:13:43 by amarlasc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sa(t_stack *a, t_benchmark *bench)
{
	int	temp_value;
	int	temp_index;

	if (a->size < 2)
		return ;
	temp_value = a->top->value;
	temp_index = a->top->index;
	a->top->value = a->top->next->value;
	a->top->index = a->top->next->index;
	a->top->next->value = temp_value;
	a->top->next->index = temp_index;
	bench->sa++;
	bench->total_ops++;
	write(1, "sa\n", 3);
}

void	sb(t_stack *b, t_benchmark *bench)
{
	int	temp_value;
	int	temp_index;

	if (b->size < 2)
		return ;
	temp_value = b->top->value;
	temp_index = b->top->index;
	b->top->value = b->top->next->value;
	b->top->index = b->top->next->index;
	b->top->next->value = temp_value;
	b->top->next->index = temp_index;
	bench->sb++;
	bench->total_ops++;
	write(1, "sb\n", 3);
}

void	ss(t_stack *a, t_stack *b, t_benchmark *bench)
{
	sa(a, bench);
	sb(b, bench);
	bench->ss++;
	bench->total_ops++;
	write(1, "ss\n", 3);
}
