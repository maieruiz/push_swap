/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rot_reverse.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarlasc <amarlasc@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/06 17:15:28 by amarlasc          #+#    #+#             */
/*   Updated: 2026/07/16 15:23:07 by amarlasc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_stack *a, t_bench *bench)
{
	t_node	*temp;
	t_node	*new_top;

	if (!a->top || !a->top->next)
		return ;
	new_top = a->top;
	temp = a->top;
	while (new_top->next)
		new_top = new_top->next;
	new_top->prev->next = NULL;
	a->top = new_top;
	a->top->prev = NULL;
	a->top->next = temp;
	temp->prev = a->top;
	bench->rra++;
	bench->total_ops++;
	write(1, "rra\n", 4);
}

void	rrb(t_stack *b, t_bench *bench)
{
	t_node	*temp;
	t_node	*new_top;

	if (!b->top || !b->top->next)
		return ;
	new_top = b->top;
	temp = b->top;
	while (new_top->next)
		new_top = new_top->next;
	new_top->prev->next = NULL;
	b->top = new_top;
	b->top->prev = NULL;
	b->top->next = temp;
	temp->prev = b->top;
	bench->rrb++;
	bench->total_ops++;
	write(1, "rrb\n", 4);
}

void	rrr(t_stack *a, t_stack *b, t_bench *bench)
{
	rra(a, bench);
	rrb(b, bench);
	bench->rrr++;
	bench->total_ops++;
	write(1, "rrr\n", 4);
}
