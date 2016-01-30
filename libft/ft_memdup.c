/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgallo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/03 17:59:47 by mgallo            #+#    #+#             */
/*   Updated: 2015/12/03 18:03:16 by mgallo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memdup(const void *s1, size_t len)
{
	void	*ret;

	ret = ft_memalloc(len);
	if (!ret)
		ft_memcpy(ret, s1, len);
	return (ret);
}
