/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrask <rrask@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 12:40:06 by rrask             #+#    #+#             */
/*   Updated: 2023/05/08 18:27:34 by rrask            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static	int	close_window(t_game *game)
{
	mlx_destroy_window(game->mlx, game->win);
	exit(0);
	return (0);
}

static int	key_handler(int keycode, t_game *game)
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

void	game_window(t_game *game)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (game->map[y] != '\0')
	{
		while (game->map[y][x] != '\0')
			x++;
		y++;
	}
	game->win = mlx_new_window(game->mlx, x * 32, y * 32,
			"So_long, space cowboy.");
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
	mlx_hook(game.win, 17, 1L << 5, &close_window, &game);
	mlx_hook(game.win, 2, 1L << 0, &key_handler, &game);
	mlx_loop(game.mlx);
	return (0);
}
