/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgallo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 10:39:13 by mgallo            #+#    #+#             */
/*   Updated: 2015/12/15 22:13:57 by mgallo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static size_t	ft_strsplit_count(char const *s, char c)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (s[i] && s[i] == c)
		i++;
	while (s[i])
	{
		while (s[i] && s[i] != c)
			i++;
		while (s[i] && s[i] == c)
			i++;
		count++;
	}
	return (count);
}

static size_t	ft_len_c_stop(char const *s, size_t start, char c)
{
	size_t	count;

	count = 0;
	while (s[start + count] && s[start + count] != c)
	{
		count++;
	}
	return (count);
}

char			**ft_strsplit(char const *s, char c)
{
	size_t	count;
	size_t	i;
	size_t	counter;
	char	**array;

	i = 0;
	if (!s)
		return (NULL);
	count = ft_strsplit_count(s, c);
	if (!(array = (char **)malloc(sizeof(char *) * (count + 1))))
		return (NULL);
	counter = 0;
	while (i < count)
	{
		while (s[counter] && s[counter] == c)
			counter++;
		array[i] = ft_strsub(s, counter, ft_len_c_stop(s, counter, c));
		while (s[counter] && s[counter] != c)
			counter++;
		i++;
	}
	array[i] = 0;
	return (array);
}
