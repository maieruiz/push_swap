/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mairuiz <mairuiz@student.42urduliz.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/28 11:36:54 by mairuiz           #+#    #+#             */
/*   Updated: 2026/06/30 18:11:42 by mairuiz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_strcmp(const char *s1, const char *s2)
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

static int	valid_int(char *str)
{
	
}

static int	correct_stack(int num, char **argv)
{
	while (argv[num])
	{
		
	}
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
			if (correct_stack(3, argv) == 1)
				ret = 321;
		}
		else if (correct_stack(2, argv) == 1)
			ret = 31;
	}
	else if (select_strategy(argv[1]) == 1)
	{
		if (correct_stack(2, argv) == 1)
			ret = 32;
	}
	else if (correct_stack(1, argv) == 1)
		ret = 3;
	return (ret);
}

/*int	main(int argc, char **argv)
{
	int 	i = check_args(argc, argv);
	if (i == 0)
		return (0);
	else if (i == -1)
		printf("Error\n");
	else
	printf("%i\n", i);
}*/