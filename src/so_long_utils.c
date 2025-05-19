/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donheo <donheo@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 20:15:56 by donheo            #+#    #+#             */
/*   Updated: 2025/05/14 11:29:34 by donheo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_err(char *str)
{
	if (str)
		write(2, str, ft_strlen(str));
	write(2, "\n", 1);
	exit(1);
}

void	init_map(t_map *map)
{
	map->length = 0;
	map->width = 0;
	map->collectable = 0;
	map->player_x = 0;
	map->player_y = 0;
	map->content = NULL;
}

void	free_map(t_map *map)
{
	int	i;

	i = 0;
	if (!map)
		return ;
	if (map->content)
	{
		while (map->content[i])
		{
			free(map->content[i]);
			i++;
		}
		free(map->content);
	}
	free(map);
}

void	free_content(char **content)
{
	int	i;

	i = 0;
	if (content)
	{
		while (content[i])
		{
			free(content[i]);
			i++;
		}
		free(content);
	}
}

char	*without_next_line(char *str)
{
	int	len;

	if (!str)
		return (NULL);
	len = ft_strlen(str);
	if (len > 0 && str[len - 1] == '\n')
		str[len - 1] = '\0';
	return (str);
}
