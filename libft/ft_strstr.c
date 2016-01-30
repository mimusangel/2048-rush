/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgallo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 13:44:23 by mgallo            #+#    #+#             */
/*   Updated: 2015/12/15 22:50:46 by mgallo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *str, const char *search)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (!str[0] && !search[0])
		return ((char *)str);
	while (str[i])
	{
		j = 0;
		while (search[j])
		{
			if (str[i + j] != search[j])
				break ;
			j++;
		}
		if (!search[j])
			return ((char *)str + i);
		i++;
	}
	return (0);
}
