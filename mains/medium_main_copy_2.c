#include "../push_swap.h"

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

void	rb(t_stack *b, t_benchmark *bench)
{
	t_node	*temp;
	t_node	*cursor;

	if (!b->top || !b->top->next)
		return ;
	temp = b->top;
	b->top = b->top->next;
	cursor = b->top;
	while (cursor->next)
		cursor = cursor->next;
	cursor->next = temp;
	temp->next = NULL;
	bench->rb++;
	bench->total_ops++;
	write(1, "rb\n", 3);
}


void	rrb(t_stack *b, t_benchmark *bench)
{
	t_node	*temp;
	t_node	*new_top;

	if (!b->top || !b->top->next)
		return ;
	new_top = b->top;
	temp = b->top;
	while (new_top->next)
		new_top = new_top->next;
	b->top = new_top;
	b->top->prev = NULL;
	while (temp->next)
	{
		temp = temp->next;
		if (temp->next->next == NULL)
			temp->next = NULL;
	}
	while (temp->prev)
		temp = temp->prev;
	b->top->next = temp;
	temp->prev = b->top;
	bench->rrb++;
	bench->total_ops++;
	write(1, "rrb\n", 4);
}

void	pa(t_stack *a, t_stack *b, t_benchmark *bench)
{
	t_node	*temp;

	if (!b->top)
		return ;
	temp = b->top;
	b->top = temp->next;
	if (b->top)
		b->top->prev = NULL;
	temp->next = a->top;
	if (a->top)
		a->top->prev = temp;
	temp->prev = NULL;
	a->top = temp;
	b->size--;
	a->size++;
	bench->pb++;
	bench->total_ops++;
	write(1, "pb\n", 3);
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



static int	find_max(t_stack *b, int ind_to_find)
{
	t_node	*current;
	int		pos;

	current = b->top;
	pos = 0;
	while (current->next)
	{
		if (current->index == ind_to_find)
		{
			return (pos);
		}
		pos++;
		current = current->next;
	}
	return (pos);
}


void	push_to_a(t_stack *a, t_stack *b, t_benchmark *bench, t_chunk *chunk)
{
	int	ind_to_push;
	int	medium_line;
	int	ind_pos;

	printf("push_to_a\n");
	medium_line = b->size / 2;
	ind_to_push = b->size - 1;
	while (ind_to_push >= 0)
	{
		if (b->top->index == ind_to_push)
		{
			pa(a, b, bench);
			ind_to_push--;
		}
		else
		{
			ind_pos = find_max(b, ind_to_push);
			if (ind_pos < medium_line)
				rb(b, bench);
			else
				rrb(b, bench);
		}
	}
}

void	medium_algorithm(t_stack *a, t_stack *b, t_benchmark *bench)
{
	t_chunk	*chunk;

	set_stack_index(a);
	chunk = set_chunk(create_chunk(), a->size);
	push_to_b(a, b, bench, chunk);
	push_to_a(a, b, bench, chunk);
}

int	main(void)
{
	t_stack	*a;
	t_stack	*b;
	t_benchmark	*bench;

	bench = create_benchmark();
	a = create_new_stack();
	b = create_new_stack();
	add_back_node(a, create_node(9, 8));
	add_back_node(a, create_node(8, 7));
	add_back_node(a, create_node(7, 6));
	add_back_node(a, create_node(6, 5));
	add_back_node(a, create_node(5, 5));
	add_back_node(a, create_node(4, 3));
	add_back_node(a, create_node(3, 2));
	add_back_node(a, create_node(2, 1));
	add_back_node(a, create_node(1, 0));
	medium_algorithm(a, b, bench);
	print_stack("A", a);
	print_stack("B", b);
	printf("total_ops: %i\n", bench->total_ops);
	//printf("3\n");
	//printf("pos_min: %i\n", find_min(a)->value);
}