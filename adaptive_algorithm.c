/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adaptive_algorithm.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mairuiz <mairuiz@student.42urduliz.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/11 15:47:01 by mairuiz           #+#    #+#             */
/*   Updated: 2026/07/12 13:09:26 by mairuiz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	adaptive_algorithm(t_stack *a, t_stack *b, t_benchmark *ben, float dis)
{
	if (dis < 0.2)
		simple_algorithm(a, b, ben);
	else if (0.2 <= dis || dis < 0.5)
		medium_algorithm(a, b, ben);
	else if (dis >= 0.5)
		complex_algorithm(a, b, ben);
}
