/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarlasc <amarlasc@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/16 15:30:15 by amarlasc          #+#    #+#             */
/*   Updated: 2026/07/16 15:31:20 by amarlasc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pb(t_stack *a, t_stack *b, t_bench *bench)
{
	t_node	*temp;

	if (!a->top)
		return ;
	temp = a->top;
	a->top = temp->next;
	if (a->top)
		a->top->prev = NULL;
	temp->next = b->top;
	if (b->top)
		b->top->prev = temp;
	temp->prev = NULL;
	b->top = temp;
	a->size--;
	b->size++;
	bench->pb++;
	bench->total_ops++;
	write(1, "pb\n", 3);
}

void	pa(t_stack *a, t_stack *b, t_bench *bench)
{
	t_node	*temp;

	if (!b->top)
		return ;
	temp = b->top;
	b->top = temp->next;
	if (b->top)
		b->top->prev = NULL;
	temp->next = a->top;
	if (a->top)
		a->top->prev = temp;
	temp->prev = NULL;
	a->top = temp;
	b->size--;
	a->size++;
	bench->pb++;
	bench->total_ops++;
	write(1, "pb\n", 3);
}
