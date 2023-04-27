/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrask <rrask@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 17:31:35 by rrask             #+#    #+#             */
/*   Updated: 2023/04/27 17:30:09 by rrask            ###   ########.fr       */
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
# include "mlx.h"

// typedef enum e_game_obj
// {
// 	EMPTY,
// 	PLAYER,
// 	WALL,
// 	EXIT,
// 	COLLECTIBLE,
// }				t_game_obj;

typedef struct s_map
{
	int			x;
	int			y;
	char		**map;
}				t_map;

typedef struct s_vars
{
	void		*mlx;
	void		*win;
	void		*player;
	void		*empty;
	void		*exit;
	void		*wall;
	void		*key;
	t_map		*map;
}				t_vars;

typedef struct s_game
{
	int			resx;
	int			resy;
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

int				key_handler(int keycode, t_vars *vars);
void			init(t_game *game, t_vars *vars);
void			invalid_error(void);
void			map_checker(char *line, t_vars *vars);
void			map_reader(int fd, t_map *map);
void			map_check(t_map *map, t_vars *vars);
void			map_placement(t_map *map, int x, int y, t_vars *vars);
void			map_rect_check(char *grid_line, int comp_width);
void			free_map(t_map	*map);

#endif 