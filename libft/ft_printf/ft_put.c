/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mairuiz <mairuiz@student.42urduliz.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/09 14:09:22 by mairuiz           #+#    #+#             */
/*   Updated: 2026/06/05 11:12:12 by mairuiz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(int c)
{
	return (write (1, &c, 1));
}

int	ft_putstr(char *s)
{
	int	i;
	int	ret;

	ret = 0;
	i = 0;
	if (!s)
		return (write (1, "(null)", 6));
	while (s[i])
	{
		ret += ft_putchar(s[i]);
		i++;
	}
	return (ret);
}

int	ft_putunsigned(unsigned int n)
{
	int	ret;

	ret = 0;
	if (n >= 10)
		ret += ft_putunsigned(n / 10);
	ret += ft_putchar(n % 10 + '0');
	return (ret);
}

int	ft_putnbr(int n)
{
	int		ret;
	long	nb;

	ret = 0;
	nb = n;
	if (nb < 0)
	{
		ret += ft_putchar('-');
		nb = -nb;
	}
	if (nb >= 10)
		ret += ft_putnbr(nb / 10);
	ret += ft_putchar(nb % 10 + 48);
	return (ret);
}

int	ft_puthex(unsigned long un, char format)
{
	char	*base;
	int		ret;

	if (format == 'p' && un == 0)
	{
		ret = ft_putstr("(nil)");
		return (ret);
	}
	if (format == 'X')
		base = "0123456789ABCDEF";
	else
		base = "0123456789abcdef";
	ret = 0;
	if (un >= 16)
		ret += ft_puthex(un / 16, format);
	ret += ft_putchar(base[un % 16]);
	return (ret);
}
