/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_checks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrask <rrask@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 17:28:36 by rrask             #+#    #+#             */
/*   Updated: 2023/05/09 16:23:16 by rrask            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_map(t_game *game)
{
	while (game->y >= 0)
	{	
		free(game->temp_map[game->y]);
		free(game->map[game->y]);
		game->y--;
	}
	free(game->map);
	free(game->temp_map);
}

int	argchecker(char *arg)
{
	char	*ber;
	char	*check;
	int		len;

	len = ft_strlen(arg);
	ber = ".ber";
	check = ft_strnstr(arg, ber, len);
	if (!check)
		invalid_error("Map is not .ber format. Check again");
	return (0);
}

void	row_confirmation(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->x)
	{
		if (game->map[game->y - 1][i] != '1' || game->map[0][i] != '1')
			invalid_error("Map is not closed off. Check map.");
		i++;
	}
	if (game->collectible <= 0)
		invalid_error("No collectibles in the map.");
	if (game->num_exit != 1 || game->num_player != 1)
		invalid_error("No exit or no player, check again.");
}

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
