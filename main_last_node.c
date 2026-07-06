/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_last_node.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mairuiz <mairuiz@student.42urduliz.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/06 13:57:35 by mairuiz           #+#    #+#             */
/*   Updated: 2026/07/06 13:58:49 by mairuiz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_node	*last_node(t_stack *a)
{
	t_node	*current;

	current = a->top;
	while (current->next)
	{
		printf("last_next: %i\n", current->next->value);
		//break;
		current = current->next;
	}
	printf("last: %i\n", current->value);
	return (current);
}

int	main(void)
{
	
}
	