/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarlasc <amarlasc@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/23 18:15:58 by amarlasc          #+#    #+#             */
/*   Updated: 2026/07/06 17:05:09 by amarlasc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

#include <stdio.h>

int main(int argc, char **argv)
{
    int ret;

    ret = check_args(argc, argv);

    printf("check_args() devuelve: %d\n", ret);

    return (0);
}
