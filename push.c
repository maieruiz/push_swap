/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mairuiz <mairuiz@student.42urduliz.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/16 15:30:15 by amarlasc          #+#    #+#             */
/*   Updated: 2026/07/18 14:03:34 by mairuiz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pb(t_program *program, t_bench *bench)
{
	t_node	*temp;

	if (!program->a->top)
		return ;
	temp = program->a->top;
	program->a->top = temp->next;
	if (program->a->top)
		program->a->top->prev = NULL;
	temp->next = program->b->top;
	if (program->b->top)
		program->b->top->prev = temp;
	temp->prev = NULL;
	program->b->top = temp;
	program->a->size--;
	program->b->size++;
	bench->pb++;
	bench->total_ops++;
	write(1, "pb\n", 3);
}

void	pa(t_program *program, t_bench *bench)
{
	t_node	*temp;

	if (!program->b->top)
		return ;
	temp = program->b->top;
	program->b->top = temp->next;
	if (program->b->top)
		program->b->top->prev = NULL;
	temp->next = program->a->top;
	if (program->a->top)
		program->a->top->prev = temp;
	temp->prev = NULL;
	program->a->top = temp;
	program->b->size--;
	program->a->size++;
	bench->pa++;
	bench->total_ops++;
	write(1, "pa\n", 3);
}
