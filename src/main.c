/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrask <rrask@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 12:40:06 by rrask             #+#    #+#             */
/*   Updated: 2023/04/25 11:31:42 by rrask            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init(t_game *game, t_vars *vars)
{
	game->resx = 32;
	game->resy = 32;

	vars->mlx = mlx_init();
	if (!vars->mlx)
	{
		ft_printf("Failed to init, innit?");
		exit(1);
	}
	vars->player = mlx_xpm_file_to_image(vars->mlx, FRONT, &game->resx,
			&game->resy);
	vars->empty = mlx_xpm_file_to_image(vars->mlx, EMPTY, &game->resx,
			&game->resy);
	vars->wall = mlx_xpm_file_to_image(vars->mlx, WALL, &game->resx,
			&game->resy);
	vars->exit = mlx_xpm_file_to_image(vars->mlx, EXIT, &game->resx,
			&game->resy);
	vars->key = mlx_xpm_file_to_image(vars->mlx, KEY, &game->resx,
			&game->resy);
	vars->win = mlx_new_window(vars->mlx, WIN_WIDTH, WIN_HEIGHT, "VIdy a geim");
	if (!vars->win)
	{
		ft_printf("Windows failed, therefore you suck.");
		exit(1);
	}
}

int	key_handler(int keycode, t_vars *vars)
{
	if (keycode == KEY_W)
		ft_printf("MOVE UP\n");
	if (keycode == KEY_A)
		ft_printf("MOVE LEFT\n");
	if (keycode == KEY_S)
		ft_printf("MOVE DOWN\n");
	if (keycode == KEY_D)
		ft_printf("MOVE RIGHT\n");
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
	map_checker(argv[1], &vars);
	mlx_hook(vars.win, 2, 1L << 0, &key_handler, &vars);
	mlx_loop(vars.mlx);
	return (0);
}
