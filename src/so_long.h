/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzammar <tzammar@student.42beirut.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 13:44:52 by tzammar           #+#    #+#             */
/*   Updated: 2026/02/04 19:24:33 by tzammar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include <unistd.h>
# include <stdlib.h>
# include "mlx.h"
# include "libft.h"
# include "get_next_line.h"
# include "ft_printf.h"

typedef struct s_point
{
	int	x;
	int	y;
}	t_point;

typedef struct s_asset
{
	void		*ptr;
	t_point		size;
	t_point		pos;
}	t_asset;

typedef struct s_assets
{
	t_asset	e;
	t_asset	p;
	t_asset	c;
	t_asset	b;
	t_asset	w;
}	t_assets;

typedef struct s_map
{
	char		**arr;
	int			c;
	t_point		size;
	t_point		e;
	t_point		p;
}	t_map;

typedef struct s_data
{
	void		*mlx;
	void		*mlx_win;
	int			c_c;
	int			m;
	t_map		*map;
	t_assets	assets;
}	t_data;

void	init_map(t_map *map);
void	init_point(t_point *point);
int		fill_map(t_map *map, char	*map_name);
void	free_map(t_map *map);
void	flood_fill(t_map *map);
int		dup_map(t_map *temp_map, t_map *map);
int		validate_map(t_map *map);
int		render_map(t_map *map);
int		get_assets(t_data *data);
int		close_window(t_data *data);
void	draw_cell(t_data *data, t_point pos);
int		check_valid_chars(t_map *map);

#endif
