/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_paths.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donheo <donheo@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 22:12:25 by donheo            #+#    #+#             */
/*   Updated: 2025/05/14 10:07:12 by donheo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	flood_fill(char **copy_content, t_map *map, int x, int y)
{
	if (x < 0 || y < 0 || x >= map->width || y >= map->length \
		|| copy_content[y][x] == '1')
		return ;
	copy_content[y][x] = '1';
	flood_fill(copy_content, map, x + 1, y);
	flood_fill(copy_content, map, x - 1, y);
	flood_fill(copy_content, map, x, y + 1);
	flood_fill(copy_content, map, x, y - 1);
}

static int	check_content(char **content)
{
	int	i;
	int	j;

	i = 0;
	while (content[i])
	{
		j = 0;
		while (content[i][j])
		{
			if (content[i][j] != '0' && content[i][j] != '1')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	check_path(t_map *map)
{
	char	**copy_content;
	int		i;

	copy_content = ft_calloc(map->length + 1, sizeof(char *));
	if (!copy_content)
		return (free_map(map), \
		print_err("fail to allocate memory for copy content"), 0);
	i = 0;
	while (i < map->length)
	{
		copy_content[i] = ft_strdup(map->content[i]);
		if (!copy_content[i])
			return (free_content(copy_content), free_map(map), \
			print_err("fail to allocate memory for copy content"), 0);
		i++;
	}
	flood_fill(copy_content, map, map->player_x, map->player_y);
	if (!check_content(copy_content))
		return (free_content(copy_content), 0);
	free_content(copy_content);
	return (1);
}
