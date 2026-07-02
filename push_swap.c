/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mairuiz <mairuiz@student.42urduliz.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/28 15:03:37 by mairuiz           #+#    #+#             */
/*   Updated: 2026/07/02 20:37:52 by mairuiz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static char	choose_strategy(int arg_type, char **argv)
{
	if (arg_type == 32)
		return (argv[1][2]);
	else if (arg_type == 321)
		return (argv[2][2]);
	else
		return ('a');
}

static int	choose_bench(int arg_type)
{
	if (arg_type == 321 || arg_type == 31)
		return (1);
	else
		return (0);
}

static t_stack	*create_stack(int start, int end, char **argv)
{
	t_stack	*a;
	int		i;
	t_node	*current;

	i = 0;
	a = create_new_stack();
	while (start < end)
	{
		current = create_nodo(argv[start], i);
		add_back_node(a, current);
		a->size++;
		i++;
		start++;
	}
	return (a);
}

static int	stack_start(int arg_type)
{
	if (arg_type == 3)
		return (1);
	else if (arg_type == 32 || arg_type == 31)
		return (2);
	else
		return (3);
}

void	push_swap(int argc, char **argv)
{
	int		arg_type;
	char	strategy;
	int		bench;
	int		disorder;
	t_stack	*a;

	arg_type = check_args(argc, argv);
	if (arg_type == 0)
		return ;
	else if (arg_type == -1)
		ft_printf("Error\n");
	else
	{
		strategy = choose_stategy(arg_type, argv);
		bench = choose_bench(arg_type);
		a = create_stack(stack_start(arg_type), argc, argv);
		disorder = compute_disorder(a);
	}
	call_algorithm(strategy);
	printf("%i\n", arg_type);
}

/*int	main(int argc, char **argv)
{
	push_swap(argc, argv);
}*/