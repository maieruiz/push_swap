/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mairuiz <mairuiz@student.42urduliz.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/11 15:26:03 by mairuiz           #+#    #+#             */
/*   Updated: 2026/07/11 15:26:37 by mairuiz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	set_node_index(t_stack *a, t_node	*node)
{
	t_node	*current;
	int		i;

	i = 0;
	current = a->top;
	while (current->next)
	{
		if (current->value < node->value)
			i++;
		current = current->next;
	}
	if (current->value < node->value)
		i++;
	return (i);
}

void	set_stack_index(t_stack *a)
{
	t_node	*current;	

	current = a->top;
	while (current->next)
	{
		current->index = set_node_index(a, current);
		current = current->next;
	}
	current->index = set_node_index(a, current);
}
