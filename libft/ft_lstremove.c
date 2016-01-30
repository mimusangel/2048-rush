/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstremove.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgallo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/04 10:57:19 by mgallo            #+#    #+#             */
/*   Updated: 2015/12/11 14:32:29 by mgallo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_lstremove(t_list **alst, size_t index)
{
	size_t	i;
	t_list	*tmp;

	i = 0;
	while (*alst)
	{
		i++;
		if (i == index)
			break ;
		else
			*alst = (*alst)->next;
	}
	if (i == index && (*alst)->next)
	{
		tmp = (*alst)->next;
		(*alst)->next = tmp->next;
		free(tmp);
	}
}
