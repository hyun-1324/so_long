/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donheo <donheo@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 11:56:49 by donheo            #+#    #+#             */
/*   Updated: 2025/05/13 17:08:59 by donheo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	count_length_and_width(t_map *map, char *map_name)
{
	int	fd;
	int	count_width;
	char	*line;

	fd = open(map_name, O_RDONLY);
	if (fd < 0)
		return (0);
	while ((line = get_next_line(fd)) != NULL)
	{
		(map->length)++;
		count_width = ft_strlen(line);
		if (count_width >= 3 || map->width != 0)
		{
			if (count_width != map->width)
				return (close(fd), 0);
		}
		else if (count_width >= 3 || map->width == 0)
			map->width = count_width;
		else
			return (close(fd), 0);
	}
	if (map->length < 3 || map->width < 3)
		return (close(fd), 0);
	return (close(fd), 1);
}

int	check_extension(char *map)
{
	int	len;

	len = ft_strlen(map);
	if (len > 4 && ft_strncmp(&map[len - 4], ".ber", 4) == 0)
		return (1);
	return (0);
}

void	init_map(t_map *map)
{
	map->length = 0;
	map->width = 0;
}

t_map	*check_map_validation(char *map_name)
{
	char	*map;
	int		is_valid_map;

	if (!check_extension(map_name))
		print_error("Invalid file name");
	map = ft_calloc(1, sizeof(t_map));
	if (!map)
		print_error("memory allocation fails");
	init_map(map);
	is_valid_map = count_length_and_width(map, map_name);
	if (!is_valid_map)
		return (free(map), print_error("Invalid map"));



}
