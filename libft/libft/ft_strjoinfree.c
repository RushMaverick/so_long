/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoinfree.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrask <rrask@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 09:21:41 by rrask             #+#    #+#             */
/*   Updated: 2023/04/24 10:34:12 by rrask            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	istheres(char *joined, char const *s1, char const *s2)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s1[i] != '\0')
	{
		joined[j] = s1[i];
		i++;
		j++;
	}
	i = 0;
	while (s2[i] != '\0')
	{
		joined[j] = s2[i];
		i++;
		j++;
	}
	joined[j] = '\0';
}

char	*ft_strjoinfree(char const *buf, char const *read_buf)
{
	char	*joined;

	joined = ft_calloc(ft_strlen(buf) + ft_strlen(read_buf) + 1, sizeof(char));
	if (!joined)
		return (NULL);
	istheres(joined, buf, read_buf);
	free((void *)buf);
	return (joined);
}
