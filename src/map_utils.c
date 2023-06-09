/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrask <rrask@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 15:50:28 by rrask             #+#    #+#             */
/*   Updated: 2023/05/09 19:11:15 by rrask            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	map_reader(int fd, t_game *game)
{
	char	*str;
	char	*map_array;
	int		count;

	count = 0;
	map_array = ft_calloc(1, sizeof(char));
	if (!map_array)
		invalid_error("ft_calloc has failed. Try again?");
	while (1)
	{
		str = get_next_line(fd);
		if (count == 0 && str == NULL)
			invalid_error("Map seems to be invalid or empty, check again.");
		if (str == NULL)
			break ;
		if (ft_strncmp(str, "\n", ft_strlen(str)) == 0)
			invalid_error("Empty lines found. Check map again.");
		map_array = ft_strjoinfree(map_array, str);
		free(str);
		count++;
	}
	game->map = ft_split(map_array, '\n');
	game->temp_map = ft_split(map_array, '\n');
	free(map_array);
}

void	map_parser(t_game *game)
{
	int	comp_width;
	int	count;

	game->x = 0;
	game->y = 0;
	comp_width = ft_strlen(game->map[game->y]);
	count = 0;
	while (game->map[game->y] != '\0')
	{
		game->x = 0;
		map_rect_check(game->map[game->y], comp_width);
		while (game->map[game->y][game->x] != '\0')
		{
			map_placement(game, game->x, game->y);
			game->x++;
		}
		game->y++;
	}
	row_confirmation(game);
	flood_check(game, game->pposx, game->pposy);
}

void	map_checker(char *file_name, t_game *game)
{
	int		fd;

	if (!game)
		exit(0);
	fd = open(file_name, O_RDONLY);
	map_reader(fd, game);
	game_window(game);
	map_parser(game);
	if (game->map_validity != 1)
		invalid_error("Collectibles or exit is unreachable.");
}
