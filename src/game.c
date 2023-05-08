/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrask <rrask@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 16:29:51 by rrask             #+#    #+#             */
/*   Updated: 2023/05/08 16:30:25 by rrask            ###   ########.fr       */
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