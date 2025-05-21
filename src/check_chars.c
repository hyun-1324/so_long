/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_chars.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donheo <donheo@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 21:41:58 by donheo            #+#    #+#             */
/*   Updated: 2025/05/21 11:38:00 by donheo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	check_border(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] != '1')
			return (0);
		i++;
	}
	return (1);
}

static int	check_line(t_map *map, int line_num, int *e_check, int *p_check)
{
	int	i;

	i = 0;
	while (map->content[line_num][i])
	{
		if (map->content[line_num][i] == 'E')
			(*e_check)++;
		else if (map->content[line_num][i] == 'P')
		{
			map->player_x = i;
			map->player_y = line_num;
			(*p_check)++;
		}
		else if (map->content[line_num][i] == 'C')
			(map->collectibles)++;
		else if (map->content[line_num][i] != '1' && \
			map->content[line_num][i] != '0')
			return (0);
		i++;
	}
	return (1);
}

int	check_chars(t_map *map, int exit_check, int player_check)
{
	int	i;

	i = 0;
	if (!check_border(map->content[i]))
		return (free_map(map), print_err("invalid map border"), 0);
	i++;
	while (i < map->length - 1)
	{
		if ((map->content[i])[0] != '1' || (map->content[i])[map->width - 1] \
		!= '1')
			return (free_map(map), print_err("invalid map border"), 0);
		if (!check_line(map, i, &exit_check, &player_check))
			return (free_map(map), \
			print_err("invalid characters in map line"), 0);
		i++;
	}
	if (exit_check != 1 || player_check != 1 || map->collectibles < 1)
		return (free_map(map), print_err("invalid number of map object"), 0);
	if (!check_border(map->content[i]))
		return (free_map(map), print_err("invalid border"), 0);
	return (1);
}
