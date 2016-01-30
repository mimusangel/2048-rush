/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgallo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 10:39:13 by mgallo            #+#    #+#             */
/*   Updated: 2015/12/15 22:08:17 by mgallo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strtrim(char const *s)
{
	char	*str;
	size_t	len;
	size_t	i;

	if (!s)
		return (ft_strdup(""));
	while (*s == ' ' || *s == '\t' || *s == '\n')
		s++;
	len = ft_strlen(s) - 1;
	if (len <= 0)
		return (ft_strdup(""));
	while (s[len] == ' ' || s[len] == '\t' || s[len] == '\n')
		len--;
	len++;
	if (!(str = (char *)malloc(sizeof(char) * (len + 1))))
		return (ft_strdup(""));
	i = 0;
	while (s[i] && i < len)
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}
