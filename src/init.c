/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrask <rrask@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 18:23:13 by rrask             #+#    #+#             */
/*   Updated: 2023/05/08 19:05:06 by rrask            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
	game->num_exit = 0;
	game->num_player = 0;
	game->exit_reach = 0;
	game->map_validity = 0;
	game->steps = 0;
	game->mlx = mlx_init();
	if (!game->mlx)
		invalid_error("Failed to initialize mlx.");
	sprite_init(game);
	if (!game->win)
		invalid_error("Window failed to open.");
}
