/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzammar <tzammar@student.42beirut.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 20:37:06 by tzammar           #+#    #+#             */
/*   Updated: 2026/02/04 19:24:29 by tzammar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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

static int	move_p(int next_y, int next_x, t_data	*data)
{
	if (next_x < 0 || next_x >= data->map->size.x || next_y < 0
		|| next_y >= data->map->size.y)
		return (1);
	if (data->map->arr[next_y][next_x] == '1')
		return (1);
	if (data->map->arr[next_y][next_x] == 'C')
		data->c_c++;
	if (data->map->arr[next_y][next_x] == 'E' && data->c_c == data->map->c)
		close_window(data);
	if (data->map->arr[next_y][next_x] == 'E' && data->c_c != data->map->c)
		return (1);
	data->map->arr[next_y][next_x] = 'P';
	data->map->arr[data->map->p.y][data->map->p.x] = '0';
	data->map->p.x = next_x;
	data->map->p.y = next_y;
	data->m++;
	ft_printf("number of moves = %d\n", data->m);
	return (0);
}

static int	handle_keypress(int keycode, t_data *data)
{
	int	next_x;
	int	next_y;

	next_x = data->map->p.x;
	next_y = data->map->p.y;
	if (keycode == 65307)
		close_window(data);
	if (keycode == 119)
		next_y--;
	else if (keycode == 115)
		next_y++;
	else if (keycode == 97)
		next_x--;
	else if (keycode == 100)
		next_x++;
	else
		return (0);
	if (move_p(next_y, next_x, data))
		return (0);
	return (draw_map(data), 0);
}

int	render_map(t_map *map)
{
	t_data	data;

	data.map = map;
	data.c_c = 0;
	data.m = 0;
	data.mlx = mlx_init();
	data.mlx_win = mlx_new_window(data.mlx, 64 * map->size.x,
			64 * map->size.y, "so_long");
	if (get_assets(&data))
		return (1);
	mlx_hook(data.mlx_win, 2, 1L << 0, handle_keypress, &data);
	mlx_hook(data.mlx_win, 17, 0, close_window, &data);
	draw_map(&data);
	mlx_loop(data.mlx);
	return (0);
}
