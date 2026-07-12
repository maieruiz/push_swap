/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mairuiz <mairuiz@student.42urduliz.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/22 17:40:18 by amarlasc          #+#    #+#             */
/*   Updated: 2026/07/05 23:39:58 by mairuiz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	write(1, "sa\n", 3);
	bench->total_ops++;
	bench->sa++;
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
	write(1, "sb\n", 3);
	bench->total_ops++;
	bench->sb++;
}

void	ss(t_stack *a, t_stack *b, t_benchmark *bench)
{
	sa(a, bench);
	sb(b, bench);
	write(1, "ss\n", 3);
	bench->total_ops++;
	bench->ss++;
}

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
	write(1, "pb\n", 3);
	bench->total_ops++;
	bench->pb++;
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
	write(1, "pa\n", 3);
	bench->total_ops++;
	bench->pa++;
}

void	ra(t_stack *a, t_benchmark *bench)
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
	bench->total_ops++;
	bench->ra++;
}

void	rb(t_stack *b, t_benchmark *bench)
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
	bench->total_ops++;
	bench->rb++;
}

void	rr(t_stack *a, t_stack *b, t_benchmark *bench)
{
	ra(a, bench);
	rb(b, bench);
	write(1, "rr\n", 3);
	bench->total_ops++;
	bench->rr++;
}

void	rra(t_stack *a, t_benchmark *bench)
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
	bench->total_ops++;
	bench->rra++;
}

void rrb(t_stack *b, t_benchmark *bench)
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
	bench->total_ops++;
	bench->rrb++;
}

void rrr(t_stack *a, t_stack *b, t_benchmark *bench)
{
	rra(a, bench);
	rrb(b, bench);
	write(1, "rrr\n", 3);
	bench->total_ops++;
	bench->rrr++;
}