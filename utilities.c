/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarlasc <amarlasc@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/06 16:48:09 by amarlasc          #+#    #+#             */
/*   Updated: 2026/07/06 16:53:47 by amarlasc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	i;

	i = 0;
	while (s1[i] && s2[i])
	{
		if (s1[i] != s2[i])
			return (1);
		i++;
	}
	if ((!s1[i] && s2[i]) || (!s2[i] && s1[i]))
		return (1);
	return (0);
}

int	is_valid_number(char *str)
{
	int	i;

	i = 0;
	if (!str || !str[i])
		return (0);
	if (str[i] == '+' || str[i] == '-')
		i++;
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

int	count_args(char	**argv)
{
	int	i;

	i = 0;
	while (argv[i])
		i++;
	return (i);
}

long	ft_atol(char *str)
{
	long	nums;
	int		i;
	long	sign;

	i = 0;
	sign = 1;
	nums = 0;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i])
	{
		nums = nums * 10 + (str[i] - '0');
		i++;
	}
	return (nums * sign);
}
