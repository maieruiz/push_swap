/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarlasc <amarlasc@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/23 18:15:58 by amarlasc          #+#    #+#             */
/*   Updated: 2026/06/25 20:09:29 by amarlasc         ###   ########.fr       */
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
}


int	main(void)
{
	t_node	n1;
	t_node	n2;
	t_node	n3;
	t_node	n4;
	t_node	n5;
	t_node	n6;	

	t_stack	a;
	t_stack b;

	n1.value = 1;
	n2.value = 2;
	n3.value = 10;
	n4.value = 4;
	n5.value = 6;
	n6.value = 9;

	n1.prev = NULL;
	n1.next = &n2;

	n2.prev = &n1;
	n2.next = &n3;

	n3.prev = &n2;
	n3.next = NULL;

	n4.prev = NULL;
	n4.next = &n5;

	n5.prev = &n4;
	n5.next = &n6;

	n6.prev = &n5;
	n6.next = NULL;


	a.top = &n1;
	a.size = 3;
	b.top = &n4;
	b.size = 3;



	print_stack("A antes", &a);
	//print_stack("B antes", &b);
	rra(&a);
	print_stack("A despues", &a);
	//print_stack("B despues", &b);
}
