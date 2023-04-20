/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrask <rrask@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 15:50:28 by rrask             #+#    #+#             */
/*   Updated: 2023/04/20 13:42:47 by rrask            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
	map_validator(map);
}

void	map_validator(t_map *map)
{
	int	i;
	int	j;
	int	len;

	i = 0;
	j = 0;
	len = 0;
	while (map->map[i] != '\0')
	{
		ft_printf("The *: %s\n", map->map[i]);
		j = 0;
		while (map->map[i][j] != '\0')
		{
			len = ft_strlen(&map->map[i][j]);
			ft_printf("The length: %d\n", len);
			j++;
		}
		i++;
	}
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