/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mairuiz <mairuiz@student.42urduliz.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/24 17:39:14 by mairuiz           #+#    #+#             */
/*   Updated: 2026/07/02 23:17:55 by mairuiz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (n > i && s1[i] && s2[i])
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	if (i < n)
		return ((unsigned char)s1[i] - (unsigned char)s2[i]);
	return (0);
}

/* int	main(void)
{
	printf("1: %i\n", ft_strncmp("salut", "salut", 5));
	printf("2: %i\n", ft_strncmp("test", "testss", 7));
	printf("3: %i\n", ft_strncmp("testss", "test", 7));
	printf("4: %i\n", ft_strncmp("test", "tEst", 4));
	printf("5: %i\n", ft_strncmp("", "test", 4));
	printf("6: %i\n", ft_strncmp("test", "", 4));
	printf("7: %i\n", ft_strncmp("abcdefghij", "abcdefgxyz", 3));
	printf("8: %i\n", ft_strncmp("abcdefgh", "abcdwxyz", 4));
	printf("9: %i\n", ft_strncmp("zyxbcdefgh", "abcdwxyz", 0));
	printf("10: %i\n", ft_strncmp("abcdefgh", "", 0));
	printf("11: %i\n", ft_strncmp("test\200", "test\0", 6));
} */