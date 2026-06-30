/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mairuiz <mairuiz@student.42urduliz.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/28 15:03:37 by mairuiz           #+#    #+#             */
/*   Updated: 2026/06/30 16:43:12 by mairuiz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	choose_strategy(int arg_type, char **argv)
{
	if (arg_type == 32)
		return (argv[1][2]);
	else if (arg_type == 321)
		return (argv[2][2]);
	else
		return ('a');
}

int	choose_bench(int arg_type)
{
	if (arg_type == 321 || arg_type == 31)
		return (1);
	else
		return (0);
}

void	push_swap(int argc, char **argv)
{
	int		arg_type;
	char	strategy;
	int		bench;
	int		disorder;

	arg_type = check_args(argc, argv);
	if (arg_type == 0)
		return ;
	else if (arg_type == -1)
		printf("Error\n");
	else
	{
		strategy = choose_stategy(arg_type, argv);
		bench = choose_bench(arg_type);
		//create stack or create in check_args??
		disorder = compute_disorder();
	}
	if (stategy == 's')
		
	printf("%i\n", arg_type);
}

int	main(int argc, char **argv)
{
	push_swap(argc, argv);
}