/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donheo <donheo@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 17:06:35 by donheo            #+#    #+#             */
/*   Updated: 2025/05/14 10:03:36 by donheo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static char	*ft_strjoin_and_free(char *s1, char *s2, int *s1_l, int *s2_l)
{
	int		i;
	char	*new_s;

	*s1_l = ft_strlen(s1);
	*s2_l = ft_strlen(s2);
	new_s = (char *)malloc((*s1_l + *s2_l + 1) * sizeof(char));
	if (!new_s)
	{
		free(s1);
		return (NULL);
	}
	i = 0;
	while (i < *s1_l)
	{
		new_s[i] = s1[i];
		i++;
	}
	while (i < *s1_l + *s2_l)
	{
		new_s[i] = s2[i - *s1_l];
		i++;
	}
	new_s[i] = '\0';
	free(s1);
	return (new_s);
}

static char	*copy_line(char *buffer, size_t *i)
{
	char	*line;

	*i = 0;
	while (buffer[*i] && buffer[*i] != '\n')
		(*i)++;
	if (buffer[*i] == '\n')
		(*i)++;
	line = ft_calloc(*i + 1, sizeof(char));
	if (!line)
		return (NULL);
	ft_memcpy(line, buffer, *i);
	return (line);
}

static char	*save_line(int fd, char *tmp_buffer)
{
	int		read_bytes;
	char	read_buffer[30];
	int		read_len;
	int		tmp_len;

	read_bytes = 1;
	while (read_bytes > 0)
	{
		read_bytes = read(fd, read_buffer, 29);
		if (read_bytes == -1)
		{
			free(tmp_buffer);
			tmp_buffer = NULL;
			return (NULL);
		}
		read_buffer[read_bytes] = '\0';
		tmp_buffer = ft_strjoin_and_free(tmp_buffer, read_buffer, \
			&tmp_len, &read_len);
		if (!tmp_buffer)
			return (NULL);
		if (ft_strchr(tmp_buffer, '\n'))
			break ;
	}
	return (tmp_buffer);
}

char	*get_next_line(int fd)
{
	static char	buffer[32];
	char		*tmp_buffer;
	char		*line;
	size_t		next_line_i;

	if (fd < 0)
		return (NULL);
	tmp_buffer = ft_strdup(buffer);
	if (!tmp_buffer)
		return (NULL);
	tmp_buffer = save_line(fd, tmp_buffer);
	if (!tmp_buffer || tmp_buffer[0] == '\0')
		return (free(tmp_buffer), NULL);
	line = copy_line(tmp_buffer, &next_line_i);
	if (!line)
		return (free(tmp_buffer), NULL);
	ft_strlcpy(buffer, tmp_buffer + next_line_i, sizeof(buffer));
	free(tmp_buffer);
	return (line);
}
