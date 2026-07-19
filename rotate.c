/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mairuiz <mairuiz@student.42urduliz.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/06 17:14:56 by amarlasc          #+#    #+#             */
/*   Updated: 2026/07/18 14:00:21 by mairuiz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_program *program, t_bench *bench)
{
	t_node	*temp;
	t_node	*cursor;

	if (!program->a->top || !program->a->top->next)
		return ;
	temp = program->a->top;
	program->a->top = program->a->top->next;
	cursor = program->a->top;
	while (cursor->next)
		cursor = cursor->next;
	cursor->next = temp;
	temp->next = NULL;
	temp->prev = cursor;
	bench->ra++;
	bench->total_ops++;
	write(1, "ra\n", 3);
}

void	rb(t_program *program, t_bench *bench)
{
	t_node	*temp;
	t_node	*cursor;

	if (!program->b->top || !program->b->top->next)
		return ;
	temp = program->b->top;
	program->b->top = program->b->top->next;
	cursor = program->b->top;
	while (cursor->next)
		cursor = cursor->next;
	cursor->next = temp;
	temp->next = NULL;
	temp->prev = cursor;
	bench->rb++;
	bench->total_ops++;
	write(1, "rb\n", 3);
}

void	rr(t_program *program, t_bench *bench)
{
	ra(program, bench);
	rb(program, bench);
	bench->rr++;
	bench->total_ops++;
	write(1, "rr\n", 3);
}
