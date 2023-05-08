/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_checks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrask <rrask@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 17:28:36 by rrask             #+#    #+#             */
/*   Updated: 2023/05/08 17:59:53 by rrask            ###   ########.fr       */
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

/*Checks that the first and the last rows are 1s,
essentially telling us they are walls.*/
void	row_confirmation(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->x)
	{
		if (game->map[game->y - 1][i] != '1' || game->map[0][i] != '1')
		{
			invalid_error("Map is not closed off. Check map.");
			exit(0);
		}
		i++;
	}
	if (game->collectible <= 0)
		invalid_error("No collectibles in the map.");
	if (game->num_exit != 1 || game->num_player != 1)
		invalid_error("No exit or no player, check again.");
}

/*Check the length of the following grid_line by
comparing to the comp_width set at the start.*/
void	map_rect_check(const char *grid_line, int comp_width)
{
	int	i;
	int	current_width;

	current_width = ft_strlen(grid_line);
	i = 0;
	if (grid_line[i] != '1')
		invalid_error("Map is not closed off. Check map.");
	while (grid_line[i])
	{
		if (grid_line[i] != 'E' && grid_line[i] != '0' && grid_line[i] != '1'
			&& grid_line[i] != 'C' && grid_line[i] != 'P')
			invalid_error("Illegal character found in map. Check map.");
		i++;
	}
	if ((grid_line[i - 1]) != '1' || current_width != comp_width)
		invalid_error("Map is not rectangular or closed off. Check map.");
}

void	invalid_error(char *err_msg)
{
	ft_printf("%s\n", err_msg);
	exit(0);
}
