/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzammar <tzammar@student.42beirut.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 19:53:34 by tzammar           #+#    #+#             */
/*   Updated: 2026/02/04 19:24:48 by tzammar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	draw_game(t_data *data)
{
	mlx_clear_window(data->mlx, data->mlx_win);
	draw_map(data);
	put_string(data);
}

void	init_map(t_map *map)
{
	map->c = 0;
	map->arr = NULL;
	map->n.x = 0;
	map->n.y = 0;
}

void	free_split(char	**arr)
{
	int	i;

	if (!arr)
		return ;
	i = 0;
	while (arr[i])
	{
		free (arr[i]);
		i++;
	}
	free (arr);
}

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
			(map->arr)[y][x] != '0' && (map->arr)[y][x] != 'N')
				return (ft_printf("Error\nnot a valid map\n%d:%d\n", y, x, 1), 1);
			x++;
		}
		y++;
	}
	return (0);
}

int	main(int argc, char *argv[])
{
	t_map	map;
	char	**arr;

	if (argc < 2)
	{
		ft_printf("Error\nNo map file provided.\n");
		return (1);
	}
	arr = ft_split(argv[1], '.');
	if (!arr[1] || ft_strncmp(arr[1], "ber", 3) != 0)
	{
		free_split(arr);
		ft_printf("Error\ninvalid file type.\n");
		return (1);
	}
	free_split(arr);
	init_map(&map);
	if (fill_map(&map, argv[1]))
		return (1);
	srand(time(NULL));
	if (render_map(&map))
		return (free_map(&map), 1);
	free_map(&map);
	return (0);
}
