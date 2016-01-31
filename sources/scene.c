/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgallo <mgallo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/30 13:23:34 by mgallo            #+#    #+#             */
/*   Updated: 2016/01/30 15:48:57 by mgallo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ncurses.h>
#include <libft.h>
#include <stdlib.h>
#include "game.h"

static void	render_game(t_game *game)
{
	char	*score;

	score = ft_itoa(game->win_value);
	mvprintw(0, 5, "but:");
	mvprintw(0, 10, score);
	free(score);
	score = ft_itoa(game->score);
	mvprintw(0, COLS - (COLS / 4) - 1, "Score:");
	mvprintw(0, COLS - (COLS / 4) + 6, score);
	render_grid(game, COLS, LINES - 1);
	free(score);
}

static void	render_main(t_game *game)
{
	draw_borders(2, 2, COLS - 4, LINES - 4);
	mvprintw(5, COLS / 2 - 3, "2048");
	mvprintw(7, COLS / 2 - 4, " JOUER ");
	mvprintw(8, COLS / 2 - 4, "QUITTER");
	mvprintw(7 + game->cursor, COLS / 2 - 7, ">");
	mvprintw(7 + game->cursor, COLS / 2 + 5, "<");
}

static void	render_win(t_game *game)
{
	draw_borders(2, 2, COLS - 4, LINES - 4);
	mvprintw(5, COLS / 2 - 3, "2048");
	mvprintw(7, COLS / 2 - 5, "CONTINUER");
	mvprintw(8, COLS / 2 - 5, " REJOUER ");
	mvprintw(9, COLS / 2 - 5, " QUITTER ");
	mvprintw(7 + game->cursor, COLS / 2 - 8, ">");
	mvprintw(7 + game->cursor, COLS / 2 + 6, "<");
}

static void	render_lose(t_game *game)
{
	draw_borders(2, 2, COLS - 4, LINES - 4);
	mvprintw(5, COLS / 2 - 3, "2048");
	mvprintw(7, COLS / 2 - 4, "REJOUER");
	mvprintw(8, COLS / 2 - 4, "QUITTER");
	mvprintw(7 + game->cursor, COLS / 2 - 7, ">");
	mvprintw(7 + game->cursor, COLS / 2 + 5, "<");
}

void		render_scene(t_game *game)
{
	if (game->scene == IN_GAME)
		check(game);
	if (game->scene == MENU_MAIN)
		render_main(game);
	else if (game->scene == IN_GAME)
		render_game(game);
	else if (game->scene == MENU_WIN)
		render_win(game);
	else if (game->scene == MENU_LOSE)
		render_lose(game);
}
