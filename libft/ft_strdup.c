/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mairuiz <mairuiz@student.42urduliz.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/06 19:23:02 by mairuiz           #+#    #+#             */
/*   Updated: 2026/06/29 16:22:44 by mairuiz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*r;
	int		ls;

	ls = ft_strlen(s);
	r = malloc(ls + 1);
	if (!r)
		return (0);
	r = ft_memcpy((void *)r, (void *)s, ls);
	r[ls] = 0;
	return (r);
}
