/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_simple.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mairuiz <mairuiz@student.42urduliz.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/06 13:22:24 by mairuiz           #+#    #+#             */
/*   Updated: 2026/07/06 14:22:01 by mairuiz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stack(char *name, t_stack *stack)
{
	t_node	*current;

	printf("\n%s\n", name);
	current = stack->top;
	while (current)
	{
		printf("value=%d", current->value);

		if (current->prev)
			printf(" prev=%d", current->prev->value);
		else
			printf(" prev=NULL");

		if (current->next)
			printf(" next=%d", current->next->value);
		else
			printf(" next=NULL");

		printf("\n");
		current = current->next;
	}
	printf("size: %i\n", stack->size);
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
	//printf("last: %i\n", current->value);
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

int	find_min(t_stack *a)
{
	t_node	*current;
	t_node	*current_min;
	int		pos;
	int		pos_min;

	current = a->top;
	current_min = a->top;
	pos = 0;
	pos_min = 0;
	while (current->next)
	{
		//printf("current_value: %i\n", current->value);
		if (current_min->value > current->next->value)
		{
			current_min = current->next;
			pos_min = pos + 1;
		}
		pos++;
		current = current->next;
	}
	return (pos_min);
}

int	main(void)
{
	t_stack	*a;

	//printf("1\n");
	a = create_new_stack();
	//printf("2\n");
	add_back_node(a, create_node(2, 0));
	add_back_node(a, create_node(4, 0));
	add_back_node(a, create_node(5, 0));
	add_back_node(a, create_node(1, 0));
	add_back_node(a, create_node(3, 0));
	//print_stack("A", a);
	//printf("3\n");
	printf("pos_min: %i\n", find_min(a));
}