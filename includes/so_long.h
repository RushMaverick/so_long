/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrask <rrask@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 17:31:35 by rrask             #+#    #+#             */
/*   Updated: 2023/04/17 21:41:34 by rrask            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# define MOVE_X 0
# define MOVE_Y 0
# define WIN_WIDTH 640
# define WIN_HEIGHT 576
# define FRONT	"src/sprites/front.xpm"
# define BACK	"src/sprites/back.xpm"
# define LEFT	"src/sprites/left.xpm"
# define RIGHT	"src/sprites/right.xpm"
# include "mlx.h"
# include "libft.h"

typedef struct s_vars{
	void	*mlx;
	void	*win;
	void	*img;
	int		place;
}				t_vars;

typedef struct s_game{
	int		resx;
	int		resy;
	int		dimsy;
	int		dimsx;
}				t_game;

typedef enum e_keyevent{
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

typedef enum e_game_obj
{
	EMPTY,
	PLAYER,
	WALL,
	EXIT,
	COLLECTIBLE,
}	t_game_obj;


// srtbfd g data

// t_game_obj	**map;

// dfgfg


// parse_map(fd)


// data->map = malloc(sizeof(t_game_obj *) * nb of lines)


// read a line 0
// 	data->map[0] = malloc(sizeof(t_game_obj) * length of the line)
// 	for i, ch in line:
// 		if (ch == '0')
// 			data->map[line_nb][i] = EMPTY;
// 		else if (ch == 'p')
// 			data->map[line_nb][i] = PLAer;
// 		if (ch == '0')
// 			data->map[line_nb][i] = EMPTY;
// 		if (ch == '0')
// 			data->map[line_nb][i] = EMPTY;

int		key_handler(int keycode, t_vars *vars);
int		image_handler(t_vars *vars, t_game *game);
void	init(t_game *game, t_vars *vars);

#endif