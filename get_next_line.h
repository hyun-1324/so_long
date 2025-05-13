/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donheo <donheo@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 17:08:24 by donheo            #+#    #+#             */
/*   Updated: 2025/04/25 23:49:43 by donheo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdlib.h>
# include <unistd.h>
# include <stdint.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

char	*ft_strchr(const char *s, int c);
int		ft_strlen(const char *str);
void	*ft_memmove(void *dest, const void *src, size_t n);
char	*ft_strjoin_and_free(char *buffer, \
		char const *tmp_buffer, int *buffer_len, int *tmp_len);
void	*ft_calloc(size_t nmemb, size_t size);

void	delete_copied_line(char **buffer, size_t *i);
char	*copy_line(char **buffer, size_t *i);
char	*save_lines(int fd, char *buffer, char *tmp_buffer);
void	save_file(int fd, char **buffer);
char	*get_next_line(int fd);

#endif
