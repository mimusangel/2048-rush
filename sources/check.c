/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c 		                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgallo <mgallo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/30 14:31:52 by mgallo            #+#    #+#             */
/*   Updated: 2016/01/30 15:48:05 by mgallo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

static int	check_moveto(t_game *game, int x, int y, t_point *dir)
{
	if (x + dir->x < 0 || y + dir->y < 0
		|| x + dir->x >= game->size || y + dir->y >= game->size)
		return (0);
	if (game->grid[y][x] == 0)
		return (0);
	if (game->grid[y + dir->y][x + dir->x] == 0)
		return (1);
	else if (game->grid[y + dir->y][x + dir->x] == game->grid[y][x])
		return (1);
	return (0);
}

static int	check_dir(t_game *game, t_point *dir)
{
	int x;
	int y;

	x = -1;
	while (++x < game->size)
	{
		y = -1;
		while (++y < game->size)
		{
			if (check_moveto(game, x, y, dir))
				return (1);
		}
	}
	return (0);
}

void		check(t_game *game)
{
	t_point dir;

	dir.x = -1;
	dir.y = 0;
	if (check_dir(game, &dir))
		return ;
	dir.x = 1;
	if (check_dir(game, &dir))
		return ;
	dir.x = 0;
	dir.y = -1;
	if (check_dir(game, &dir))
		return ;
	dir.y = 1;
	if (check_dir(game, &dir))
		return ;
	game->scene = MENU_LOSE;
}
