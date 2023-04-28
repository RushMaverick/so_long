/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrask <rrask@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 15:50:28 by rrask             #+#    #+#             */
/*   Updated: 2023/04/28 10:35:27 by rrask            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_map(t_map *map)
{
	while (map->y >= 0)
	{
		free(map->map[map->y]);
		map->y--;
	}
	free(map->map);
}

void	map_reader(int fd, t_map *map)
{
	char	*str;
	char	*map_array;
	int		count;

	count = 0;
	map_array = malloc(1);
	if (!map_array)
		exit (0);
	while (1) //LEAK IN HERE SOMEWHERE
	{
		str = get_next_line(fd);
		if (str == NULL)
			break ;
		map_array = ft_strjoinfree(map_array, str);
		free(str);
		count++;
	}
	map->map = ft_split(map_array, '\n');
	free(map_array);
}

/*Checks the validity of the map. Map_rect_check checks if
the map is rectangular or not. Map_placement
places the correct sprites on the correct characters.*/
void	map_check(t_map *map, t_vars *vars)
{
	int	comp_width;

	map->x = 0;
	map->y = 0;
	comp_width = ft_strlen(map->map[map->y]);
	while (map->map[map->y] != '\0')
	{
		map->x = 0;
		map_rect_check(map->map[map->y], comp_width);
		while (map->map[map->y][map->x] != '\0')
		{
			map_placement(map, map->y, map->x, vars);
			map->x++;
		}
		map->y++;
	}
}

void	map_checker(char *file_name, t_vars *vars)
{
	int		fd;
	t_map	*map;

	map = malloc(sizeof(t_map));
	if (!map)
		exit (0);
	fd = open(file_name, O_RDONLY);
	map_reader(fd, map);
	vars->map = map;
	map_check(map, vars);
}
