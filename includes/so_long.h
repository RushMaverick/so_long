/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrask <rrask@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 17:31:35 by rrask             #+#    #+#             */
/*   Updated: 2023/04/10 14:53:39 by rrask            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "mlx.h"
# include "libft.h"

typedef struct s_vars{
	void	*mlx;
	void	*win;
	void	*img;
	int		place;
}				t_vars;

typedef struct s_dims{
	int		x;
	int		y;
}				t_dims;

enum e_keyevent{
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
	ESC = 53,
};

int	key_handler(int keycode, t_vars *vars);

#endif