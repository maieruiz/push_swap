/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mairuiz <mairuiz@student.42urduliz.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/08 19:22:49 by mairuiz           #+#    #+#             */
/*   Updated: 2026/06/29 16:35:42 by mairuiz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_convert(char s, va_list args)
{
	int				ret;
	unsigned long	phelp;

	ret = 0;
	phelp = 0;
	if (s == 'c')
		ret = ft_putchar(va_arg(args, int));
	else if (s == 's')
		ret = ft_putstr(va_arg(args, char *));
	else if (s == 'p')
	{
		phelp = (unsigned long)va_arg(args, void *);
		if (phelp != 0)
			ret += ft_putstr("0x");
		ret += ft_puthex(phelp, 'p');
	}
	else if (s == 'd' || s == 'i')
		ret = ft_putnbr(va_arg(args, int));
	else if (s == 'u')
		ret = ft_putunsigned(va_arg(args, unsigned int));
	else if (s == 'x' || s == 'X')
		ret = ft_puthex((unsigned long)va_arg(args, unsigned int), s);
	else if (s == '%')
		ret = ft_putchar('%');
	return (ret);
}

int	ft_printf(char const *s, ...)
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
			total += ft_convert(s[i], args);
			i++;
		}
		else
		{
			total += ft_putchar(s[i]);
			i++;
		}
	}
	va_end(args);
	return (total);
}
