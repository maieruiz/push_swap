/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mairuiz <mairuiz@student.42urduliz.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/11 14:59:12 by mairuiz           #+#    #+#             */
/*   Updated: 2026/07/11 15:23:28 by mairuiz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*void	print_stack(char *name, t_stack *stack)
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
}*/

void	print_stack(char *name, t_stack *stack)
{
	t_node	*current;

	printf("\n%s\n", name);
	current = stack->top;
	while (current)
	{
		printf("value=%d  ", current->value);
		printf("index=%d", current->index);
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
	return (current);
}

void	add_back_node(t_stack *a, t_node *node_to_add)
{
	t_node	*last;

	a->size++;
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

int	set_node_index(t_stack *a, t_node	*node)
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

int	main(void)
{
	t_stack	*a;

	//printf("1\n");
	a = create_new_stack();
	//printf("2\n");
	add_back_node(a, create_node(100, 0));
	add_back_node(a, create_node(-1, 0));
	add_back_node(a, create_node(99, 0));
	add_back_node(a, create_node(-2, 0));
	add_back_node(a, create_node(98, 0));
	add_back_node(a, create_node(-3, 0));
	set_stack_index(a);
	print_stack("A", a);
	//printf("3\n");
	//printf("pos_min: %i\n", find_min(a)->value);
}