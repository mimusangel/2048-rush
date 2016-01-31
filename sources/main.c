/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgallo <mgallo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/30 10:06:56 by mgallo            #+#    #+#             */
/*   Updated: 2016/01/30 15:49:34 by mgallo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ncurses.h>
#include <libft.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include "game.h"

static void		init(t_game *game)
{
	int i;
	int j;

	game->score = 0;
	game->end = 0;
	game->cursor = 0;
	game->size = 4;
	game->scene = MENU_MAIN;
	game->win = 0;
	game->grid = (int **)malloc(sizeof(int *) * game->size);
	game->win_value = is_pow2(WIN_VALUE) ? WIN_VALUE : 2048;
	i = -1;
	while (++i < game->size)
	{
		game->grid[i] = (int *)malloc(sizeof(int) * game->size);
		j = -1;
		while (++j < game->size)
			game->grid[i][j] = 0;
	}
	add_number(game);
	add_number(game);
}

static void		free_game(t_game *game)
{
	int i;

	i = -1;
	while (++i < game->size)
		free(game->grid[i]);
	free(game->grid);
}

void			add_number(t_game *game)
{
	int i;
	int j;

	i = 0;
	while (i < 1)
	{
		j = rand() % (game->size * game->size);
		if (game->grid[j / game->size][j % game->size] == 0)
		{
			game->grid[j / game->size][j % game->size] = 1 << (1 + rand() % 2);
			i++;
		}
	}
}

void			reset_game(t_game *game)
{
	int i;
	int j;

	game->score = 0;
	game->win = 0;
	i = -1;
	while (++i < game->size)
	{
		j = -1;
		while (++j < game->size)
			game->grid[i][j] = 0;
	}
	add_number(game);
	add_number(game);
}

int				main(void)
{
	int		key;
	t_game	game;

	key = 0;
	srand(time(NULL));
	init(&game);
	initscr();
	start_color();
	initialize_color();
	curs_set(0);
	noecho();
	keypad(stdscr, TRUE);
	while (key != ESCAPE && !game.end)
	{
		clear();
		render_scene(&game);
		refresh();
		key = getch();
		control(&game, key);
		usleep(TIME_SLEEP);
	}
	endwin();
	free_game(&game);
	return (0);
}
