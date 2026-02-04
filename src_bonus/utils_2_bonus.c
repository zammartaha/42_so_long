/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzammar <tzammar@student.42beirut.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 19:22:44 by tzammar           #+#    #+#             */
/*   Updated: 2026/02/04 19:24:52 by tzammar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

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

static void	load_asset(t_data *data, t_asset *asset, char *path)
{
	asset->ptr = mlx_xpm_file_to_image(data->mlx, path,
			&asset->size.x, &asset->size.y);
}

int	get_assets(t_data *data)
{
	load_asset(data, &data->assets.p, "./assets/p.xpm");
	load_asset(data, &data->assets.p_r, "./assets/p_r.xpm");
	load_asset(data, &data->assets.c, "./assets/c.xpm");
	load_asset(data, &data->assets.e, "./assets/e.xpm");
	load_asset(data, &data->assets.e_c, "./assets/e_c.xpm");
	load_asset(data, &data->assets.b, "./assets/b.xpm");
	load_asset(data, &data->assets.w, "./assets/w.xpm");
	load_asset(data, &data->assets.n, "./assets/n.xpm");
	load_asset(data, &data->assets.y_l, "./assets/y_l.xpm");
	load_asset(data, &data->assets.y_w, "./assets/y_w.xpm");
	if (!data->assets.p.ptr || !data->assets.p_r.ptr || !data->assets.c.ptr
		|| !data->assets.e.ptr || !data->assets.b.ptr || !data->assets.w.ptr
		|| !data->assets.n.ptr || !data->assets.e_c.ptr
		|| !data->assets.y_l.ptr || !data->assets.y_w.ptr)
	{
		ft_printf("Error\ncouldn't load assets\n");
		return (close_window(data), 1);
	}
	return (0);
}

static void	destroy_asset(t_data *data, t_asset *asset)
{
	if (asset->ptr)
		mlx_destroy_image(data->mlx, asset->ptr);
}

int	close_window(t_data *data)
{
	destroy_asset(data, &data->assets.p);
	destroy_asset(data, &data->assets.p_r);
	destroy_asset(data, &data->assets.c);
	destroy_asset(data, &data->assets.e);
	destroy_asset(data, &data->assets.e_c);
	destroy_asset(data, &data->assets.b);
	destroy_asset(data, &data->assets.w);
	destroy_asset(data, &data->assets.n);
	destroy_asset(data, &data->assets.y_w);
	destroy_asset(data, &data->assets.y_l);
	if (data->mlx_win)
		mlx_destroy_window(data->mlx, data->mlx_win);
	free_map(data->map);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	exit(0);
	return (0);
}
