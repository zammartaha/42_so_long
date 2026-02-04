/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_4_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzammar <tzammar@student.42beirut.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 22:11:38 by tzammar           #+#    #+#             */
/*   Updated: 2026/02/04 19:24:54 by tzammar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	draw_exit(t_data *data, t_point pos)
{
	if (data->c_c != data->map->c)
		mlx_put_image_to_window(data->mlx, data->mlx_win, \
data->assets.e.ptr, pos.x * 64, pos.y * 64);
	else
		mlx_put_image_to_window(data->mlx, data->mlx_win, \
data->assets.e_c.ptr, pos.x * 64, pos.y * 64);
}

static void	draw_player(t_data *data, t_point pos)
{
	if (data->p_f)
		mlx_put_image_to_window(data->mlx, data->mlx_win, \
data->assets.p.ptr, pos.x * 64, pos.y * 64);
	else
		mlx_put_image_to_window(data->mlx, data->mlx_win, \
data->assets.p_r.ptr, pos.x * 64, pos.y * 64);
}

void	end_game(t_data *data)
{
	int	x;
	int	y;

	x = data->map->size.x / 2 - 1;
	y = data->map->size.y / 2 - 1;
	if (data->w_l == 1)
		mlx_put_image_to_window(data->mlx, data->mlx_win, \
data->assets.y_w.ptr, x * 64, y * 64);
	else
		mlx_put_image_to_window(data->mlx, data->mlx_win, \
data->assets.y_l.ptr, x * 64, y * 64);
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
	else if (cell == 'N')
		mlx_put_image_to_window(data->mlx, data->mlx_win, \
data->assets.n.ptr, pos.x * 64, pos.y * 64);
}

void	put_string(t_data *data)
{
	char	*moves_str;
	char	*total_moves_str;

	moves_str = ft_itoa(data->m);
	total_moves_str = ft_strjoin("Moves: ", moves_str);
	mlx_string_put(data->mlx, data->mlx_win, 3, \
15, 0xFFFFFF, total_moves_str);
	mlx_string_put(data->mlx, data->mlx_win, 7, \
15, 0xFFFFFF, total_moves_str);
	mlx_string_put(data->mlx, data->mlx_win, 5, \
13, 0xFFFFFF, total_moves_str);
	mlx_string_put(data->mlx, data->mlx_win, 5, \
17, 0xFFFFFF, total_moves_str);
	mlx_string_put(data->mlx, data->mlx_win, 5, \
15, 0x000000, total_moves_str);
	free(moves_str);
	free(total_moves_str);
}
