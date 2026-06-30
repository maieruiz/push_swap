/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mairuiz <mairuiz@student.42urduliz.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/06 19:22:01 by mairuiz           #+#    #+#             */
/*   Updated: 2026/06/29 16:23:12 by mairuiz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t	i;
	size_t	j;

	if (!*s2)
		return ((char *)s1);
	i = 0;
	while (s1[i] && n > i)
	{
		j = 0;
		while (s1[i + j] == s2[j] && n > (i + j) && s2[j])
			j++;
		if (!s2[j])
			return ((char *)&s1[i]);
		i++;
	}
	return (0);
}
