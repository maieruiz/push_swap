<<<<<<< HEAD
#include <stdio.h>
#include <math.h>
=======
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mairuiz <mairuiz@student.42urduliz.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/23 18:15:58 by amarlasc          #+#    #+#             */
/*   Updated: 2026/07/02 23:22:53 by mairuiz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
>>>>>>> e9a1d646e49110b06bca91ba7f711d04226ec913

int	root(int num)
{
	int	i;

	i = 0;
	while (i * i <= num)
		i++;
	return (i - 1);
}

int	main(void)
{
	printf("root: %i\n", root(100));
	printf("root: %i\n", (int)sqrt(100));
	printf("root: %i\n", root(0));
	printf("root: %i\n", (int)sqrt(0));
	printf("root: %i\n", root(2));
	printf("root: %i\n", (int)sqrt(2));
	printf("root: %i\n", root(4));
	printf("root: %i\n", (int)sqrt(4));
	printf("root: %i\n", root(3));
	printf("root: %i\n", (int)sqrt(3));
	printf("root: %i\n", root(10));
	printf("root: %i\n", (int)sqrt(10));
	printf("root: %i\n", root(9));
	printf("root: %i\n", (int)sqrt(9));
	printf("root: %i\n", root(45));
	printf("root: %i\n", (int)sqrt(45));
	printf("root: %i\n", root(36));
	printf("root: %i\n", (int)sqrt(36));
	printf("root: %i\n", root(35));
	printf("root: %i\n", (int)sqrt(35));
	printf("root: %i\n", root(37));
	printf("root: %i\n", (int)sqrt(37));
}