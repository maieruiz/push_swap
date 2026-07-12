/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_algorithm.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
<<<<<<< HEAD
/*   By: amarlasc <amarlasc@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/02 20:12:57 by mairuiz           #+#    #+#             */
/*   Updated: 2026/07/10 13:26:35 by amarlasc         ###   ########.fr       */
=======
/*   By: mairuiz <mairuiz@student.42urduliz.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/02 20:12:57 by mairuiz           #+#    #+#             */
/*   Updated: 2026/07/06 14:24:20 by mairuiz          ###   ########.fr       */
>>>>>>> e9a1d646e49110b06bca91ba7f711d04226ec913
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

<<<<<<< HEAD
static int	find_min(t_stack *a)
=======
int	find_min(t_stack *a)
>>>>>>> e9a1d646e49110b06bca91ba7f711d04226ec913
{
	t_node	*current;
	t_node	*current_min;
	int		pos;
	int		pos_min;

	current = a->top;
	current_min = a->top;
	pos = 0;
	pos_min = 0;
	while (current->next)
	{
		if (current_min->value > current->next->value)
		{
			current_min = current->next;
			pos_min = pos + 1;
		}
		pos++;
		current = current->next;
	}
	return (pos_min);
}

<<<<<<< HEAD
void	rotate_to_min(t_stack *a, int pos_min, t_benchmark *bench)
{
	int	medium_line;
	int	moves;

	medium_line = a->size / 2;
	moves = pos_min;
	if (pos_min <= medium_line)
	{
		while (moves != 0)
		{
			ra(a, bench);
			moves--;
		}
	}
	else
	{
		moves = a->size - pos_min;
		while (moves != 0)
		{
			rra(a, bench);
			moves--;
		}
	}
}

static float	is_sorted(t_stack *a, t_stack *b, t_benchmark *bench)
{
	float	ret;

	ret = compute_disorder(a);
	if (ret == 0.0f)
	{
		while (b->top)
			pa(a, b, bench);
		return (0);
	}
	return (ret);
}

void	simple_algorithm(t_stack *a, t_stack *b, t_benchmark *bench)
{
	int	pos_min;

	while (a->top)
	{
		if (is_sorted(a, b, bench) == 0.0f)
			break ;
		pos_min = find_min(a);
		rotate_to_min(a, pos_min, bench);
		if (is_sorted(a, b, bench) == 0.0f)
			break ;
		pb(a, b, bench);
	}
	while (b->top)
		pa(a, b, bench);
=======
void	simple_algorithm(t_stack *a, t_stack *b, t_benchmark bench)
{
	
>>>>>>> e9a1d646e49110b06bca91ba7f711d04226ec913
}
