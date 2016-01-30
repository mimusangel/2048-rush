/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgallo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 13:44:23 by mgallo            #+#    #+#             */
/*   Updated: 2015/11/26 15:52:27 by mgallo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*ret;
	size_t	i;

	i = 0;
	ret = NULL;
	while (s[i])
	{
		if (s[i] == (char)c)
		{
			ret = (char *)s + i;
		}
		i++;
	}
	if (c == 0)
		return ((char *)s + ft_strlen(s));
	if (!s[i] && !ret)
		return (NULL);
	return (ret);
}
