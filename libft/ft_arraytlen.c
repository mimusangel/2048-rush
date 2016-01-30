/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arraytlen.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgallo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/03 15:53:26 by mgallo            #+#    #+#             */
/*   Updated: 2015/12/03 16:25:00 by mgallo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_arraytlen(char **array)
{
	size_t	len;

	len = 0;
	while (*array)
	{
		len += ft_strlen(*array);
		array++;
	}
	return (len);
}
