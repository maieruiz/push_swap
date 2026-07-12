/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nosedondemeterlo.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mairuiz <mairuiz@student.42urduliz.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/02 20:36:30 by mairuiz           #+#    #+#             */
/*   Updated: 2026/07/05 23:51:02 by mairuiz          ###   ########.fr       */
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
