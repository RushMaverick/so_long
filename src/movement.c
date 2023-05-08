/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrask <rrask@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 11:24:33 by rrask             #+#    #+#             */
/*   Updated: 2023/05/08 10:30:05 by rrask            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	up(t_game *game)
{
	if (game->map[game->pposy - 1][game->pposx] == '0')
	{
		game->map[game->pposy - 1][game->pposx] = 'P';
		mlx_put_image_to_window(game->mlx, game->win, game->empty, game->pposx
			* 32, game->pposy * 32);
		game->map[game->pposy][game->pposx] = '0';
		game->pposy -= 1;
		mlx_put_image_to_window(game->mlx, game->win, game->player_back,
			game->pposx * 32, game->pposy * 32);
	}
	if (game->map[game->pposy - 1][game->pposx] == 'C')
	{
		game->map[game->pposy - 1][game->pposx] = 'P';
		mlx_put_image_to_window(game->mlx, game->win, game->empty, game->pposx
			* 32, game->pposy * 32);
		game->collectible--;
		game->map[game->pposy][game->pposx] = '0';
		game->pposy -= 1;
		mlx_put_image_to_window(game->mlx, game->win, game->player_back,
			game->pposx * 32, game->pposy * 32);
	}
}

void	left(t_game *game)
{
	if (game->map[game->pposy][game->pposx - 1] == '0')
	{
		game->map[game->pposy][game->pposx - 1] = 'P';
		mlx_put_image_to_window(game->mlx, game->win, game->empty, game->pposx
			* 32, game->pposy * 32);
		game->map[game->pposy][game->pposx] = '0';
		game->pposx -= 1;
		mlx_put_image_to_window(game->mlx, game->win, game->player_left,
			game->pposx * 32, game->pposy * 32);
	}
	if (game->map[game->pposy][game->pposx - 1] == 'C')
	{
		game->map[game->pposy][game->pposx - 1] = 'P';
		mlx_put_image_to_window(game->mlx, game->win, game->empty, game->pposx
			* 32, game->pposy * 32);
		game->collectible--;
		game->map[game->pposy][game->pposx] = '0';
		game->pposx -= 1;
		mlx_put_image_to_window(game->mlx, game->win, game->player_left,
			game->pposx * 32, game->pposy * 32);
	}
}

void	right(t_game *game)
{
	if (game->map[game->pposy][game->pposx + 1] == '0')
	{
		game->map[game->pposy][game->pposx + 1] = game->pposx;
		mlx_put_image_to_window(game->mlx, game->win, game->empty, game->pposx
			* 32, game->pposy * 32);
		game->map[game->pposy][game->pposx] = '0';
		game->pposx += 1;
		mlx_put_image_to_window(game->mlx, game->win, game->player_right,
			game->pposx * 32, game->pposy * 32);
	}
	if (game->map[game->pposy][game->pposx + 1] == 'C')
	{
		game->map[game->pposy][game->pposx + 1] = 'P';
		mlx_put_image_to_window(game->mlx, game->win, game->empty, game->pposx
			* 32, game->pposy * 32);
		game->collectible--;
		game->map[game->pposy][game->pposx] = '0';
		game->pposx += 1;
		mlx_put_image_to_window(game->mlx, game->win, game->player_right,
			game->pposx * 32, game->pposy * 32);
	}
}

void	down(t_game *game)
{
	if (game->map[game->pposy + 1][game->pposx] == '0')
	{
		game->map[game->pposy + 1][game->pposx] = game->pposx;
		mlx_put_image_to_window(game->mlx, game->win, game->empty, game->pposx
			* 32, game->pposy * 32);
		game->map[game->pposy][game->pposx] = '0';
		game->pposy += 1;
		mlx_put_image_to_window(game->mlx, game->win, game->player_front,
			game->pposx * 32, game->pposy * 32);
	}
	if (game->map[game->pposy + 1][game->pposx] == 'C')
	{
		game->map[game->pposy + 1][game->pposx] = 'P';
		mlx_put_image_to_window(game->mlx, game->win, game->empty, game->pposx
			* 32, game->pposy * 32);
		game->collectible--;
		game->map[game->pposy][game->pposx] = '0';
		game->pposy += 1;
		mlx_put_image_to_window(game->mlx, game->win, game->player_front,
			game->pposx * 32, game->pposy * 32);
	}
}
