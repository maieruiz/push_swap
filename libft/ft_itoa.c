/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mairuiz <mairuiz@student.42urduliz.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/06 10:15:58 by mairuiz           #+#    #+#             */
/*   Updated: 2026/06/29 16:21:11 by mairuiz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_intlen(long num)
{
	int	count;

	count = 0;
	if (num < 0)
	{
		count++;
		num = -num;
	}
	if (num == 0)
		count++;
	while (num != 0)
	{
		num = num / 10;
		count++;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	int		len;
	int		i;
	char	*p;
	long	num;

	num = n;
	len = ft_intlen(num);
	p = malloc ((len + 1) * sizeof(char));
	if (!p)
		return (NULL);
	if (num < 0)
		num = -num;
	i = len - 1;
	if (num == 0)
		p[0] = '0';
	while (num != 0)
	{
		p[i] = ((num % 10) + '0');
		num = num / 10;
		i--;
	}
	if (n < 0)
		p[0] = '-';
	p[len] = 0;
	return (p);
}
