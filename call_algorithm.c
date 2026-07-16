/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   call_algorithm.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarlasc <amarlasc@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/02 20:36:30 by mairuiz           #+#    #+#             */
/*   Updated: 2026/07/16 16:17:00 by amarlasc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	call_algorithm(t_program *program, t_bench *bench)
{
	//poner función is_sorted
	if (program->strategy == 's')
		simple_algorithm(program->a, program->b, bench);
	else if (program->strategy == 'm')
		medium_algorithm(program->a, program->b, bench);
	else if (program->strategy == 'c')
		complex_algorithm(program->a, program->b, bench);
	else
		adaptive_algorithm(program->a, program->b, bench, program->disorder);
}
