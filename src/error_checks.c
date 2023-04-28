/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_checks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrask <rrask@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 17:28:36 by rrask             #+#    #+#             */
/*   Updated: 2023/04/28 11:42:44 by rrask            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*Check the length of the following grid_line by
comparing to the comp_width set at the start.*/
void	map_rect_check(const char *grid_line, int comp_width)
{
	int		i;
	int		current_width;

	current_width = ft_strlen(grid_line);
	i = 0;
	if (grid_line[i] != '1')
	{
		invalid_error("Map is not closed off. Check map.");
	}
	while (grid_line[i])
	{
		if (grid_line[i] != 'E' && grid_line[i] != '0'
			&& grid_line[i] != '1' && grid_line[i] != 'C'
			&& grid_line[i] != 'P')
			invalid_error("Illegal character found in map. Check map.");
		i++;
	}
	if ((grid_line[i - 1]) != '1' || current_width != comp_width)
	{
		invalid_error("Map is not rectangular or closed off. Check map.");
	}
}

void	invalid_error(char *err_msg)
{
	ft_printf("%s\n", err_msg);
	exit(0);
}
