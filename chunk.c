/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mairuiz <mairuiz@student.42urduliz.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/11 18:59:14 by mairuiz           #+#    #+#             */
/*   Updated: 2026/07/12 13:11:07 by mairuiz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	root(int num)
{
	int	i;

	i = 0;
	while (i * i <= num)
		i++;
	return (i - 1);
}

void	next_chunk(t_chunk	*chunk)
{
	chunk->min = chunk->max + 1;
	chunk->max = chunk->max + chunk->chunk_size;
}

t_chunk	*create_chunk(void)
{
	t_chunk	*new_chunk;

	new_chunk = (t_chunk *)malloc(sizeof(t_chunk));
	new_chunk->chunk_size = 0;
	new_chunk->min = 0;
	new_chunk->max = 0;
}

t_chunk	*set_chunk(t_chunk *chunk, int chunk_num)
{
	chunk->chunk_size = root(chunk_num);
	chunk->min = 0;
	chunk->max = chunk->chunk_size - 1;
	return (chunk);
}
