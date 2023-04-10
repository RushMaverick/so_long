/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrask <rrask@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 12:40:06 by rrask             #+#    #+#             */
/*   Updated: 2023/04/10 14:57:58 by rrask            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	key_handler(int keycode, t_vars *vars)
{	
	if (keycode == KEY_W)
	{
		mlx_put_image_to_window(vars->mlx, vars->win, vars->img, 50, 0);
	}	
	if (keycode == ESC)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		exit(0);
	}
	return (0);
}

int	main(void)
{
	t_vars	vars;
	t_dims	dims;

	dims.x = 32;
	dims.y = 32;
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 640, 576, "KING");
	vars.img = mlx_xpm_file_to_image(vars.mlx, "src/lad.xpm", &dims.x, &dims.y);
	mlx_put_image_to_window(vars.mlx, vars.win, vars.img, 0, 0);
	mlx_hook(vars.win, 2, 1L << 0, key_handler, &vars);
	mlx_loop(vars.mlx);
	return (0);
}
