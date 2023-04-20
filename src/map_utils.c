/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrask <rrask@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 15:50:28 by rrask             #+#    #+#             */
/*   Updated: 2023/04/20 17:38:06 by rrask            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

#include <stdio.h>

void	map_reader(int fd, t_map *map)
{
	char	*str;
	char	*map_array;
	char	**map;

	map->height = 0;
	map_array = malloc(1);
	while (42)
	{
		str = get_next_line(fd);
		if (str == NULL)
			break ;
		map_array = ft_strjoinfree(map_array, str);
		free(str);
		map->height++;
	}
	map = ft_split(map_array, '\n');
	free(map_array);
	map_validator(map);
}

void	map_validator(char **map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map[i] != '\0')
	{
		j = 0;
		ft_printf("%s", map[i]);
		while (map[i][j] != '\0')
		{
			if (map[i][j] != '\n')
				j++;
		}
		i++;
	}
}

void	map_checker(char *file_name)
{
	int		fd;
	t_map	map;

	fd = open(file_name, O_RDONLY);
	map_reader(fd, &map);
	//free_map
	// ft_printf("%d tiles, with a number of %d columns.\n", map.width, map.col_count);
}