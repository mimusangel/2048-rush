/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgallo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 11:54:38 by mgallo            #+#    #+#             */
/*   Updated: 2015/12/16 11:06:47 by mgallo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *nlst;
	t_list *next;

	if (!lst || !f)
		return (NULL);
	nlst = (*f)(lst);
	if (nlst)
	{
		next = nlst;
		lst = lst->next;
		while (lst)
		{
			next->next = (*f)(lst);
			if (!(next->next))
				return (NULL);
			next = next->next;
			lst = lst->next;
		}
	}
	return (nlst);
}
