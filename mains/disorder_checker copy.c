/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disorder_checker.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mairuiz <mairuiz@student.42urduliz.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/28 19:22:23 by amarlasc          #+#    #+#             */
/*   Updated: 2026/07/12 16:47:11 by mairuiz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	compute_disorder(t_stack *stack)
{
	float	mistake;
	float	total_pairs;
	t_node	*current;
	t_node	*runner;

	mistake = 0;
	total_pairs = 0;
	current = stack->top;
	if (stack->size <= 1)
		return (0.0f);
	while (current)
	{
		runner = current->next;
		while (runner)
		{
			total_pairs += 1;
			if (current->value > runner->value)
				mistake += 1;
			runner = runner->next;
		}
		current = current->next;
	}
	return ((mistake * 10000) / total_pairs);
}

t_node	*create_node(int value, int index)
{
	t_node	*new_node;

	new_node = (t_node *)malloc(sizeof(t_node));
	if (!new_node)
		return (NULL);
	new_node->value = value;
	new_node->index = index;
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


int	main(void)
{
	t_stack	*a;

	a = create_new_stack();
	add_back_node(a, create_node(6, 0));
	add_back_node(a, create_node(2, 0));
	add_back_node(a, create_node(3, 0));
	add_back_node(a, create_node(4, 0));
	add_back_node(a, create_node(5, 0));
	printf("%i\n", compute_disorder(a));
}