/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mairuiz <mairuiz@student.42urduliz.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/03 19:16:42 by mairuiz           #+#    #+#             */
/*   Updated: 2026/06/29 16:21:31 by mairuiz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*save;

	if (!lst || !del)
		return ;
	while (*lst)
	{
		save = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = save;
	}
	*lst = NULL;
}
