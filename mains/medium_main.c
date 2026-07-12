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

t_benchmark	*create_benchmark(void)
{
	t_benchmark	*benchmark;

	benchmark = (t_benchmark *)malloc(sizeof(t_benchmark));
	if (!benchmark)
		return (NULL);
	benchmark->disorder = 0.0;
	benchmark->strategy = 0;
	benchmark->total_ops = 0;
	benchmark->sa = 0;
	benchmark->sb = 0;
	benchmark->ss = 0;
	benchmark->pb = 0;
	benchmark->pa = 0;
	benchmark->ra = 0;
	benchmark->rb = 0;
	benchmark->rr = 0;
	benchmark->rra = 0;
	benchmark->rrb = 0;
	benchmark->rrr = 0;
	return (benchmark);
}

void	ra(t_stack *a, t_benchmark *bench)
{
	t_node	*temp;
	t_node	*cursor;

	if (!a->top || !a->top->next)
		return ;
	temp = a->top;
	a->top = a->top->next;
	cursor = a->top;
	while (cursor->next)
		cursor = cursor->next;
	cursor->next = temp;
	temp->next = NULL;
	bench->ra++;
	bench->total_ops++;
	write(1, "ra\n", 3);
}

void	pb(t_stack *a, t_stack *b, t_benchmark *bench)
{
	t_node	*temp;

	if (!a->top)
		return ;
	temp = a->top;
	a->top = temp->next;
	if (a->top)
		a->top->prev = NULL;
	temp->next = b->top;
	if (b->top)
		b->top->prev = temp;
	temp->prev = NULL;
	b->top = temp;
	a->size--;
	b->size++;
	bench->pb++;
	bench->total_ops++;
	write(1, "pb\n", 3);
}

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

int	root(int num)
{
	int	i;

	i = 0;
	while (i * i <= num)
		i++;
	return (i - 1);
}


int	is_top_in_chunk(t_stack *a, int min, int max)
{
	if (min <= a->top->index && a->top->index <= max)
		return (1);
	return (0);
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

void	next_chunk(t_chunk	*chunk)
{
	chunk->min = chunk->max + 1;
	chunk->max = chunk->max + chunk->chunk_size;
}

t_chunk	*create_chunk()
{
	t_chunk	*new_chunk;

	new_chunk = (t_chunk *)malloc(sizeof(t_chunk));
	new_chunk->chunk_size = 0;
	new_chunk->min = 0;
	new_chunk->max = 0;
}

t_chunk	*set_chunk(t_chunk	*chunk, int	chunk_num)
{
	chunk->chunk_size = root(chunk_num);
	chunk->min = 0;
	chunk->max = chunk->chunk_size - 1;
	return (chunk);
}

void	medium_algorithm(t_stack *a, t_stack *b, t_benchmark *bench)
{
	t_chunk	*chunk;
	int	chunk_cont;
	int	sub_chunk_cont;
//push_to_b(a, b, bench, chunk);
	set_stack_index(a);
	chunk = set_chunk(create_chunk(), a->size);
	chunk_cont = 0;
	while (chunk_cont < chunk->chunk_size)
	{
		sub_chunk_cont = 0;
		while (sub_chunk_cont < chunk->chunk_size)
		{
			printf("sub_chunk: %i.%i\n", chunk_cont, sub_chunk_cont);
			printf("node: %i\n", a->top->value);
			if (is_top_in_chunk(a, chunk->min, chunk->max) == 1)
			{
				pb(a, b, bench);
				sub_chunk_cont++;
			}
			else
				ra(a, bench);
		}
		next_chunk(chunk);
		chunk_cont++;
	}
/*	chunk_a_b();
	while (b)
		push_max_to_a();*/
}

int	main(void)
{
	t_stack	*a;
	t_stack	*b;
	t_benchmark	*bench;

	bench = create_benchmark();
	a = create_new_stack();
	b = create_new_stack();
	add_back_node(a, create_node(2, 1));
	add_back_node(a, create_node(9, 8));
	add_back_node(a, create_node(3, 2));
	add_back_node(a, create_node(6, 5));
	add_back_node(a, create_node(8, 7));
	add_back_node(a, create_node(4, 3));
	add_back_node(a, create_node(5, 4));
	add_back_node(a, create_node(1, 0));
	add_back_node(a, create_node(7, 6));
	medium_algorithm(a, b, bench);
	print_stack("B", b);
	//printf("3\n");
	//printf("pos_min: %i\n", find_min(a)->value);
}