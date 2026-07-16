/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   superfree.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarlasc <amarlasc@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/16 16:47:55 by amarlasc          #+#    #+#             */
/*   Updated: 2026/07/16 17:04:22 by amarlasc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	superfree(t_stack *a, t_stack *b, t_bench *bench, t_program *pro)
{
	t_node	*temp;

	temp = a->top;
	while (a->top)
	{
		a->top = temp->next;
		free(temp);
		temp = a->top;
	}
	free(b);
	free(bench);
	free(a);
	free(pro);
}
