/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarlasc <amarlasc@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/22 17:40:18 by amarlasc          #+#    #+#             */
/*   Updated: 2026/07/09 16:09:55 by amarlasc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	pb(t_stack *a, t_stack *b, t_benchmark *bench)
{
	t_node	*temp;
	t_node	*next_node;

	if (!a->top)
		return ;
	temp = a->top;
	next_node = a->top->next;
	a->top = next_node;
	if (a->top)
		a->top->prev = NULL;
	temp->next = b->top;
	b->top = temp;
	a->size--;
	b->size++;
	bench->pb++;
	bench->total_ops++;
	write(1, "pb\n", 3);
}

void	pa(t_stack *a, t_stack *b, t_benchmark *bench)
{
	t_node	*temp;
	t_node	*next_node;

	if (!b->top)
		return ;
	temp = b->top;
	next_node = b->top->next;
	b->top = next_node;
	if (b->top)
		b->top->prev = NULL;
	temp->next = a->top;
	a->top = temp;
	b->size--;
	a->size++;
	bench->pa++;
	bench->total_ops++;
	write(1, "pa\n", 3);
}
