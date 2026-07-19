/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adaptive_algorithm.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mairuiz <mairuiz@student.42urduliz.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/11 15:47:01 by mairuiz           #+#    #+#             */
/*   Updated: 2026/07/18 14:14:29 by mairuiz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	adaptive_algorithm(t_program *program, t_bench *bench)
{
	if (program->disorder < 0.2)
		simple_algorithm(program, bench);
	else if (0.2 <= program->disorder && program->disorder < 0.5)
		medium_algorithm(program, bench);
	else if (program->disorder >= 0.5)
		complex_algorithm(program, bench);
}
