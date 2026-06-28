/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mairuiz <mairuiz@student.42urduliz.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/28 15:03:37 by mairuiz           #+#    #+#             */
/*   Updated: 2026/06/28 15:10:36 by mairuiz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap(int argc, char **argv)
{
	int	arg_tp;

	arg_tp = check_args(argc, argv);
	if (arg_tp == 0)
		return ;
	else if (arg_tp == -1)
		printf("Error\n");
	else
	printf("%i\n", arg_tp);
}

int	main(int argc, char **argv)
{
	push_swap(argc, argv);
}