/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arraytostr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgallo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/08 14:51:05 by mgallo            #+#    #+#             */
/*   Updated: 2015/12/11 14:31:28 by mgallo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_arraytostr(char **str, char c)
{
	char	*s;
	size_t	i;
	size_t	len;

	i = 0;
	len = ft_arraytlen(str) + (ft_arraylen(str) - 1);
	s = ft_strnew(len);
	if (!str)
		return (NULL);
	while (*str)
	{
		ft_strcpy(s + i, *str);
		i += ft_strlen(*str);
		if (i < len)
			s[i++] = c;
		str++;
	}
	return (s);
}
