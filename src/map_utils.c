/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrask <rrask@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 15:50:28 by rrask             #+#    #+#             */
/*   Updated: 2023/04/19 15:29:03 by rrask            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// void	allocate_x(int fd, char *line, t_map *map)
// {
// 	fd = open(line, O_RDONLY);
// 	map->map_x = get_next_line(fd);
// 	map->width = ft_strlen(map->map_x) - 1;
// 	free(map->map_x);
// 	close(fd);
// }

// void	allocate_y(t_map *map, int fd)
// {
// 	int		i;
// 	int		l;
// 	char	*str;

// 	map->width = 0;
// 	map->col_count = -1;
// 	str = "";
// 	i = 1;
// 	l = 0;
// 	while (str != NULL || i == 1)
// 	{
// 		i = 0;
// 		str = get_next_line(fd);
// 		map->map[l] = *(char *)malloc(sizeof(char) * ft_strlen(str));
// 		ft_printf("I am here");
// 		str2[l] = *ft_strdup(str);
// 		ft_printf("%s\n", str2);
// 		l++;
// 		free(str);
// 	}
// 	close(fd);
// }

void	map_reader(int fd, t_map *map)
{
	char	*str;
	char	*map_array;

	map->counter = 0;
	str = get_next_line(fd);
	map_array = malloc(1);
	while (str != NULL)
	{
		map_array = ft_strjoinfree(map_array, str);
		map->counter++;
		free(str);
		str = get_next_line(fd);
	}
	map->map = ft_split(map_array, '\n');
}

void	map_checker(char *line)
{
	int		fd;
	t_map	map;

	fd = open(line, O_RDONLY);
	map_reader(fd, &map);
	//free_map
	// ft_printf("%d tiles, with a number of %d columns.\n", map.width, map.col_count);
}