/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgallo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 13:44:22 by mgallo            #+#    #+#             */
/*   Updated: 2015/12/11 18:36:26 by mgallo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	size;

	i = 0;
	while (dst[i] && i < dstsize)
		i++;
	size = i;
	while (src[i - size] && i < dstsize - 1)
	{
		dst[i] = src[i - size];
		i++;
	}
	if (size < dstsize)
		dst[i] = '\0';
	return (size + ft_strlen(src));
}
