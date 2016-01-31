/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control_game.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgallo <mgallo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/30 14:31:52 by mgallo            #+#    #+#             */
/*   Updated: 2016/01/30 15:48:05 by mgallo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

static void	moveto(t_game *game, int x, int y, t_point *dir)
{
	if (x + dir->x < 0 || y + dir->y < 0
		|| x + dir->x >= game->size || y + dir->y >= game->size)
		return ;
	if (game->grid[y][x] == 0)
		return ;
	if (game->grid[y + dir->y][x + dir->x] == 0)
	{
		game->grid[y + dir->y][x + dir->x] = game->grid[y][x];
		game->grid[y][x] = 0;
		game->moved += 1;
		moveto(game, x + dir->x, y + dir->y, dir);
	}
	else if (game->grid[y + dir->y][x + dir->x] == game->grid[y][x])
	{
		game->grid[y + dir->y][x + dir->x] += game->grid[y][x];
		game->grid[y][x] = 0;
		game->moved += 1;
		game->score += game->grid[y + dir->y][x + dir->x];
		if (game->grid[y + dir->y][x + dir->x] == game->win_value && !game->win)
		{
			game->win = 1;
			game->scene = MENU_WIN;
		}
	}
}

void		left(t_game *game)
{
	t_point	dir;
	int		x;
	int		y;

	dir.x = -1;
	dir.y = 0;
	x = 0;
	game->moved = 0;
	while (++x < game->size)
	{
		y = -1;
		while (++y < game->size)
			moveto(game, x, y, &dir);
	}
	if (game->moved > 0)
		add_number(game);
}

void		right(t_game *game)
{
	t_point	dir;
	int		x;
	int		y;

	dir.x = 1;
	dir.y = 0;
	x = game->size - 1;
	game->moved = 0;
	while (--x >= 0)
	{
		y = -1;
		while (++y < game->size)
			moveto(game, x, y, &dir);
	}
	if (game->moved > 0)
		add_number(game);
}

void		up(t_game *game)
{
	t_point	dir;
	int		x;
	int		y;

	dir.x = 0;
	dir.y = -1;
	game->moved = 0;
	y = 0;
	while (++y < game->size)
	{
		x = -1;
		while (++x < game->size)
			moveto(game, x, y, &dir);
	}
	if (game->moved > 0)
		add_number(game);
}

void		down(t_game *game)
{
	t_point	dir;
	int		x;
	int		y;

	dir.x = 0;
	dir.y = 1;
	game->moved = 0;
	y = game->size - 1;
	while (--y >= 0)
	{
		x = -1;
		while (++x < game->size)
			moveto(game, x, y, &dir);
	}
	if (game->moved > 0)
		add_number(game);
}
