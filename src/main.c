/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrask <rrask@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 12:40:06 by rrask             #+#    #+#             */
/*   Updated: 2023/05/02 17:49:24 by rrask            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init(t_game *game)
{
	game->resx = 32;
	game->resy = 32;
	game->mlx = mlx_init();
	if (!game->mlx)
	{
		ft_printf("Failed to init, innit?");
		exit(1);
	}
	game->player = mlx_xpm_file_to_image(game->mlx, FRONT, &game->resx,
			&game->resy);
	game->empty = mlx_xpm_file_to_image(game->mlx, EMPTY, &game->resx,
			&game->resy);
	game->wall = mlx_xpm_file_to_image(game->mlx, WALL, &game->resx,
			&game->resy);
	game->exit = mlx_xpm_file_to_image(game->mlx, EXIT, &game->resx,
			&game->resy);
	game->key = mlx_xpm_file_to_image(game->mlx, KEY, &game->resx,
			&game->resy);
	game->win = mlx_new_window(game->mlx, WIN_WIDTH, WIN_HEIGHT, "VIdy a geim");
	if (!game->win)
	{
		ft_printf("Window did not open, therefore you suck.");
		exit(1);
	}
}

int	key_handler(int keycode, t_game *game)
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
		free_map(game);
		exit(0);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
	{
		ft_printf("Nice try bucko, try again.\n");
		exit(1);
	}
	init(&game);
	map_checker(argv[1], &game);
	mlx_hook(game.win, 2, 1L << 0, &key_handler, &game);
	mlx_loop(game.mlx);
	return (0);
}
