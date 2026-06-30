/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mairuiz <mairuiz@student.42urduliz.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/02 16:29:06 by mairuiz           #+#    #+#             */
/*   Updated: 2026/06/29 16:21:56 by mairuiz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*new_nodo;

	new_nodo = (t_list *)malloc(sizeof(t_list));
	if (!new_nodo)
		return (NULL);
	new_nodo->content = content;
	new_nodo->next = NULL;
	return (new_nodo);
}
