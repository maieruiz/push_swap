/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rot_reverse.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarlasc <amarlasc@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/06 17:15:28 by amarlasc          #+#    #+#             */
/*   Updated: 2026/07/06 17:17:41 by amarlasc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_stack *a)
{
	t_node	*temp;
	t_node	*new_top;

	if (!a->top || !a->top->next)
		return ;
	new_top = a->top;
	temp = a->top;
	while (new_top->next)
		new_top = new_top->next;
	a->top = new_top;
	a->top->prev = NULL;
	while (temp->next)
	{
		temp = temp->next;
		if (temp->next->next == NULL)
			temp->next = NULL;
	}
	while (temp->prev)
		temp = temp->prev;
	a->top->next = temp;
	temp->prev = a->top;
	write(1, "rra\n", 3);
}

void	rrb(t_stack *b)
{
	t_node	*temp;
	t_node	*new_top;

	if (!b->top || !b->top->next)
		return ;
	new_top = b->top;
	temp = b->top;
	while (new_top->next)
		new_top = new_top->next;
	b->top = new_top;
	b->top->prev = NULL;
	while (temp->next)
	{
		temp = temp->next;
		if (temp->next->next == NULL)
			temp->next = NULL;
	}
	while (temp->prev)
		temp = temp->prev;
	b->top->next = temp;
	temp->prev = b->top;
	write(1, "rrb\n", 3);
}

void	rrr(t_stack *a, t_stack *b)
{
	rra(a);
	rrb(b);
	write(1, "rrr\n", 3);
}
