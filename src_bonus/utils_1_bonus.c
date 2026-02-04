/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_1_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzammar <tzammar@student.42beirut.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 00:34:26 by tzammar           #+#    #+#             */
/*   Updated: 2026/02/04 19:24:51 by tzammar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static int	get_fd(char	*map_name, int	*fd)
{
	*fd = open(map_name, O_RDONLY);
	if (*fd < 0)
		return (ft_printf("Error\ncould not open map\n"), 1);
	return (0);
}

static int	get_size(int fd, t_map *map)
{
	char	*str;

	str = get_next_line(fd);
	if (!str)
		return (ft_printf("Error\nempty map\n"), 1);
	map->size.x = ft_strlen(str);
	map->size.y = 0;
	while (str)
	{
		if (map->size.x != (int)ft_strlen(str))
		{
			free(str);
			return (ft_printf("Error\nmap is not rectangular\n"), 1);
		}
		map->size.y = map->size.y + 1;
		free(str);
		str = get_next_line(fd);
	}
	ft_printf("map size is: x = %d, y = %d\n", map->size.x, map->size.y);
	return (0);
}

static int	malloc_copy(int fd, t_map *map)
{
	int	j;

	map->arr = malloc(sizeof(char *) * map->size.y);
	if (!(map->arr))
		return (ft_printf("Error\nmalloc\n"), 1);
	j = 0;
	while (j < map->size.y)
	{
		(map->arr)[j] = get_next_line(fd);
		if (!(map->arr)[j])
		{
			while (j >= 0)
				free((map->arr)[--j]);
			return (free(map->arr), ft_printf("Error\nmalloc\n"), 1);
		}
		j++;
	}
	return (0);
}

void	free_map(t_map *map)
{
	int	j;

	j = 0;
	while (j < map->size.y)
		free((map->arr)[j++]);
	free(map->arr);
}

int	fill_map(t_map *map, char	*map_name)
{
	int		fd1;
	int		fd2;

	if (get_fd(map_name, &fd1) || get_fd(map_name, &fd2))
		return (1);
	if (get_size(fd1, map))
		return (close (fd1), close (fd2), 1);
	if (malloc_copy(fd2, map))
		return (close (fd1), close (fd2), free_map(map), 1);
	close (fd1);
	close (fd2);
	if (validate_map(map))
		return (free_map(map), 1);
	return (0);
}
