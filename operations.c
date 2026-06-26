/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarlasc <amarlasc@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/22 17:40:18 by amarlasc          #+#    #+#             */
/*   Updated: 2026/06/25 20:09:14 by amarlasc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
void	sa(t_stack *a)
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
	write(1, "sa\n", 3);
}

void	sb(t_stack *b)
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
	write(1, "sb\n", 3);
}

void	ss(t_stack *a, t_stack *b)
{
	sa(a);
	sb(b);
	write(1, "ss\n", 3);
}
*/
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

void	ra(t_stack *a)
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
	write(1, "ra\n", 3);
}

void	rb(t_stack *b)
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
	write(1, "rb\n", 3);
}

void	rr(t_stack *a, t_stack *b)
{
	ra(a);
	rb(b);
	write(1, "rr\n", 3);
}

void	rra(t_stack *a)
{
	t_node	*temp;
	t_node	*cursor;
	t_node	*new_last;

	if (!a->top || !a->top->next)
		return ;
	cursor = a->top;
	temp = a->top->next;
	while (cursor->next)
		cursor = cursor->next;
	a->top = cursor;
	a->top->prev = NULL;
	a->top->next = temp;
}