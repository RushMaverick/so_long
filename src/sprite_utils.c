/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrask <rrask@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 10:53:14 by rrask             #+#    #+#             */
/*   Updated: 2023/05/09 18:48:29 by rrask            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	empty_placement(t_game *game, int x, int y)
{
	if (game->map[game->y][game->x])
	{
		if (game->map[game->y][game->x] == 'E')
		{
			mlx_put_image_to_window(game->mlx, game->win, game->exit, x * 32, y
				* 32);
		}
		mlx_put_image_to_window(game->mlx, game->win, game->empty, x * 32, y
			* 32);
	}
}

void	sprite_placement(t_game *game, int x, int y)
{
	if (game->map[game->y][game->x] == '1')
		mlx_put_image_to_window(game->mlx, game->win, game->wall, x * 32, y
			* 32);
	if (game->map[game->y][game->x] == 'E')
	{
		mlx_put_image_to_window(game->mlx, game->win, game->exit, x * 32, y
			* 32);
		game->num_exit++;
	}
	if (game->map[game->y][game->x] == 'P')
	{
		game->pposx = game->x;
		game->pposy = game->y;
		game->num_player++;
		mlx_put_image_to_window(game->mlx, game->win, game->player_front,
			x * 32, y * 32);
	}
	if (game->map[game->y][game->x] == 'C')
	{
		game->collectible++;
		mlx_put_image_to_window(game->mlx, game->win, game->key, x * 32, y
			* 32);
	}
}

void	map_placement(t_game *game, int x, int y)
{
	empty_placement(game, x, y);
	sprite_placement(game, x, y);
}
