/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarlasc <amarlasc@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/22 17:40:18 by amarlasc          #+#    #+#             */
/*   Updated: 2026/07/06 17:16:42 by amarlasc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pb(t_stack *a, t_stack *b)
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
	write(1, "pb\n", 3);
}

void	pa(t_stack *a, t_stack *b)
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
	write(1, "pa\n", 3);
}
