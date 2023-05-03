/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrask <rrask@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 11:24:33 by rrask             #+#    #+#             */
/*   Updated: 2023/05/03 12:29:33 by rrask            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	up(t_game *game)
{
	ft_printf("Above the player: %c\n", game->map[game->pposy - 1][game->pposx]);
	if (game->map[game->pposy - 1][game->pposx] == '0')
	{
		game->pposy -= 1;
	}
	ft_printf("Above the player: %c\n", game->map[game->pposy][game->pposx]);
}

void	left(t_game *game)
{
	int	x;

	x = 0;
	ft_printf("Left of the player: %c\n", game->map[game->pposy][game->pposx - 1]);
	ft_printf("Old pposx: %d\n", game->pposx);
	if (game->map[game->pposy][game->pposx - 1] == '0')
	{
		game->map[game->pposy][game->pposx - 1] = game->pposx;
		game->pposx -= 1;
	}
	ft_printf("Left of the player: %c\n", game->map[game->pposy][game->pposx - 1]);
	ft_printf("New pposx: %d\n", game->pposx);
}

void	right(t_game *game)
{
	ft_printf("Right of the player: %c\n", game->map[game->pposy][game->pposx + 1]);
	if (game->map[game->pposy][game->pposx + 1] == '0')
	{
		game->pposx += 1;
	}
	ft_printf("Right of the player: %c\n", game->map[game->pposy][game->pposx + 1]);
}

void	down(t_game *game)
{
	ft_printf("Below the player: %c\n", game->map[game->pposy + 1][game->pposx]);
	if (game->map[game->pposy + 1][game->pposx] == '0')
	{
		game->pposy += 1;
	}
	ft_printf("Below the player: %c\n", game->map[game->pposy + 1][game->pposx]);
}
