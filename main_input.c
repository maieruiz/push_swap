/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mairuiz <mairuiz@student.42urduliz.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/28 11:36:54 by mairuiz           #+#    #+#             */
/*   Updated: 2026/06/28 14:37:29 by mairuiz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdio.h>
#include <unistd.h>

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
	if ((!s1[i] && s2[i] )|| (!s2[i] && s1[i]))
		return (1);
	return (0);
}

int	correct_stack(int num, char **argv)
{
	if (ft_strcmp(argv[num], "1") == 0)
		return (1);
	return (0);
}



int	select_strategy(char *argv)
{
	if (ft_strcmp(argv, "--simple") == 0 || ft_strcmp(argv, "--medium") == 0 
		|| ft_strcmp(argv, "--complex") == 0)
		return (1);
	return (0);
}

int	check_args(int argc, char **argv)
{
	int	ret;

	ret = 0;
	if (argc == 1)
		return (ret);
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
			ret = 23;
	}
	else if (correct_stack(1, argv) == 1)//check stack
		ret = 3;
	return (ret);
}

int	main(int argc, char **argv)
{
	printf("%i\n", check_args(argc, argv));
}