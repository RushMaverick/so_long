/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrask <rrask@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 17:31:35 by rrask             #+#    #+#             */
/*   Updated: 2023/05/09 10:43:03 by rrask            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# define MOVE_X 0
# define MOVE_Y 0
# define WIN_WIDTH 640
# define WIN_HEIGHT 576
# define FRONT "src/sprites/front.xpm"
# define BACK "src/sprites/back.xpm"
# define LEFT "src/sprites/left.xpm"
# define RIGHT "src/sprites/right.xpm"
# define WALL "src/sprites/wall.xpm"
# define EXIT "src/sprites/exit.xpm"
# define EMPTY "src/sprites/empty.xpm"
# define KEY "src/sprites/key.xpm"
# include "libft.h"
# include <mlx.h>

typedef struct s_game
{
	int			x;
	int			y;
	int			resx;
	int			resy;
	int			steps;
	int			pposy;
	int			pposx;
	int			collectible;
	int			collectible_check;
	int			num_player;
	int			num_exit;
	int			map_validity;
	int			exit_reach;
	char		**map;
	char		**temp_map;
	void		*mlx;
	void		*win;
	void		*player_front;
	void		*player_left;
	void		*player_right;
	void		*player_back;
	void		*empty;
	void		*exit;
	void		*wall;
	void		*key;
}				t_game;

typedef enum e_keyevent
{
	KEY_A = 0,
	KEY_S = 1,
	KEY_D = 2,
	ON_KEYDOWN = 3,
	ON_KEYUP = 4,
	ON_MOUSEDOWN = 5,
	ON_MOUSEUP = 6,
	ON_MOUSEMOVE = 7,
	ON_EXPOSE = 12,
	KEY_W = 13,
	ON_DESTROY = 17,
	ESC = 53
}				t_keyevent;

int				argchecker(char *arg);
void			sprite_init(t_game *game);
void			init(t_game *game);
void			invalid_error(char *err_msg);
void			map_checker(char *file_name, t_game *game);
void			map_reader(int fd, t_game *game);
void			map_parser(t_game *game);
void			map_placement(t_game *game, int x, int y);
void			sprite_placement(t_game *game, int x, int y);
void			empty_placement(t_game *game, int x, int y);
void			map_rect_check(const char *grid_line, int comp_width);
void			free_map(t_game *game);
void			row_confirmation(t_game *game);
void			flood_check(t_game *game, int x, int y);
void			game_window(t_game *game);
void			finish_game(t_game *game);
void			up(t_game *game);
void			down(t_game *game);
void			left(t_game *game);
void			right(t_game *game);

#endif 