/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_3_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzammar <tzammar@student.42beirut.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 13:13:50 by tzammar           #+#    #+#             */
/*   Updated: 2026/02/04 19:24:53 by tzammar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static	void	fill(char **tab, t_point size, int row, int col)
{
	if (tab[row][col] == 'E')
		tab[row][col] = '1';
	if (row < 0 || col < 0 || row >= size.y || col >= size.x)
		return ;
	if (tab[row][col] == 'F' || tab[row][col] == '1')
		return ;
	tab[row][col] = 'F';
	fill(tab, size, row -1, col);
	fill(tab, size, row +1, col);
	fill(tab, size, row, col - 1);
	fill(tab, size, row, col + 1);
}

void	flood_fill(t_map *map)
{
	fill(map->arr, map->size, map->p.y, map->p.x);
}

static int	move_n_h(int next_y, int next_x, t_data	*data)
{
	if (data->map->arr[next_y][next_x] != '1')
	{
		if (data->map->arr[next_y][next_x] == 'C')
			return (1);
		if (data->map->arr[next_y][next_x] == 'E')
			return (1);
		if (data->map->arr[next_y][next_x] == 'P')
			return ((data->w_l = 2), 1);
		data->map->arr[next_y][next_x] = 'N';
		data->map->arr[data->map->n.y][data->map->n.x] = '0';
		data->map->n.x = next_x;
		data->map->n.y = next_y;
		return (0);
	}
	return (1);
}

int	move_n(t_data	*data)
{
	int			num;
	int			next_x;
	int			next_y;

	next_x = data->map->n.x;
	next_y = data->map->n.y;
	if (next_x != 0 && next_y != 0)
	{
		num = rand() % 4;
		if (num == 0)
			next_x--;
		if (num == 1)
			next_x++;
		if (num == 2)
			next_y--;
		if (num == 3)
			next_y++;
		if (move_n_h(next_y, next_x, data))
			move_n(data);
	}
	return (0);
}

int	handle_keypress(int keycode, t_data *data)
{
	int	next[2];

	next[0] = data->map->p.x;
	next[1] = data->map->p.y;
	if (keycode == 65307)
		close_window(data);
	if (keycode == 119 && !data->w_l)
		next[1]--;
	else if (keycode == 115 && !data->w_l)
		next[1]++;
	else if (keycode == 97 && !data->w_l)
	{
		next[0]--;
		data->p_f = 1;
	}
	else if (keycode == 100 && !data->w_l)
	{
		next[0]++;
		data->p_f = 0;
	}
	else
		return (0);
	if (!data->w_l && move_p(next[1], next[0], data))
		return (0);
	return (draw_game(data), 0);
}
