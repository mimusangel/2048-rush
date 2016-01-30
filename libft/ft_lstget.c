/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstget.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgallo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/04 12:55:31 by mgallo            #+#    #+#             */
/*   Updated: 2015/12/11 14:31:48 by mgallo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstget(t_list **alst, size_t index)
{
	size_t	i;

	i = 0;
	while (*alst)
	{
		if (i == index)
			return (*alst);
		i++;
		*alst = (*alst)->next;
	}
	return (NULL);
}
