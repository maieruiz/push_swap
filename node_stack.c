/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mairuiz <mairuiz@student.42urduliz.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/08 15:03:18 by amarlasc          #+#    #+#             */
/*   Updated: 2026/07/19 11:00:45 by mairuiz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*create_new_node(int value)
{
	t_node	*new_node;

	new_node = (t_node *)malloc(sizeof(t_node));
	if (!new_node)
		return (NULL);
	new_node->value = value;
	new_node->index = 0;
	new_node->prev = NULL;
	new_node->next = NULL;
	return (new_node);
}

static t_node	*last_node(t_stack *a)
{
	t_node	*current;

	current = a->top;
	while (current->next)
	{
		current = current->next;
	}
	return (current);
}

void	add_back_node(t_stack *a, t_node *node_to_add)
{
	t_node	*last;

	if (a->top == NULL)
	{
		a->top = node_to_add;
		return ;
	}
	last = last_node(a);
	last->next = node_to_add;
	node_to_add->prev = last;
}

t_stack	*create_new_stack(void)
{
	t_stack	*a;

	a = (t_stack *)malloc(sizeof(t_stack));
	if (!a)
		return (NULL);
	a->top = NULL;
	a->size = 0;
	return (a);
}

t_stack	*fill_stack(int start, int end, char **argv, t_stack *a)
{
	t_node	*current;

	while (start < end)
	{
		current = create_new_node(ft_atoi(argv[start]));
		add_back_node(a, current);
		a->size++;
		start++;
	}
	return (a);
}
