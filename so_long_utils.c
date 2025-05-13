/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donheo <donheo@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 20:15:56 by donheo            #+#    #+#             */
/*   Updated: 2025/05/13 23:51:42 by donheo           ###   ########.fr       */
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

char	*ft_strjoin_and_free(char *buffer, \
		char const *tmp_buffer, int *buffer_len, int *tmp_len)
{
	int		i;
	char	*new_s;

	*buffer_len = ft_strlen(buffer);
	*tmp_len = ft_strlen(tmp_buffer);
	new_s = (char *)malloc((*buffer_len + *tmp_len + 1) * sizeof(char));
	if (!new_s)
	{
		free(buffer);
		return (NULL);
	}
	i = 0;
	while (i < *buffer_len)
	{
		new_s[i] = buffer[i];
		i++;
	}
	while (i < *buffer_len + *tmp_len)
	{
		new_s[i] = tmp_buffer[i - *buffer_len];
		i++;
	}
	new_s[i] = '\0';
	free(buffer);
	return (new_s);
}
