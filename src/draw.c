/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzammar <tzammar@student.42beirut.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 22:11:38 by tzammar           #+#    #+#             */
/*   Updated: 2026/02/04 19:24:26 by tzammar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	draw_exit(t_data *data, t_point pos)
{
	mlx_put_image_to_window(data->mlx, data->mlx_win, \
data->assets.e.ptr, pos.x * 64, pos.y * 64);
}

static void	draw_player(t_data *data, t_point pos)
{
	mlx_put_image_to_window(data->mlx, data->mlx_win, \
data->assets.p.ptr, pos.x * 64, pos.y * 64);
}

void	draw_cell(t_data *data, t_point pos)
{
	char	cell;

	cell = data->map->arr[pos.y][pos.x];
	mlx_put_image_to_window(data->mlx, data->mlx_win, \
data->assets.b.ptr, pos.x * 64, pos.y * 64);
	if (cell == '1')
		mlx_put_image_to_window(data->mlx, data->mlx_win, \
data->assets.w.ptr, pos.x * 64, pos.y * 64);
	else if (cell == 'C')
		mlx_put_image_to_window(data->mlx, data->mlx_win, \
data->assets.c.ptr, pos.x * 64, pos.y * 64);
	else if (cell == 'E')
		draw_exit(data, pos);
	else if (cell == 'P')
		draw_player(data, pos);
}
