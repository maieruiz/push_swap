/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarlasc <amarlasc@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/23 18:15:58 by amarlasc          #+#    #+#             */
/*   Updated: 2026/07/03 18:56:47 by amarlasc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(void)
{
	char	*test1[] = {"125", "58", "34", NULL};
	char	*test2[] = {"JSLDJF", "58", "34", NULL};

	printf("Test 1: %d\n", correct_stack(test1));
	printf("Test 2: %d\n", correct_stack(test2));
	return (0);
}
