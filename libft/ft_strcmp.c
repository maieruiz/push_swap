/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mairuiz <mairuiz@student.42urduliz.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/02 15:51:45 by mairuiz           #+#    #+#             */
/*   Updated: 2026/07/02 23:17:44 by mairuiz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	i;

	i = 0;
	if (ft_strlen(s1) != ft_strlen(s2))
		return (-1);
	while (s1[i] && s2[i])
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return (0);
}

/*
int	main(void)
{
	printf("1: %i\n", ft_strcmp("salut", "salut"));
	printf("2: %i\n", ft_strcmp("test", "testss"));
	printf("3: %i\n", ft_strcmp("testss", "test"));
	printf("4: %i\n", ft_strcmp("test", "tEst"));
	printf("5: %i\n", ft_strcmp("", "test"));
	printf("6: %i\n", ft_strcmp("test", ""));
	printf("7: %i\n", ft_strcmp("abcdefghij", "abcdefgxyz"));
	printf("8: %i\n", ft_strcmp("abcdefgh", "abcdwxyz"));
	printf("9: %i\n", ft_strcmp("zyxbcdefgh", "abcdwxyz"));
	printf("10: %i\n", ft_strcmp("abcdefgh", ""));
	printf("11: %i\n", ft_strcmp("test\200", "test\0"));
}
*/