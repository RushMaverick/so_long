/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrask <rrask@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 16:29:51 by rrask             #+#    #+#             */
/*   Updated: 2023/05/09 10:42:35 by rrask            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	finish_game(t_game *game)
{
	mlx_put_image_to_window(game->mlx, game->win, game->empty, game->pposx
		* 32, game->pposy * 32);
	game->pposy -= 1;
	mlx_put_image_to_window(game->mlx, game->win, game->player_back,
		game->pposx * 32, game->pposy * 32);
	ft_printf("The winner is you. %d steps taken.\n", game->steps);
	exit(0);
}

void	flood_check(t_game *game, int x, int y)
{
	if (game->exit_reach == 1 && game->collectible == game->collectible_check)
		game->map_validity = 1;
	if (game->temp_map[y][x] == 'E')
		game->exit_reach = 1;
	if (game->temp_map[y][x] == '0' || game->temp_map[y][x] == 'C'
		|| game->temp_map[y][x] == 'P' || game->temp_map[y][x] == 'E')
	{
		if (game->temp_map[y][x] == 'C')
			game->collectible_check += 1;
		game->temp_map[y][x] = 'X';
		if (x < game->x - 1)
			flood_check(game, x + 1, y);
		if (y < game->y - 1)
			flood_check(game, x, y + 1);
		if (x > 0)
			flood_check(game, x - 1, y);
		if (y > 0)
			flood_check(game, x, y - 1);
	}
}
