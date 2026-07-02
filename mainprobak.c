
#include <stdio.h>
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

static t_stack	*create_stack(int start, int end, char **argv)
{
	t_stack	*a;
	int		i;
	t_node	*current;
	int		value;

	i = 0;
	a = create_new_stack();
	while (start < end)
	{
		printf("%s\n", argv[start]);
		value = atoi(argv[start]);
		current = create_node(value, i);
		add_back_node(a, current);
		a->size++;
		i++;
		start++;
	}
	return (a);
}

int	main(int argc, char **argv)
{
	t_stack	*a;

	printf("argc= %i\n", argc);
	a = create_stack(1, argc, argv);
	print_stack("A:", a);
}
