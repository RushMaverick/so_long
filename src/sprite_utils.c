/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrask <rrask@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 10:53:14 by rrask             #+#    #+#             */
/*   Updated: 2023/04/27 11:10:29 by rrask            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	sprite_placement(t_map *map, t_vars *vars, int offsetx, int offsety)
{
	if (map->map[map->y][map->x] == '1')
		mlx_put_image_to_window(vars->mlx, vars->win, vars->wall, offsetx,
			offsety);
	if (map->map[map->y][map->x] == '0')
		mlx_put_image_to_window(vars->mlx, vars->win, vars->empty, offsetx,
			offsety);
	if (map->map[map->y][map->x] == 'E')
		mlx_put_image_to_window(vars->mlx, vars->win, vars->exit, offsetx,
			offsety);
	if (map->map[map->y][map->x] == 'P')
	{
		mlx_put_image_to_window(vars->mlx, vars->win, vars->empty, offsetx,
			offsety);
		mlx_put_image_to_window(vars->mlx, vars->win, vars->player, offsetx,
			offsety);
	}
	if (map->map[map->y][map->x] == 'C')
	{
		mlx_put_image_to_window(vars->mlx, vars->win, vars->empty, offsetx,
			offsety);
		mlx_put_image_to_window(vars->mlx, vars->win, vars->key, offsetx,
			offsety);
	}
}

void	map_placement(t_map *map, int x, int y, t_vars *vars)
{
	int	offsetx;
	int	offsety;

	offsetx = x * 32;
	offsety = y * 32;
	sprite_placement(map, vars, offsety, offsetx);
}