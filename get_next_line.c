/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donheo <donheo@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 17:06:35 by donheo            #+#    #+#             */
/*   Updated: 2025/05/14 00:59:44 by donheo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	delete_copied_line(char **buffer, size_t *len)
{
	int		rest_len;
	char	*bzero_char;
	size_t	bzero_i;

	rest_len = ft_strlen(*buffer + *len);
	ft_memmove(*buffer, *buffer + *len, rest_len + 1);
	bzero_char = *buffer + rest_len + 1;
	bzero_i = 0;
	while (bzero_i < *len)
	{
		bzero_char[bzero_i] = '\0';
		bzero_i++;
	}
}

static char	*copy_line(char **buffer, size_t *i)
{
	char	*line;

	*i = 0;
	while ((*buffer)[*i] && (*buffer)[*i] != '\n')
		(*i)++;
	if ((*buffer)[*i] == '\n')
		(*i)++;
	line = ft_calloc(*i + 1, sizeof(char));
	if (!line)
	{
		free(*buffer);
		return (NULL);
	}
	*i = 0;
	while ((*buffer)[*i] && (*buffer)[*i] != '\n')
	{
		line[*i] = (*buffer)[*i];
		(*i)++;
	}
	if ((*buffer)[*i] && (*buffer)[*i] == '\n')
		line[(*i)++] = '\n';
	return (line);
}

static char	*save_lines(int fd, char *buffer, char *tmp_buffer)
{
	int	read_bytes;
	int	buffer_len;
	int	tmp_len;

	read_bytes = 1;
	while (read_bytes > 0)
	{
		read_bytes = read(fd, tmp_buffer, 29);
		if (read_bytes == -1)
		{
			free(buffer);
			return (NULL);
		}
		tmp_buffer[read_bytes] = 0;
		buffer = ft_strjoin_and_free(buffer, tmp_buffer, &buffer_len, &tmp_len);
		if (!buffer)
			return (NULL);
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	return (buffer);
}

static void	save_file(int fd, char **buffer)
{
	char	*tmp_buffer;

	if (!*buffer)
		*buffer = ft_calloc(1, 1);
	if (!*buffer)
		return ;
	tmp_buffer = malloc((30) * sizeof(char));
	if (!tmp_buffer)
	{
		free(*buffer);
		*buffer = NULL;
		return ;
	}
	*buffer = save_lines(fd, *buffer, tmp_buffer);
	free(tmp_buffer);
	if (*buffer && (*buffer)[0] == '\0')
	{
		free(*buffer);
		*buffer = NULL;
	}
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;
	size_t		next_line_i;

	if (fd < 0)
		return (NULL);
	save_file(fd, &buffer);
	if (!buffer)
		return (NULL);
	line = copy_line(&buffer, &next_line_i);
	if (!line)
		return (NULL);
	delete_copied_line(&buffer, &next_line_i);
	return (line);
}
