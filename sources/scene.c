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

	score = ft_itoa(game->score);
	mvprintw(0, COLS - (COLS / 3), "Score:");
	mvprintw(0, COLS - (COLS / 3) + 7, score);
	render_grid(game, COLS, LINES - 1);
	free(score);
}

static void	render_main(t_game *game)
{
	draw_borders(2, 2, COLS - 4, LINES - 4);
	mvprintw(5, COLS / 2 - 2, "2048");
	mvprintw(7, COLS / 2 - 4, " JOUER ");
	mvprintw(8, COLS / 2 - 4, "QUITTER");
	mvprintw(7 + game->cursor, COLS / 2 - 7, ">");
	mvprintw(7 + game->cursor, COLS / 2 + 6, "<");
}

void		render_scene(t_game *game)
{
	if (game->scene == MENU_MAIN)
		render_main(game);
	else if (game->scene == IN_GAME)
		render_game(game);
}
