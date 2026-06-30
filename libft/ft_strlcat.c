/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mairuiz <mairuiz@student.42urduliz.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/06 19:22:32 by mairuiz           #+#    #+#             */
/*   Updated: 2026/06/29 16:22:53 by mairuiz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	ld;
	size_t	ls;
	size_t	i;
	size_t	j;

	ld = ft_strlen((char *)dst);
	ls = ft_strlen((char *)src);
	if (size == 0)
		return (ls);
	if (size <= ld)
		return (size + ls);
	i = 0;
	j = ld;
	while (src[i] && size - 1 > j)
	{
		dst[j] = src[i];
		j++;
		i++;
	}
	dst[j] = 0;
	return (ld + ls);
}
