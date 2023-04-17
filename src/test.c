/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrask <rrask@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 09:32:04 by rrask             #+#    #+#             */
/*   Updated: 2023/04/17 09:37:32 by rrask            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void func(char *line)
{
	int		fd;
	char	*str;

	fd = open(line, O_RDONLY);
	str = get_next_line(fd);
	ft_printf("%s\n", str);
	free(str);
}

int	main(int argc, char **argv)
{

	if (argc != 2)
	{
		ft_printf("ADD THE ARGUMENT CUNT");
		return (0);
	}
	func(argv[1]);
	return (0);
}