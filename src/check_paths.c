/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_paths.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donheo <donheo@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 22:12:25 by donheo            #+#    #+#             */
/*   Updated: 2025/05/21 11:46:02 by donheo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	flood_fill(char **map_copy, t_map *map, int x, int y)
{
	if (x < 0 || y < 0 || x >= map->width || y >= map->length \
		|| map_copy[y][x] == '1')
		return ;
	map_copy[y][x] = '1';
	flood_fill(map_copy, map, x + 1, y);
	flood_fill(map_copy, map, x - 1, y);
	flood_fill(map_copy, map, x, y + 1);
	flood_fill(map_copy, map, x, y - 1);
}

static int	check_all_reachable(char **map_copy)
{
	int	i;
	int	j;

	i = 0;
	while (map_copy[i])
	{
		j = 0;
		while (map_copy[i][j])
		{
			if (map_copy[i][j] != '0' && map_copy[i][j] != '1')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	check_path(t_map *map)
{
	char	**map_copy;
	int		i;

	map_copy = ft_calloc(map->length + 1, sizeof(char *));
	if (!map_copy)
		return (free_map(map), \
		print_err("failed to allocate memory for map copy"), 0);
	i = 0;
	while (i < map->length)
	{
		map_copy[i] = ft_strdup(map->content[i]);
		if (!map_copy[i])
			return (free_content(map_copy), free_map(map), \
			print_err("failed to allocate memory for map copy"), 0);
		i++;
	}
	flood_fill(map_copy, map, map->player_x, map->player_y);
	if (!check_all_reachable(map_copy))
		return (free_content(map_copy), free_map(map), \
		print_err("invalid map path: : unreachable collectibles or exit"), 0);
	free_content(map_copy);
	return (1);
}
