/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrask <rrask@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 15:50:28 by rrask             #+#    #+#             */
/*   Updated: 2023/04/24 17:32:24 by rrask            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	map_reader(int fd, t_map *map)
{
	char	*str;
	char	*map_array;

	map->height = 0;
	map_array = malloc(1);
	while (1) //LEAK IN HERE SOMEWHERE
	{
		str = get_next_line(fd);
		if (str == NULL)
			break ;
		map_array = ft_strjoinfree(map_array, str);
		free(str);
		map->height++;
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
	int	x;
	int	y;
	int	comp_width;

	x = 0;
	y = 0;
	comp_width = ft_strlen(map->map[x]);
	while (map->map[x] != '\0')
	{
		y = 0;
		// map_rect_check(map->map[i], comp_width);
		while (map->map[x][y] != '\0')
		{
			map_placement(map, x, y, vars);
			y++;
		}
		x++;
		ft_printf("\n");
	}
}

void	map_placement(t_map *map, int x, int y, t_vars *vars)
{
	int	line_length;
	int	offsetx;
	int	offsety;

	vars->bpp = 32;
	offsety = x * 32;
	offsetx = y * 32;
	line_length = ft_strlen(map->map[x]);
	if (map->map[x][y] == '1')
	{
		mlx_put_image_to_window(vars->mlx, vars->win, vars->wall, offsetx,
			offsety);
	}
	if (map->map[x][y] == '0')
	{
		mlx_put_image_to_window(vars->mlx, vars->win, vars->empty, offsetx,
			offsety);
	}
	if (map->map[x][y] == 'P')
	{
		mlx_put_image_to_window(vars->mlx, vars->win, vars->empty, offsetx,
			offsety);
		mlx_put_image_to_window(vars->mlx, vars->win, vars->player, offsetx,
			offsety);
	}
}

/*Check the length of the following grid_line by
comparing to the comp_width set at the start.*/
// void	map_rect_check(char *grid_line, int comp_width)
// {
// }

void	map_checker(char *file_name, t_vars *vars)
{
	int		fd;
	t_map	map;

	fd = open(file_name, O_RDONLY);
	map_reader(fd, &map);
	map_check(&map, vars);
}
