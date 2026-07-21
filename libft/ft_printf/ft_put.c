/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mairuiz <mairuiz@student.42urduliz.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/09 14:09:22 by mairuiz           #+#    #+#             */
/*   Updated: 2026/07/12 15:44:34 by mairuiz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(int fd, int c)
{
	return (write (fd, &c, 1));
}

int	ft_putstr(int fd, char *s)
{
	int	i;
	int	ret;

	ret = 0;
	i = 0;
	if (!s)
		return (write (fd, "(null)", 6));
	while (s[i])
	{
		ret += ft_putchar(fd, s[i]);
		i++;
	}
	return (ret);
}

int	ft_putunsigned(int fd, unsigned int n)
{
	int	ret;

	ret = 0;
	if (n >= 10)
		ret += ft_putunsigned(fd, n / 10);
	ret += ft_putchar(fd, n % 10 + '0');
	return (ret);
}

int	ft_putnbr(int fd, int n)
{
	int		ret;
	long	nb;

	ret = 0;
	nb = n;
	if (nb < 0)
	{
		ret += ft_putchar(fd, '-');
		nb = -nb;
	}
	if (nb >= 10)
		ret += ft_putnbr(fd, nb / 10);
	ret += ft_putchar(fd, nb % 10 + 48);
	return (ret);
}

int	ft_puthex(int fd, unsigned long un, char format)
{
	char	*base;
	int		ret;

	if (format == 'p' && un == 0)
	{
		ret = ft_putstr(fd, "(nil)");
		return (ret);
	}
	if (format == 'X')
		base = "0123456789ABCDEF";
	else
		base = "0123456789abcdef";
	ret = 0;
	if (un >= 16)
		ret += ft_puthex(fd, un / 16, format);
	ret += ft_putchar(fd, base[un % 16]);
	return (ret);
}
