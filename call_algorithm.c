/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   call_algorithm.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarlasc <amarlasc@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/02 20:36:30 by mairuiz           #+#    #+#             */
/*   Updated: 2026/07/08 15:05:32 by amarlasc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	call_algorithm(t_program *program, t_benchmark *bench)
{
	if (program->strategy == 's')
		simple_algorithm(program->a, program->b, bench);
	else if (program->strategy == 'm')
		medium_algorithm(program->a, program->b, bench);
	else if (program->strategy == 'c')
		complex_algorithm(program->a, program->b, bench);
	else
		adaptive_algorithm(program->a, program->b, bench);
}
