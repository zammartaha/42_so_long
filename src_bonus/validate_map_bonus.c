/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzammar <tzammar@student.42beirut.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 00:36:45 by tzammar           #+#    #+#             */
/*   Updated: 2026/02/04 19:24:55 by tzammar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static int	check_walls(t_map *map)
{
	int	j;
	int	i;

	j = 0;
	while (j < map->size.y)
	{
		if (j == 0 || j == (map->size.y - 1))
		{
			i = 0;
			while (i < map->size.x)
			{
				if ((map->arr)[j][i] != '1')
					return (ft_printf("Error\nnot a valid map\n"), 1);
				i++;
			}
		}
		if ((map->arr)[j][0] != '1' || (map->arr)[j][map->size.x - 1] != '1')
			return (ft_printf("Error\nnot a valid map\n"), 1);
		j++;
	}
	return (0);
}

static int	check_elements(t_map *map)
{
	int	x;
	int	y;
	int	p;
	int	e;

	y = 0;
	p = 0;
	e = 0;
	while (y < map->size.y)
	{
		x = 0;
		while (x < map->size.x)
		{
			if ((map->arr)[y][x] == 'E')
				e++;
			if ((map->arr)[y][x] == 'P')
				p++;
			if ((map->arr)[y][x++] == 'C')
				(map->c)++;
		}
		y++;
	}
	if (e != 1 || p != 1 || map->c < 1)
		return (ft_printf("Error\nnot a valid map\n"), 1);
	return (0);
}

static void	set_element_location(t_map *map)
{
	int	x;
	int	y;

	y = 0;
	while (y < map->size.y)
	{
		x = 0;
		while (x < map->size.x)
		{
			if ((map->arr)[y][x] == 'E')
				map->e = (t_point){x, y};
			if ((map->arr)[y][x] == 'P')
				map->p = (t_point){x, y};
			if ((map->arr)[y][x] == 'N')
				map->n = (t_point){x, y};
			x++;
		}
		y++;
	}
	return ;
}

static int	check_valid_path(t_map *map)
{
	int	y;
	int	x;

	flood_fill(map);
	y = 0;
	while (y < map->size.y)
	{
		x = 0;
		while (x < map->size.x)
		{
			if ((map->arr)[y][x] == 'E' || (map->arr)[y][x] == 'C' )
				return (ft_printf("Error\nnot a valid map\n"), 1);
			x++;
		}
		y++;
	}
	ft_printf("\n");
	return (0);
}

int	validate_map(t_map *map)
{
	t_map	temp_map;

	if (check_valid_chars(map))
		return (1);
	if (check_walls(map))
		return (1);
	if (check_elements(map))
		return (1);
	if (dup_map(&temp_map, map))
		return (1);
	set_element_location(map);
	set_element_location(&temp_map);
	if (check_valid_path(&temp_map))
		return (free_map(&temp_map), 1);
	free_map(&temp_map);
	return (0);
}
