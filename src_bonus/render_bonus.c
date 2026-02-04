/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzammar <tzammar@student.42beirut.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 20:37:06 by tzammar           #+#    #+#             */
/*   Updated: 2026/02/04 19:24:46 by tzammar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	game_loop(t_data *data)
{
	static long long	last_move_time = 0;
	struct timeval		tv;
	long long			current_time;

	gettimeofday(&tv, NULL);
	current_time = ((long long)tv.tv_sec * 1000) + (tv.tv_usec / 1000);
	if (current_time - last_move_time >= 500 && !data->w_l)
	{
		move_n(data);
		draw_game(data);
		last_move_time = current_time;
	}
	else if (data->w_l == 1 || data->w_l == 2)
	{
		end_game(data);
	}
	return (0);
}

void	draw_map(t_data *data)
{
	t_point	pos;

	pos.y = 0;
	while (pos.y < data->map->size.y)
	{
		pos.x = 0;
		while (pos.x < data->map->size.x)
		{
			draw_cell(data, pos);
			pos.x++;
		}
		pos.y++;
	}
}

int	move_p(int next_y, int next_x, t_data	*data)
{
	if (next_x < 0 || next_x >= data->map->size.x || next_y < 0
		|| next_y >= data->map->size.y)
		return (1);
	if (data->map->arr[next_y][next_x] == '1')
		return (1);
	if (data->map->arr[next_y][next_x] == 'N')
		return ((data->w_l = 2), 1);
	if (data->map->arr[next_y][next_x] == 'C')
		data->c_c++;
	if (data->map->arr[next_y][next_x] == 'E' && data->c_c == data->map->c)
		return ((data->w_l = 1), 1);
	if (data->map->arr[next_y][next_x] == 'E' && data->c_c != data->map->c)
		return (1);
	data->map->arr[next_y][next_x] = 'P';
	data->map->arr[data->map->p.y][data->map->p.x] = '0';
	data->map->p.x = next_x;
	data->map->p.y = next_y;
	data->m++;
	return (0);
}

int	render_map(t_map *map)
{
	t_data	data;

	data.map = map;
	data.c_c = 0;
	data.m = 0;
	data.p_f = 0;
	data.w_l = 0;
	data.mlx = mlx_init();
	data.mlx_win = mlx_new_window(data.mlx, 64 * map->size.x,
			64 * map->size.y, "so_long_bonus");
	if (get_assets(&data))
		return (1);
	mlx_hook(data.mlx_win, 2, 1L << 0, handle_keypress, &data);
	mlx_hook(data.mlx_win, 17, 0, close_window, &data);
	mlx_loop_hook(data.mlx, game_loop, &data);
	draw_game(&data);
	mlx_loop(data.mlx);
	return (0);
}
