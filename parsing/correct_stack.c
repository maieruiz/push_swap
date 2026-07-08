/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   correct_stack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarlasc <amarlasc@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/06 16:05:07 by amarlasc          #+#    #+#             */
/*   Updated: 2026/07/06 17:18:02 by amarlasc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	validate_format(char **argv)
{
	int	i;

	i = 0;
	if (!argv)
		return (0);
	while (argv[i])
	{
		if (!is_valid_number(argv[i]))
			return (0);
		i++;
	}
	return (1);
}

long	*convert_to_long(char **argv)
{
	int		count;
	int		i;
	long	*nums;

	i = 0;
	count = count_args(argv);
	nums = malloc(count * sizeof (long));
	if (!nums)
		return (NULL);
	while (argv[i])
	{
		nums[i] = ft_atol(argv[i]);
		i++;
	}
	return (nums);
}

int	check_int_limits(long *nums, int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		if (nums[i] < INT_MIN)
			return (0);
		if (nums[i] > INT_MAX)
			return (0);
		i++;
	}
	return (1);
}

int	check_duplicates(long *nums, int count)
{
	int	i;
	int	j;

	i = 0;
	while (i < count)
	{
		j = i + 1;
		while (j < count)
		{
			if (nums[i] == nums[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
