/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   program.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mairuiz <mairuiz@student.42urduliz.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/08 15:04:06 by amarlasc          #+#    #+#             */
/*   Updated: 2026/07/18 17:34:52 by mairuiz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_flag	*create_flag(void)
{
	t_flag	*flag;

	flag = (t_flag *)malloc(sizeof(t_flag));
	if (!flag)
		return (NULL);
	flag->bench = 0;
	flag->strategy = 'a';
	return (flag);
}

t_program	*create_program(void)
{
	t_program	*program;

	program = (t_program *)malloc(sizeof(t_program));
	if (!program)
		return (NULL);
	program->a = NULL;
	program->b = NULL;
	program->flag = NULL;
	program->a = create_new_stack();
	if (!program->a)
		return (free_program(program), NULL);
	program->b = create_new_stack();
	if (!program->b)
		return (free_program(program), NULL);
	program->flag = create_flag();
	if (!program->flag)
		return (free_program(program), NULL);
	program->disorder = compute_disorder(program->a);
	return (program);
}
