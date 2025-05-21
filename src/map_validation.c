/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donheo <donheo@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 11:56:49 by donheo            #+#    #+#             */
/*   Updated: 2025/05/21 11:38:01 by donheo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	process_map_line(t_map *map, char *line)
{
	int	count_width;

	map->length++;
	count_width = ft_strlen(line);
	if (count_width >= 3 && map->width != 0)
	{
		if (count_width != map->width)
			return (0);
	}
	else if (count_width >= 3 && map->width == 0)
		map->width = count_width;
	else
		return (0);
	return (1);
}

static int	count_length_and_width(t_map *map, char *map_name, int *last_line)
{
	int		fd;
	char	*line;

	fd = open(map_name, O_RDONLY);
	if (fd < 0)
		return (free(map), print_err("failed to open map file"), 0);
	line = without_next_line(get_next_line(fd, map), last_line);
	if (!line)
		return (close(fd), free(map), print_err("failed to read a line"), 0);
	while (line)
	{
		if (!process_map_line(map, line))
			return (free(line), close(fd), free(map), \
			print_err("Invalid map: inconsistent width"), 0);
		free(line);
		if (*last_line)
			break ;
		line = without_next_line(get_next_line(fd, map), last_line);
	}
	return (close(fd), 1);
}

static int	check_extension(char *map_name)
{
	int	len;
	int	fd;

	fd = open(map_name, O_RDONLY | O_DIRECTORY);
	if (fd != -1)
	{
		close(fd);
		return (0);
	}
	fd = open(map_name, O_RDONLY);
	if (fd == -1)
		return (0);
	len = ft_strlen(map_name);
	if (len > 4 && ft_strncmp(&map_name[len - 4], ".ber", 4) == 0)
		return (close(fd), 1);
	return (close(fd), 0);
}

static int	save_map(t_map *map, char *map_name, int *last_line)
{
	int		fd;
	int		i;
	char	*line;

	fd = open(map_name, O_RDONLY);
	if (fd < 0)
		return (free(map), \
		print_err("failed to reopen the file for map content"), 0);
	i = 0;
	while (i < map->length)
	{
		line = without_next_line(get_next_line(fd, map), last_line);
		if (!line)
			return (close(fd), 0);
		map->content[i] = ft_strdup(line);
		if (!map->content[i])
			return (free(line), close(fd), 0);
		free(line);
		i++;
		if (*last_line)
			break ;
	}
	map->content[i] = NULL;
	close(fd);
	return (1);
}

t_map	*check_map_validation(char *map_name)
{
	t_map	*map;
	int		last_line;

	if (!check_extension(map_name))
		print_err("invalid file");
	map = ft_calloc(1, sizeof(t_map));
	if (!map)
		print_err("failed to allocate memory for map structure");
	init_map(map);
	last_line = 0;
	count_length_and_width(map, map_name, &last_line);
	if (map->length < 3 || map->width < 3 || map->length * \
		TILE_SIZE > MONITOR_LENGTH || map->width * TILE_SIZE > MONITOR_WIDTH)
		return (free(map), print_err("invalid map: size too \
			small or exceeds monitor"), NULL);
	map->content = calloc(map->length + 1, sizeof(char *));
	if (!map->content)
		return (free(map), \
		print_err("failed to allocate memory for map content"), NULL);
	last_line = 0;
	if (!save_map(map, map_name, &last_line))
		return (free_map(map), print_err("fail to save lines to memory"), NULL);
	check_chars(map, 0, 0);
	check_path(map);
	return (map);
}
