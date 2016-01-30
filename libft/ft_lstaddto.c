/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstaddto.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgallo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/04 10:05:08 by mgallo            #+#    #+#             */
/*   Updated: 2015/12/04 10:44:14 by mgallo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_lstaddto(t_list **alst, t_list *new, size_t index)
{
	size_t	i;
	t_list	*lst;

	i = 0;
	lst = *alst;
	while (i++ < index && lst)
		if (i < index && lst->next)
			lst = lst->next;
	new->next = lst->next;
	lst->next = new;
	return (i);
}
