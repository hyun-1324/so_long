/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_chars.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donheo <donheo@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 21:41:58 by donheo            #+#    #+#             */
/*   Updated: 2025/05/13 23:38:51 by donheo           ###   ########.fr       */
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

static void	check_line(t_map *map, int line_num, int *exit_check, int *player_check, int *collect_check)
{
	int	i;

	i = 0;
	while (map->content[line_num][i])
	{
		if (map->content[line_num][i] == 'E')
			(*exit_check)++;
		else if (map->content[line_num][i] == 'P')
		{
			map->player_x = i;
			map->player_y = line_num;
			(*player_check)++;
		}
		else if (map->content[line_num][i] == 'C')
			(*collect_check)++;
		i++;
	}
}

int check_chars(t_map *map, int exit_check, int player_check, int collect_check)
{
	int	i;

	i = 0;
	if (!check_border(map->content[i]))
		return (0);
	i++;
	while (i < map->length - 1)
	{
		if ((map->content[i])[0] != '1' || (map->content[i])[map->width - 1] != '1')
			return (0);
		check_line(map, i, &exit_check, &player_check, &collect_check);
		i++;
	}
	if (exit_check != 1 || player_check != 1 || collect_check < 1)
		return (0);
	if (!check_border(map->content[i]))
		return (0);
	return (1);
}
