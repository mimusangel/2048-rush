/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgallo <mgallo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/30 13:55:13 by mgallo            #+#    #+#             */
/*   Updated: 2016/01/30 15:47:19 by mgallo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

static void	control_main(t_game *game, int key)
{
	if (key == UP)
		game->cursor -= 1;
	if (key == DOWN)
		game->cursor += 1;
	game->cursor = game->cursor % 2;
	if (game->cursor < 0)
		game->cursor = 2 + game->cursor;
	if (key == ENTER)
	{
		if (game->cursor == 0)
			game->scene = IN_GAME;
		if (game->cursor == 1)
			game->end = 1;
	}
}

static void	control_game(t_game *game, int key)
{
	if (key == RESET)
		reset_game(game);
	if (key == UP)
		up(game);
	if (key == DOWN)
		down(game);
	if (key == LEFT)
		left(game);
	if (key == RIGHT)
		right(game);
}

static void	control_win(t_game *game, int key)
{
	if (key == UP)
		game->cursor -= 1;
	if (key == DOWN)
		game->cursor += 1;
	game->cursor = game->cursor % 3;
	if (game->cursor < 0)
		game->cursor = 3 + game->cursor;
	if (key == ENTER)
	{
		if (game->cursor == 0)
			game->scene = IN_GAME;
		if (game->cursor == 1)
		{
			reset_game(game);
			game->scene = IN_GAME;
		}
		if (game->cursor == 2)
			game->end = 1;
	}
}

static void	control_lose(t_game *game, int key)
{
	if (key == UP)
		game->cursor -= 1;
	if (key == DOWN)
		game->cursor += 1;
	game->cursor = game->cursor % 2;
	if (game->cursor < 0)
		game->cursor = 2 + game->cursor;
	if (key == ENTER)
	{
		if (game->cursor == 0)
		{
			reset_game(game);
			game->scene = IN_GAME;
		}
		if (game->cursor == 1)
			game->end = 1;
	}
}

void		control(t_game *game, int key)
{
	if (game->scene == MENU_MAIN)
		control_main(game, key);
	else if (game->scene == IN_GAME)
		control_game(game, key);
	else if (game->scene == MENU_WIN)
		control_win(game, key);
	else if (game->scene == MENU_LOSE)
		control_lose(game, key);
}
