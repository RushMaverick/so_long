/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_checks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrask <rrask@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 17:28:36 by rrask             #+#    #+#             */
/*   Updated: 2023/05/02 13:40:28 by rrask            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	row_confirmation(t_map *map)
{
	int		i;

	i = 0;
	while (i < map->x)
	{
		if (map->map[map->y - 1][i] != '1' || map->map[0][i] != '1')
		{
			invalid_error("Map is not closed off. Check map.");
			exit(0);
		}
		i++;
	}
}

void	check_characters(t_map *map)
{
	ft_printf("%s\n", map->map[0]);
	ft_printf("This is where the program detected that you don't have a proper amount of characters for the map to be valid.");
	ft_printf("Also maybe have the program check if any of those collectibles are closed off from the player.");
}

/*Check the length of the following grid_line by
comparing to the comp_width set at the start.*/
void	map_rect_check(const char *grid_line, int comp_width)
{
	int		i;
	int		current_width;

	current_width = ft_strlen(grid_line);
	i = 0;
	if (grid_line[i] != '1')
	{
		invalid_error("Map is not closed off. Check map.");
	}
	while (grid_line[i])
	{
		if (grid_line[i] != 'E' && grid_line[i] != '0'
			&& grid_line[i] != '1' && grid_line[i] != 'C'
			&& grid_line[i] != 'P')
			invalid_error("Illegal character found in map. Check map.");
		i++;
	}
	if ((grid_line[i - 1]) != '1' || current_width != comp_width)
	{
		invalid_error("Map is not rectangular or closed off. Check map.");
	}
}

void	invalid_error(char *err_msg)
{
	ft_printf("%s\n", err_msg);
	exit(0);
}
