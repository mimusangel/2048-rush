/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgallo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 15:29:07 by mgallo            #+#    #+#             */
/*   Updated: 2015/12/03 15:02:30 by mgallo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	*ft_memalloc(size_t size)
{
	void *str;

	if (size == 0)
		return (NULL);
	str = malloc(size);
	if (str != NULL)
	{
		ft_bzero(str, size);
		return (str);
	}
	return (NULL);
}
