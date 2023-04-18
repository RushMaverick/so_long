/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrask <rrask@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 12:40:06 by rrask             #+#    #+#             */
/*   Updated: 2023/04/18 15:50:10 by rrask            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init(t_game *game, t_vars *vars)
{
	game->resx = 32;
	game->resy = 32;
	vars->mlx = mlx_init();
	if (!vars->mlx)
		;
	vars->win = mlx_new_window(vars->mlx, WIN_WIDTH, WIN_HEIGHT, "VIdy a geim");
	if (!vars->win)
	{
		free(vars->win);
	}
}

int	image_handler(t_vars *vars, t_game *game)
{
	vars->img = mlx_xpm_file_to_image(vars->mlx, FRONT, &game->resx,
			&game->resy);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img, 0, 0);
	mlx_hook(vars->win, 2, 1L << 0, &key_handler, vars);
	return (0);
}

int	key_handler(int keycode, t_vars *vars)
{
	if (keycode == KEY_W)
	{
		ft_printf("MOVE UP\n");
	}
	if (keycode == KEY_A)
	{
		ft_printf("MOVE LEFT\n");
	}
	if (keycode == KEY_S)
	{
		ft_printf("MOVE DOWN\n");
	}
	if (keycode == KEY_D)
	{
		ft_printf("MOVE RIGHT\n");
	}
	if (keycode == ESC)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		exit(0);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_vars	vars;
	t_game	game;

	if (argc != 2)
	{
		ft_printf("Nice try bucko, try again.\n");
		exit(1);
	}
	init(&game, &vars);
	map_checker(argv[1]);
	image_handler(&vars, &game);
	mlx_loop(vars.mlx);
	return (0);
}
