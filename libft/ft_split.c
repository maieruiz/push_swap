/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mairuiz <mairuiz@student.42urduliz.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/26 10:21:07 by mairuiz           #+#    #+#             */
/*   Updated: 2026/06/29 16:22:39 by mairuiz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_word_count(char const *s, char c)
{
	int		w_count;
	int		m;

	w_count = 0;
	m = 0;
	while (*s)
	{
		if (*s != c && m == 0)
		{
			w_count++;
			m = 1;
		}
		else if (*s == c)
			m = 0;
		s++;
	}
	return (w_count);
}

static char	*ft_fill_word(char	*s, int start, int end)
{
	char	*z;
	int		i;

	i = 0;
	z = malloc((end - start + 1) + 1);
	if (!z)
		return (NULL);
	while (start <= end)
	{
		z[i] = s[start];
		start++;
		i++;
	}
	z[i] = 0;
	return (z);
}

static void	*ft_free(char **strs, int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		free(strs[i]);
		i++;
	}
	free(strs);
	return (NULL);
}

static char	**ft_fill_array(char	**p, int w_count, char c, char const *s)
{
	int	i;
	int	j;
	int	start;

	start = 0;
	i = 0;
	j = 0;
	while (w_count > 0)
	{
		while (s[i] && s[i] == c)
			i++;
		start = i;
		while (s[i] && s[i] != c)
			i++;
		p[j] = ft_fill_word((char *)s, start, i - 1);
		if (!p[j])
			return (ft_free(p, j));
		w_count--;
		j++;
	}
	p[j] = 0;
	return (p);
}

char	**ft_split(char const *s, char c)
{
	char	**p;
	int		w_count;

	if (!s)
		return (NULL);
	w_count = ft_word_count(s, c);
	p = (char **)ft_calloc(w_count + 1, sizeof(char *));
	if (!p)
		return (NULL);
	return (ft_fill_array(p, w_count, c, s));
}
