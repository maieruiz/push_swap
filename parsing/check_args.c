/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarlasc <amarlasc@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/28 11:36:54 by mairuiz           #+#    #+#             */
/*   Updated: 2026/07/06 16:46:38 by amarlasc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	correct_stack(char **argv)
{
	long	*nums;
	int		count;

	if (!argv)
		return (0);
	count = count_args(argv);
	if (!validate_format(argv))
		return (0);
	nums = convert_to_long(argv);
	if (!nums)
		return (0);
	if (!check_int_limits(nums, count))
	{
		free (nums);
		return (0);
	}
	if (!check_duplicates(nums, count))
	{
		free(nums);
		return (0);
	}
	free (nums);
	return (1);
}

static int	select_strategy(char *argv)
{
	if (ft_strcmp(argv, "--simple") == 0 || ft_strcmp(argv, "--medium") == 0
		|| ft_strcmp(argv, "--complex") == 0
		|| ft_strcmp(argv, "--adaptive") == 0)
		return (1);
	return (0);
}

int	check_args(int argc, char **argv)
{
	int	ret;

	ret = -1;
	if (argc == 1)
		return (0);
	if (ft_strcmp(argv[1], "--bench") == 0 && argc > 2)
	{
		if (select_strategy(argv[2]) == 1 && argc > 3)
		{
			if (correct_stack(argv + 3) == 1)
				ret = 321;
		}
		else if (correct_stack(argv + 2) == 1)
			ret = 31;
	}
	else if (select_strategy(argv[1]) == 1)
	{
		if (correct_stack(argv + 2) == 1)
			ret = 32;
	}
	else if (correct_stack(argv + 1) == 1)
		ret = 3;
	return (ret);
}
