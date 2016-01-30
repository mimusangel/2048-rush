/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgallo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 13:44:22 by mgallo            #+#    #+#             */
/*   Updated: 2015/12/16 01:13:12 by mgallo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*s1;
	size_t			i;
	unsigned char	cmp;

	i = 0;
	s1 = (unsigned char *)s;
	cmp = (unsigned char)c;
	while (i < n)
	{
		if (s1[i] == cmp)
			return (s1 + i);
		i++;
	}
	return (0);
}
