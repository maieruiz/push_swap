/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nosedondemeterlo.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mairuiz <mairuiz@student.42urduliz.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/02 20:36:30 by mairuiz           #+#    #+#             */
/*   Updated: 2026/07/02 20:37:03 by mairuiz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	call_algorithm(char strategy)
{
	if (strategy == 's')
		simple_algorithm();
	else if (strategy == 'm')
		medium_algorithm();
	else if (strategy == 'c')
		complex_algorithm();
	else
		adaptive_algorithm();
}