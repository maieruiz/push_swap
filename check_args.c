/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mairuiz <mairuiz@student.42urduliz.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/28 11:36:54 by mairuiz           #+#    #+#             */
/*   Updated: 2026/07/19 11:00:23 by mairuiz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	correct_stack(char **argv)
{
	long	*nums;
	int		count;

	if (!argv)
		return (-1);
	count = count_args(argv);
	if (!validate_format(argv))
		return (-1);
	nums = convert_to_long(argv);
	if (!nums)
		return (-1);
	if (!check_int_limits(nums, count))
	{
		free (nums);
		return (-1);
	}
	if (!check_duplicates(nums, count))
	{
		free(nums);
		return (-1);
	}
	free (nums);
	return (1);
}

static int	correct_flag(char	*argv, t_program *program)
{
	if (ft_strcmp(argv, "--bench") == 0)
		program->flag->bench = 1;
	else if (ft_strcmp(argv, "--simple") == 0)
		program->flag->strategy = 's';
	else if (ft_strcmp(argv, "--medium") == 0)
		program->flag->strategy = 'm';
	else if (ft_strcmp(argv, "--complex") == 0)
		program->flag->strategy = 'c';
	else if (ft_strcmp(argv, "--adaptive") == 0)
		program->flag->strategy = 'a';
	else
		return (-1);
	return (1);
}

int	check_args(int argc, char **argv, t_program *program)
{
	int	ret;
	int	i;

	i = 1;
	ret = 1;
	while (argv[i][0] == '-' && argv[i][1] == '-' && ret == 1)
	{
		ret = correct_flag(argv[i], program);
		i++;
	}
	if (ret == -1)
		return (ret);
	if (correct_stack(argv + i) == 1)
	{
		program->a = fill_stack(i, argc, argv, program->a);
	}
	else
		return (-1);
	program->disorder = compute_disorder(program->a);
	return (ret);
}
