/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grid.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgallo <mgallo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/30 11:19:11 by mgallo            #+#    #+#             */
/*   Updated: 2016/01/30 15:50:27 by mgallo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ncurses.h>
#include "game.h"
#include <libft.h>
#include <stdlib.h>

void		draw_borders(int x, int y, int w, int h)
{
	int i;

	mvprintw(y, x, "+");
	mvprintw(y + h, x, "+");
	mvprintw(y, x + w, "+");
	mvprintw(y + h, x + w, "+");
	i = 0;
	while (++i < h)
	{
		mvprintw(y + i, x, "|");
		mvprintw(y + i, x + w, "|");
	}
	i = 0;
	while (++i < w)
	{
		mvprintw(y, x + i, "-");
		mvprintw(y + h, x + i, "-");
	}
}

static void	draw_value(t_game *game, t_point *p, int w, int h)
{
	int		x;
	int		y;
	char	*str;

	if (game->grid[p->y][p->x] == 0)
		return ;
	str = ft_itoa(game->grid[p->y][p->x]);
	x = p->x * w + w / 2 - ft_strlen(str) / 2;
	y = p->y * h + h / 2 + 1;
	attron(COLOR_PAIR(get_color(game->grid[p->y][p->x])));
	mvprintw(y, x, str);
	attroff(COLOR_PAIR(get_color(game->grid[p->y][p->x])));
}

void		render_grid(t_game *game, int w, int h)
{
	int		i;
	int		x;
	int		y;
	t_point	p;

	w = (w / game->size);
	h = (h / game->size);
	i = -1;
	while (++i < game->size * game->size)
	{
		p.x = (i % game->size);
		p.y = (i / game->size);
		x = p.x * w;
		y = p.y * h;
		draw_borders(x, y + 1, w, h);
		draw_value(game, &p, w, h);
	}
}
