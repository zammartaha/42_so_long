/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzammar <tzammar@student.42beirut.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 00:53:07 by tzammar           #+#    #+#             */
/*   Updated: 2026/02/04 19:24:39 by tzammar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_valid_chars(t_map *map)
{
	int	y;
	int	x;

	y = 0;
	while (y < map->size.y)
	{
		x = 0;
		while (x < map->size.x)
		{
			if ((map->arr)[y][x] != 'E' && (map->arr)[y][x] != 'P' && \
			(map->arr)[y][x] != 'C' && (map->arr)[y][x] != '1' && \
			(map->arr)[y][x] != '0')
				return (ft_printf("Error\nnot a valid map\n%d:%d\n", y, x, 1), 1);
			x++;
		}
		y++;
	}
	return (0);
}
