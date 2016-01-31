/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgallo <mgallo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/30 10:23:31 by mgallo            #+#    #+#             */
/*   Updated: 2016/01/30 15:46:42 by mgallo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_H
# define GAME_H

# define ESCAPE		27
# define ENTER		10
# define RESET		114
# define RESIZE		410
# define UP			259
# define DOWN		258
# define LEFT		260
# define RIGHT		261
# define TIME_SLEEP	60000

# include <ncurses.h>

typedef enum	e_const
{
	WIN_VALUE = 2048
}				t_const;

typedef enum	e_scene
{
	MENU_MAIN,
	MENU_WIN,
	MENU_LOSE,
	IN_GAME

}				t_scene;

typedef struct	s_game
{
	unsigned int	score;
	int				size;
	t_scene			scene;
	int				cursor;
	int				moved;
	int				win;
	int				win_value;
	int				**grid;
	int				end;
}				t_game;

typedef struct	s_point
{
	int x;
	int y;
}				t_point;

void			draw_borders(int x, int y, int w, int h);
void			render_grid(t_game *game, int w, int h);
void			render_scene(t_game *game);
void			add_number(t_game *game);
void			reset_game(t_game *game);
void			control(t_game *game, int key);
void			left(t_game *game);
void			right(t_game *game);
void			up(t_game *game);
void			down(t_game *game);
void			initialize_color(void);
int				get_color(int v);
int				is_pow2(int v);
void			check(t_game *game);

#endif
