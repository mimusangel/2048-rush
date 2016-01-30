/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgallo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 10:39:13 by mgallo            #+#    #+#             */
/*   Updated: 2015/12/16 00:51:08 by mgallo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static void	ft_itoa_init(int n, size_t *len, int *sign)
{
	*len = 2;
	*sign = 0;
	if (n < 0)
	{
		n *= -1;
		*sign = 1;
		(*len)++;
	}
	while (n /= 10)
		(*len)++;
}

char		*ft_itoa(int n)
{
	char	*str;
	size_t	len;
	int		sign;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	ft_itoa_init(n, &len, &sign);
	n = (n < 0) ? -n : n;
	str = (char *)malloc(sizeof(char) * len);
	if (!str)
		return (NULL);
	str[--len] = '\0';
	while (len--)
	{
		str[len] = (n % 10) + '0';
		n = n / 10;
	}
	if (sign)
		str[0] = '-';
	return (str);
}
