/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzammar <tzammar@student.42beirut.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 13:44:52 by tzammar           #+#    #+#             */
/*   Updated: 2026/02/04 19:24:49 by tzammar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H
# include <unistd.h>
# include <stdlib.h>
# include <time.h>
# include <sys/time.h>
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
}	t_asset;

typedef struct s_assets
{
	t_asset	e;
	t_asset	e_c;
	t_asset	p;
	t_asset	p_r;
	t_asset	c;
	t_asset	b;
	t_asset	w;
	t_asset	n;
	t_asset	y_w;
	t_asset	y_l;
}	t_assets;

typedef struct s_map
{
	char		**arr;
	int			c;
	t_point		size;
	t_point		e;
	t_point		p;
	t_point		n;
}	t_map;

typedef struct s_data
{
	void		*mlx;
	void		*mlx_win;
	int			c_c;
	int			m;
	int			p_f;
	int			w_l;
	t_map		*map;
	t_assets	assets;
}	t_data;

int		game_loop(t_data *data);
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
void	put_string(t_data	*data);
int		move_n(t_data	*data);
void	draw_map(t_data *data);
void	draw_game(t_data *data);
void	end_game(t_data *data);
void	draw_cell(t_data *data, t_point pos);
int		handle_keypress(int keycode, t_data *data);
int		move_p(int next_y, int next_x, t_data	*data);
int		check_valid_chars(t_map *map);

#endif
