/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rot_reverse.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mairuiz <mairuiz@student.42urduliz.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/06 17:15:28 by amarlasc          #+#    #+#             */
/*   Updated: 2026/07/18 13:56:24 by mairuiz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_program *program, t_bench *bench)
{
	t_node	*temp;
	t_node	*new_top;

	if (!program->a->top || !program->a->top->next)
		return ;
	new_top = program->a->top;
	temp = program->a->top;
	while (new_top->next)
		new_top = new_top->next;
	new_top->prev->next = NULL;
	program->a->top = new_top;
	program->a->top->prev = NULL;
	program->a->top->next = temp;
	temp->prev = program->a->top;
	bench->rra++;
	bench->total_ops++;
	write(1, "rra\n", 4);
}

void	rrb(t_program *program, t_bench *bench)
{
	t_node	*temp;
	t_node	*new_top;

	if (!program->b->top || !program->b->top->next)
		return ;
	new_top = program->b->top;
	temp = program->b->top;
	while (new_top->next)
		new_top = new_top->next;
	new_top->prev->next = NULL;
	program->b->top = new_top;
	program->b->top->prev = NULL;
	program->b->top->next = temp;
	temp->prev = program->b->top;
	bench->rrb++;
	bench->total_ops++;
	write(1, "rrb\n", 4);
}

void	rrr(t_program *program, t_bench *bench)
{
	rra(program, bench);
	rrb(program, bench);
	bench->rrr++;
	bench->total_ops++;
	write(1, "rrr\n", 4);
}
