/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   superfree.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mairuiz <mairuiz@student.42urduliz.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/16 16:47:55 by amarlasc          #+#    #+#             */
/*   Updated: 2026/07/19 11:09:23 by mairuiz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	free_stack(t_stack *stack)
{
	t_node	*current;
	t_node	*next;

	if (!stack)
		return ;
	current = stack->top;
	while (current)
	{
		next = current->next;
		free(current);
		current = next;
	}
	free(stack);
}

void	free_program(t_program *program)
{
	free_stack(program->a);
	free_stack(program->b);
	free(program->flag);
	free(program);
}

void	superfree(t_bench *bench, t_program *program)
{
	free_program(program);
	free(bench);
}
