/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgallo <mgallo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/30 15:27:09 by mgallo            #+#    #+#             */
/*   Updated: 2016/01/30 15:47:14 by mgallo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

int		is_pow2(int v)
{
	int i;

	i = 0;
	while (++i < 32)
	{
		if (v == (1 << i))
			return (1);
	}
	return (0);
}
