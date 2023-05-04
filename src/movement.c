/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrask <rrask@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 11:24:33 by rrask             #+#    #+#             */
/*   Updated: 2023/05/04 16:01:15 by rrask            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	up(t_game *game)
{
	ft_printf("Above the player: %c\n", game->map[game->pposy - 1][game->pposx]);
	if (game->map[game->pposy - 1][game->pposx] == '0')
	{
		game->map[game->pposy - 1][game->pposx] = 'P';
		mlx_put_image_to_window(game->mlx, game->win,
			game->empty, game->pposx * 32, game->pposy * 32);
		game->map[game->pposy][game->pposx] = '0';
		game->pposy -= 1;
		mlx_put_image_to_window(game->mlx, game->win,
			game->player, game->pposx * 32, game->pposy * 32);
	}
	ft_printf("Above the player: %c\n", game->map[game->pposy][game->pposx]);
}

void	left(t_game *game)
{
	ft_printf("Collect Counter: %d\n", game->collectible);
	if (game->map[game->pposy][game->pposx - 1] == '0')
	{
		game->map[game->pposy][game->pposx - 1] = 'P';
		mlx_put_image_to_window(game->mlx, game->win,
			game->empty, game->pposx * 32, game->pposy * 32);
		game->map[game->pposy][game->pposx] = '0';
		game->pposx -= 1;
		mlx_put_image_to_window(game->mlx, game->win,
			game->player, game->pposx * 32, game->pposy * 32);
	}
	if (game->map[game->pposy][game->pposx - 1] == 'C')
	{
		game->map[game->pposy][game->pposx - 1] = 'P';
		mlx_put_image_to_window(game->mlx, game->win,
			game->empty, game->pposx * 32, game->pposy * 32);
		game->collectible--;
		game->map[game->pposy][game->pposx] = '0';
		game->pposx -= 1;
		mlx_put_image_to_window(game->mlx, game->win,
			game->player, game->pposx * 32, game->pposy * 32);
	}
	ft_printf("Collect Counter: %d\n", game->collectible);
	ft_printf("Player X: %d\n", game->pposx);
	ft_printf("Player Y: %d\n", game->pposy);
}

void	right(t_game *game)
{
	ft_printf("Right of the player: %c\n", game->map[game->pposy][game->pposx + 1]);
	if (game->map[game->pposy][game->pposx + 1] == '0')
	{
		game->map[game->pposy][game->pposx + 1] = game->pposx;
		mlx_put_image_to_window(game->mlx, game->win,
			game->empty, game->pposx * 32, game->pposy * 32);
		game->map[game->pposy][game->pposx] = '0';
		game->pposx += 1;
		mlx_put_image_to_window(game->mlx, game->win,
			game->player, game->pposx * 32, game->pposy * 32);
	}
	ft_printf("Right of the player: %c\n", game->map[game->pposy][game->pposx + 1]);
}

void	down(t_game *game)
{
	ft_printf("Below the player: %c\n", game->map[game->pposy + 1][game->pposx]);
	if (game->map[game->pposy + 1][game->pposx] == '0')
	{
		game->map[game->pposy + 1][game->pposx] = game->pposx;
		mlx_put_image_to_window(game->mlx, game->win,
			game->empty, game->pposx * 32, game->pposy * 32);
		game->map[game->pposy][game->pposx] = '0';
		game->pposy += 1;
		mlx_put_image_to_window(game->mlx, game->win,
			game->player, game->pposx * 32, game->pposy * 32);
	}
	ft_printf("Below the player: %c\n", game->map[game->pposy + 1][game->pposx]);
}
