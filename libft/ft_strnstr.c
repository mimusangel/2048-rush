/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgallo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 13:44:23 by mgallo            #+#    #+#             */
/*   Updated: 2015/12/15 22:50:11 by mgallo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *search, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (str[i] && i < len)
	{
		j = 0;
		while (search[j])
		{
			if (i + j >= len)
				return (0);
			if (str[i + j] && str[i + j] != search[j])
				break ;
			else
				j++;
		}
		if (!search[j])
			return ((char *)str + i);
		i++;
	}
	return (0);
}
