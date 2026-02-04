/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzammar <tzammar@student.42beirut.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 13:13:50 by tzammar           #+#    #+#             */
/*   Updated: 2026/02/04 19:24:28 by tzammar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
