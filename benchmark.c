/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   benchmark.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mairuiz <mairuiz@student.42urduliz.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
<<<<<<< HEAD
/*   Created: 2026/07/08 15:02:38 by amarlasc          #+#    #+#             */
/*   Updated: 2026/07/12 13:10:37 by mairuiz          ###   ########.fr       */
=======
/*   Created: 2026/07/05 23:47:50 by mairuiz           #+#    #+#             */
/*   Updated: 2026/07/05 23:59:28 by mairuiz          ###   ########.fr       */
>>>>>>> e9a1d646e49110b06bca91ba7f711d04226ec913
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

<<<<<<< HEAD
t_benchmark	*create_benchmark(void)
=======
t_benchmark	*crete_benchmark(void)
>>>>>>> e9a1d646e49110b06bca91ba7f711d04226ec913
{
	t_benchmark	*benchmark;

	benchmark = (t_benchmark *)malloc(sizeof(t_benchmark));
	if (!benchmark)
		return (NULL);
	benchmark->disorder = 0.0;
	benchmark->strategy = 0;
	benchmark->total_ops = 0;
	benchmark->sa = 0;
	benchmark->sb = 0;
	benchmark->ss = 0;
	benchmark->pb = 0;
	benchmark->pa = 0;
	benchmark->ra = 0;
	benchmark->rb = 0;
	benchmark->rr = 0;
	benchmark->rra = 0;
	benchmark->rrb = 0;
	benchmark->rrr = 0;
<<<<<<< HEAD
	return (benchmark);
=======
>>>>>>> e9a1d646e49110b06bca91ba7f711d04226ec913
}

void	set_benchmark(t_benchmark *benchmark, t_program *program)
{
	benchmark->disorder = program->disorder;
	if (program->strategy == 's')
		benchmark->strategy = "Simple";
	else if (program->strategy == 'm')
		benchmark->strategy = "Medium";
	else if (program->strategy == 'c')
		benchmark->strategy = "Complex";
	else if (program->strategy == 'a')
		benchmark->strategy = "Adaptive";
}

void	printf_benchmark(t_benchmark *bench)
{
<<<<<<< HEAD
	ft_putstr_fd("[bench] disorder: ", 2);
	ft_putstr_fd(".", 2);
	ft_putendl_fd("%\n", 2);
	ft_putstr_fd("[bench] strategy: ", 2);
	ft_putendl_fd(&bench->strategy, 2);
	ft_putendl_fd("\n", 2);
	ft_putstr_fd("[bench] total_ops: ", 2);
	ft_putnbr_fd(bench->total_ops, 2);
	
=======
>>>>>>> e9a1d646e49110b06bca91ba7f711d04226ec913
}
