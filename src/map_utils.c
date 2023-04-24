/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrask <rrask@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 15:50:28 by rrask             #+#    #+#             */
/*   Updated: 2023/04/24 12:33:59 by rrask            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	map_reader(int fd, t_map *map)
{
	char	*str;
	char	*map_array;
	char	**whole_map;

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
	whole_map = ft_split(map_array, '\n');
	free(map_array);
	free(str);
	map_validator(map, whole_map);
}

void	map_validator(t_map *map, char **whole_map)
{
	int	i;
	int	j;
	int	comp_width;

	i = 0;
	j = 0;
	comp_width = ft_strlen(*whole_map);
	while (whole_map[i] != '\0')
	{
		j = 0;
		map->width = ft_strlen(whole_map[i]);
		if (map->width != comp_width)
		{
			free(whole_map);
			ft_printf("%s\n", "That's wrong");
			exit (1);
		}
		while (whole_map[i][j] != '\0')
		{
			map_placement(whole_map[i][j]);
			if (whole_map[i][j] != '\n')
				j++;
		}
		i++;
		ft_printf("\n");
	}
}

void	map_placement(char c)
{
	ft_printf("%c", c);
}

void	map_checker(char *file_name)
{
	int		fd;
	t_map	map;

	fd = open(file_name, O_RDONLY);
	map_reader(fd, &map);
	//free_map
	//ft_printf("%d tiles, with a number of %d columns.\n", map.width, map.col_count);
}