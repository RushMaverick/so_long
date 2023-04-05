/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrask <rrask@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 12:40:06 by rrask             #+#    #+#             */
/*   Updated: 2023/04/05 15:28:23 by rrask            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mlx/mlx.h"
#include "../includes/libft/libft.h"

int	main(void)
{
	void	*mlx;
	void	*mlx_win;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello World");
	mlx_loop(mlx);
	return (0);
}
