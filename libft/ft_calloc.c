/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mairuiz <mairuiz@student.42urduliz.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/24 20:56:14 by mairuiz           #+#    #+#             */
/*   Updated: 2026/06/29 16:23:52 by mairuiz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t num, size_t size)
{
	void	*s;

	if (size != 0 && ((num * size) / size) != (num))
		return (NULL);
	s = malloc(num * size);
	if (!s)
		return (NULL);
	ft_memset(s, 0, num * size);
	return (s);
}
