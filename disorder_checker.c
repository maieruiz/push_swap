/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disorder_checker.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarlasc <amarlasc@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/28 19:22:23 by amarlasc          #+#    #+#             */
/*   Updated: 2026/06/29 18:29:09 by amarlasc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

float   compute_disorder(t_stack *stack)
{
	float mistake;
	float total_pairs;
	t_node	*counter;
	t_node	*current;
	t_node	*runner;
	
	mistake = 0;
	total_pairs = 0;
	current = stack->top;
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
	return (mistake/total_pairs);
}