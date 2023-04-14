/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrask <rrask@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 12:40:06 by rrask             #+#    #+#             */
/*   Updated: 2023/04/14 14:16:11 by rrask            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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

int	image_handler(t_vars *vars, t_game *game)
{
	vars->img = mlx_xpm_file_to_image \
		(vars->mlx, "src/lad.xpm", &game->resx, &game->resy);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img, 0, 0);
	mlx_hook(vars->win, 2, 1L << 0, &key_handler, vars);
	return (0);
}

void	init(t_game *game)
{
	game->resx = 32;
	game->resy = 32;
}

int	main(void)
{
	t_vars	vars;
	t_game	game;

	init(&game);
	// int			fd;
	// char		**map;
	// if (argc != 2)
	// {
	// 	ft_printf("Nice try bucko, try again.\n");
	// 	return (0);
	// }
	// map = ft_calloc(1, 1);
	// fd = open(argv[1], O_RDONLY);
	//map_reader(fd);
	vars.mlx = mlx_init();
	if (!vars.mlx)
		return (0);
	vars.win = mlx_new_window(vars.mlx, WIN_WIDTH, WIN_HEIGHT, "KING");
	if (!vars.win)
	{
		free(vars.win);
		return (0);
	}
	image_handler(&vars, &game);
	mlx_loop(vars.mlx);
	return (0);
}
