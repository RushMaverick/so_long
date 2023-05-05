/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrask <rrask@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 12:40:06 by rrask             #+#    #+#             */
/*   Updated: 2023/05/05 16:17:06 by rrask            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_map(t_game *game)
{
	while (game->y >= 0)
	{
		free(game->map[game->y]);
		game->y--;
	}
	free(game->map);
}

void	sprite_init(t_game *game)
{
	game->player_front = mlx_xpm_file_to_image(game->mlx, FRONT, &game->resx,
			&game->resy);
	game->player_back = mlx_xpm_file_to_image(game->mlx, BACK, &game->resx,
			&game->resy);
	game->player_left = mlx_xpm_file_to_image(game->mlx, LEFT, &game->resx,
			&game->resy);
	game->player_right = mlx_xpm_file_to_image(game->mlx, RIGHT, &game->resx,
			&game->resy);
	game->empty = mlx_xpm_file_to_image(game->mlx, EMPTY, &game->resx,
			&game->resy);
	game->wall = mlx_xpm_file_to_image(game->mlx, WALL, &game->resx,
			&game->resy);
	game->exit = mlx_xpm_file_to_image(game->mlx, EXIT, &game->resx,
			&game->resy);
	game->key = mlx_xpm_file_to_image(game->mlx, KEY, &game->resx, &game->resy);
}

void	init(t_game *game)
{
	game->resx = 32;
	game->resy = 32;
	game->collectible = 0;
	game->collectible_check = 0;
	game->exit_reach = 0;
	game->map_validity = 0;
	game->mlx = mlx_init();
	if (!game->mlx)
		invalid_error("Failed to initialize mlx.");
	sprite_init(game);
	if (!game->win)
		invalid_error("Window failed to open.");
}

int	key_handler(int keycode, t_game *game)
{
	if (keycode == ESC)
	{
		free_map(game);
		exit(0);
	}
	if (keycode == KEY_W)
		up(game);
	if (keycode == KEY_A)
		left(game);
	if (keycode == KEY_S)
		down(game);
	if (keycode == KEY_D)
		right(game);
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
