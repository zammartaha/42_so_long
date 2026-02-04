/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzammar <tzammar@student.42beirut.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 19:22:44 by tzammar           #+#    #+#             */
/*   Updated: 2026/02/04 19:24:37 by tzammar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_map(t_map *map)
{
	map->c = 0;
	map->arr = NULL;
}

int	dup_map(t_map *temp_map, t_map *map)
{
	int	j;

	temp_map->e = (t_point){map->e.x, map->e.y};
	temp_map->p = (t_point){map->p.x, map->p.y};
	temp_map->c = map->c;
	temp_map->size.x = map->size.x;
	temp_map->size.y = map->size.y;
	temp_map->arr = malloc(sizeof(char *) * temp_map->size.y);
	if (!(temp_map->arr))
		return (ft_printf("Error\nmalloc\n"), 1);
	j = 0;
	while (j < temp_map->size.y)
	{
		temp_map->arr[j] = malloc(sizeof(char *) * temp_map->size.x + 2);
		if (!temp_map->arr[j])
		{
			while (--j >= 0)
				free(temp_map->arr[j]);
			free(temp_map->arr);
			return (ft_printf("Error\nmalloc\n"), 1);
		}
		ft_strlcpy((temp_map->arr)[j], (map->arr)[j], map->size.x + 2);
		j++;
	}
	return (0);
}

int	get_assets(t_data *data)
{
	data->assets.p.ptr = mlx_xpm_file_to_image(data->mlx, "./assets/p.xpm"\
, &data->assets.p.size.x, &data->assets.p.size.y);
	data->assets.c.ptr = mlx_xpm_file_to_image(data->mlx, "./assets/c.xpm"\
, &data->assets.c.size.x, &data->assets.c.size.y);
	data->assets.e.ptr = mlx_xpm_file_to_image(data->mlx, "./assets/e.xpm"\
, &data->assets.e.size.x, &data->assets.e.size.y);
	data->assets.b.ptr = mlx_xpm_file_to_image(data->mlx, "./assets/b.xpm"\
, &data->assets.b.size.x, &data->assets.b.size.y);
	data->assets.w.ptr = mlx_xpm_file_to_image(data->mlx, "./assets/w.xpm"\
, &data->assets.w.size.x, &data->assets.w.size.y);
	if (!data->assets.p.ptr || !data->assets.c.ptr || !data->assets.e.ptr
		|| !data->assets.b.ptr || !data->assets.w.ptr)
	{
		ft_printf("Error\ncouldn't load asstes\n");
		return (close_window(data), 1);
	}
	return (0);
}

int	close_window(t_data *data)
{
	if (data->assets.p.ptr)
		mlx_destroy_image(data->mlx, data->assets.p.ptr);
	if (data->assets.c.ptr)
		mlx_destroy_image(data->mlx, data->assets.c.ptr);
	if (data->assets.e.ptr)
		mlx_destroy_image(data->mlx, data->assets.e.ptr);
	if (data->assets.b.ptr)
		mlx_destroy_image(data->mlx, data->assets.b.ptr);
	if (data->assets.w.ptr)
		mlx_destroy_image(data->mlx, data->assets.w.ptr);
	if (data->mlx_win)
		mlx_destroy_window(data->mlx, data->mlx_win);
	free_map(data->map);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	exit(0);
	return (0);
}
