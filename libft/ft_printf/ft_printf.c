/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mairuiz <mairuiz@student.42urduliz.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/08 19:22:49 by mairuiz           #+#    #+#             */
/*   Updated: 2026/07/12 15:46:54 by mairuiz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_convert(int fd, char s, va_list args)
{
	int				ret;
	unsigned long	phelp;

	ret = 0;
	phelp = 0;
	if (s == 'c')
		ret = ft_putchar(fd, va_arg(args, int));
	else if (s == 's')
		ret = ft_putstr(fd, va_arg(args, char *));
	else if (s == 'p')
	{
		phelp = (unsigned long)va_arg(args, void *);
		if (phelp != 0)
			ret += ft_putstr(fd, "0x");
		ret += ft_puthex(fd, phelp, 'p');
	}
	else if (s == 'd' || s == 'i')
		ret = ft_putnbr(fd, va_arg(args, int));
	else if (s == 'u')
		ret = ft_putunsigned(fd, va_arg(args, unsigned int));
	else if (s == 'x' || s == 'X')
		ret = ft_puthex(fd, (unsigned long)va_arg(args, unsigned int), s);
	else if (s == '%')
		ret = ft_putchar(fd, '%');
	return (ret);
}

int	ft_printf(int fd, char const *s, ...)
{
	va_list	args;
	int		i;
	int		total;

	i = 0;
	total = 0;
	if (!s)
		return (-1);
	va_start(args, s);
	while (s[i])
	{
		if (s[i] == '%')
		{
			i++;
			total += ft_convert(fd, s[i], args);
			i++;
		}
		else
		{
			total += ft_putchar(fd, s[i]);
			i++;
		}
	}
	va_end(args);
	return (total);
}
