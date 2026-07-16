/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarlasc <amarlasc@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/06 17:14:56 by amarlasc          #+#    #+#             */
/*   Updated: 2026/07/16 15:23:07 by amarlasc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_stack *a, t_bench *bench)
{
	t_node	*temp;
	t_node	*cursor;

	if (!a->top || !a->top->next)
		return ;
	temp = a->top;
	a->top = a->top->next;
	cursor = a->top;
	while (cursor->next)
		cursor = cursor->next;
	cursor->next = temp;
	temp->next = NULL;
	temp->prev = cursor;
	bench->ra++;
	bench->total_ops++;
	write(1, "ra\n", 3);
}

void	rb(t_stack *b, t_bench *bench)
{
	t_node	*temp;
	t_node	*cursor;

	if (!b->top || !b->top->next)
		return ;
	temp = b->top;
	b->top = b->top->next;
	cursor = b->top;
	while (cursor->next)
		cursor = cursor->next;
	cursor->next = temp;
	temp->next = NULL;
	temp->prev = cursor;
	bench->rb++;
	bench->total_ops++;
	write(1, "rb\n", 3);
}

void	rr(t_stack *a, t_stack *b, t_bench *bench)
{
	ra(a, bench);
	rb(b, bench);
	bench->rr++;
	bench->total_ops++;
	write(1, "rr\n", 3);
}
