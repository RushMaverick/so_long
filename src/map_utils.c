/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrask <rrask@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 15:50:28 by rrask             #+#    #+#             */
/*   Updated: 2023/04/26 12:28:38 by rrask            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_map(t_map *map)
{
	int	size = ft_strlen(&map->map[2][0]);

	ft_printf("%d\n", size);
	exit(0);
}

void	map_reader(int fd, t_map *map)
{
	char	*str;
	char	*map_array;

	map->y = 0;
	map_array = malloc(1);
	while (1) //LEAK IN HERE SOMEWHERE
	{
		str = get_next_line(fd);
		if (str == NULL)
			break ;
		map_array = ft_strjoinfree(map_array, str);
		free(str);
		map->y++;
	}
	map->map = ft_split(map_array, '\n');
	free(map_array);
	free(str);
}

/*Checks the validity of the map. Map_rect_check checks if
the map is rectangular or not. Map_placement
places the correct sprites on the correct characters.*/
void	map_check(t_map *map, t_vars *vars)
{
	int	comp_width;

	map->x = 0;
	map->y = 0;
	comp_width = ft_strlen(map->map[map->x]);
	while (map->map[map->x] != '\0')
	{
		map->y = 0;
		map_rect_check(map->map[map->x], comp_width, map);
		while (map->map[map->x][map->y] != '\0')
		{
			map_placement(map, map->x, map->y, vars);
			map->y++;
		}
		map->x++;
	}
}

/*Check the length of the following grid_line by
comparing to the comp_width set at the start.*/
void	map_rect_check(char *grid_line, int comp_width, t_map *map)
{
	int	current_width;

	current_width = ft_strlen(grid_line);
	if (current_width != comp_width)
	{
		free_map(map);
		exit (0);
	}
}

void	map_checker(char *file_name, t_vars *vars)
{
	int		fd;
	t_map	map;

	fd = open(file_name, O_RDONLY);
	map_reader(fd, &map);
	map_check(&map, vars);
}
