/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putarray_fd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgallo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/03 16:45:48 by mgallo            #+#    #+#             */
/*   Updated: 2015/12/03 17:34:14 by mgallo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putarray_fd(char **array, char sep, int fd)
{
	while (*array)
	{
		ft_putstr_fd(*array, fd);
		if ((array + 1))
			ft_putchar_fd(sep, fd);
		array++;
	}
}
