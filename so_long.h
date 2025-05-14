/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donheo <donheo@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 11:37:43 by donheo            #+#    #+#             */
/*   Updated: 2025/05/14 10:05:05 by donheo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>
# include "libft/libft.h"

typedef struct s_map
{
	int		length;
	int		width;
	int		player_x;
	int		player_y;
	int		collectable;
	char	**content;


}	t_map;

int		main(int ac, char **av);
void	print_err(char *str);
void	init_map(t_map *map);
void	free_map(t_map *map);
void	free_content(char **content);

t_map	*check_map_validation(char *map_name);
char	*get_next_line(int fd);
char	*ft_strjoin_and_free(char *buffer, \
		char const *tmp_buffer, int *buffer_len, int *tmp_len);
int		check_chars(t_map *map, int exit_check, int player_check);
int		check_path(t_map *map);

#endif
