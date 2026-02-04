/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzammar <tzammar@student.42beirut.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 19:53:34 by tzammar           #+#    #+#             */
/*   Updated: 2026/02/04 19:24:31 by tzammar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_split(char	**arr)
{
	int	i;

	if (!arr)
		return ;
	i = 0;
	while (arr[i])
	{
		free (arr[i]);
		i++;
	}
	free (arr);
}

int	main(int argc, char *argv[])
{
	t_map	map;
	char	**arr;

	if (argc < 2)
	{
		ft_printf("Error\nNo map file provided.\n");
		return (1);
	}
	arr = ft_split(argv[1], '.');
	if (!arr[1] || ft_strncmp(arr[1], "ber", 3) != 0)
	{
		free_split(arr);
		ft_printf("Error\ninvalid file type.\n");
		return (1);
	}
	free_split(arr);
	init_map(&map);
	if (fill_map(&map, argv[1]))
		return (1);
	if (render_map(&map))
		return (free_map(&map), 1);
	free_map(&map);
	return (0);
}
