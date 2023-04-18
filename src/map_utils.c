/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrask <rrask@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 15:50:28 by rrask             #+#    #+#             */
/*   Updated: 2023/04/18 15:50:32 by rrask            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	tile_number(int fd, char *line, t_game *game)
{
	fd = open(line, O_RDONLY);
	game->map_row = get_next_line(fd);
	game->width = ft_strlen(game->map_row) - 1;
	free(game->map_row);
	close(fd);
}

void	get_columns(t_game *game, int fd)
{
	int	i;

	game->width = 0;
	game->col_count = -1;
	game->map_row = NULL;
	i = 1;
	while (game->map_row != NULL || i == 1)
	{
		i = 0;
		game->map_row = get_next_line(fd);
		game->col_count++;
		free(game->map_row);
	}
	close(fd);
}

void	map_checker(char *line)
{
	int		fd;
	t_game	game;

	fd = open(line, O_RDONLY);
	get_columns(&game, fd);
	tile_number(fd, line, &game);
	game.map = (char **)malloc(sizeof(char *) * game.col_count);
	ft_printf("%d tiles, with a number of %d columns.\n", game.width, game.col_count);
}