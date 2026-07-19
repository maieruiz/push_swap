/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   call_algorithm.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mairuiz <mairuiz@student.42urduliz.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/02 20:36:30 by mairuiz           #+#    #+#             */
/*   Updated: 2026/07/19 10:24:01 by mairuiz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	call_algorithm(t_program *program, t_bench *bench)
{
	if (program->disorder == 0.0)
		return ;
	if (program->flag->strategy == 's')
		simple_algorithm(program, bench);
	else if (program->flag->strategy == 'm')
		medium_algorithm(program, bench);
	else if (program->flag->strategy == 'c')
		complex_algorithm(program, bench);
	else
		adaptive_algorithm(program, bench);
}
