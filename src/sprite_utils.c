/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrask <rrask@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 10:53:14 by rrask             #+#    #+#             */
/*   Updated: 2023/05/02 18:08:25 by rrask            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	sprite_placement(t_game *game, int offsetx, int offsety)
{
	if (game->map[game->y][game->x] == '1')
		mlx_put_image_to_window(game->mlx, game->win, game->wall, offsetx,
			offsety);
	if (game->map[game->y][game->x] == '0')
		mlx_put_image_to_window(game->mlx, game->win, game->empty, offsetx,
			offsety);
	if (game->map[game->y][game->x] == 'E')
		mlx_put_image_to_window(game->mlx, game->win, game->exit, offsetx,
			offsety);
	if (game->map[game->y][game->x] == 'P')
	{
		game->pposx = game->x;
		game->pposy = game->y;
		mlx_put_image_to_window(game->mlx, game->win, game->empty, offsetx,
			offsety);
		mlx_put_image_to_window(game->mlx, game->win, game->player, offsetx,
			offsety);
	}
	if (game->map[game->y][game->x] == 'C')
	{
		mlx_put_image_to_window(game->mlx, game->win, game->empty, offsetx,
			offsety);
		mlx_put_image_to_window(game->mlx, game->win, game->key, offsetx,
			offsety);
	}
}

void	map_placement(t_game *game, int x, int y)
{
	int	offsetx;
	int	offsety;

	offsetx = x * 32;
	offsety = y * 32;
	sprite_placement(game, offsety, offsetx);
}