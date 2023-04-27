/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_checks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrask <rrask@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 17:28:36 by rrask             #+#    #+#             */
/*   Updated: 2023/04/27 18:22:17 by rrask            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*Check the length of the following grid_line by
comparing to the comp_width set at the start.*/
void	map_rect_check(char *grid_line, int comp_width)
{
	int		i;
	int		current_width;
	
	current_width = ft_strlen(grid_line);
	i = 0;
	if (grid_line[i] != '1')
		invalid_error();
	while (grid_line[i])
	{
		// if (grid_line[i] != 'E' || grid_line[i] != '0'
		// 	|| grid_line[i] != '1' || grid_line[i] != 'C'
		// 	|| grid_line[i] != 'P')
		// 	exit(0);
		i++;
	}
	if ((grid_line[i - 1]) != '1' || current_width != comp_width)
		invalid_error();
}

void	invalid_error(void)
{
	ft_printf("Map is not closed or it is not rectangular. Check map.\n");
	exit(0);
}