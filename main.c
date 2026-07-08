/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarlasc <amarlasc@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/23 18:15:58 by amarlasc          #+#    #+#             */
/*   Updated: 2026/07/08 17:42:35 by amarlasc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

#include <stdio.h>

static void	print_stack(char *name, t_stack *stack)
{
	t_node	*current;

	printf("%s (size = %d)\n", name, stack->size);
	current = stack->top;
	while (current)
	{
		printf("%d\n", current->value);
		current = current->next;
	}
	printf("-----------------\n");
}

int	main(void)
{
	t_stack		a;
	t_stack		b;

	t_node	n1;
	t_node	n2;
	t_node	n3;
	t_node	n4;
	t_node	n5;

	/* Inicializar stack B */
	b.top = NULL;
	b.size = 0;

	/* Valores */
	n1.value = 5;
	n2.value = 4;
	n3.value = 3;
	n4.value = 2;
	n5.value = 1;

	/* Los index no importan para este algoritmo */
	n1.index = 0;
	n2.index = 0;
	n3.index = 0;
	n4.index = 0;
	n5.index = 0;

	/* Enlaces */
	n1.prev = NULL;
	n1.next = &n2;

	n2.prev = &n1;
	n2.next = &n3;

	n3.prev = &n2;
	n3.next = &n4;

	n4.prev = &n3;
	n4.next = &n5;

	n5.prev = &n4;
	n5.next = NULL;

	/* Stack A */
	a.top = &n1;
	a.size = 5;

	print_stack("STACK A ANTES", &a);
	print_stack("STACK B ANTES", &b);

	simple_algorithm(&a, &b);

	print_stack("STACK A DESPUÉS", &a);
	print_stack("STACK B DESPUÉS", &b);

	return (0);
}
