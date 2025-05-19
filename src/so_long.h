/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donheo <donheo@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 11:37:43 by donheo            #+#    #+#             */
/*   Updated: 2025/05/19 10:34:04 by donheo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>
# include "../libft/libft.h"
# include "../MLX42/include/MLX42/MLX42.h"

# define TILE_SIZE 64
# define WALL "./img/wall.png"
# define EMPTY_SPACE "./img/empty.png"
# define COLLECTIBLE "./img/colletible.png"
# define EXIT "./img/exit.png"
# define PLAYER "./img/player.png"

typedef struct s_map
{
	int		length;
	int		width;
	int		player_x;
	int		player_y;
	int		collectable;
	char	**content;
}	t_map;

typedef struct s_game
{
	t_map		*map;
	mlx_t		*mlx;
	mlx_image_t	*img_wall;
	mlx_image_t	*img_empty_space;
	mlx_image_t	*img_collectible;
	mlx_image_t	*img_exit;
	mlx_image_t	*img_player;
	int			steps;
} t_game;

int		main(int ac, char **av);
void	print_err(char *str);
void	init_map(t_map *map);
void	free_map(t_map *map);
void	free_content(char **content);
char	*without_next_line(char *str);

t_map	*check_map_validation(char *map_name);
char	*get_next_line(int fd);
int		check_chars(t_map *map, int exit_check, int player_check);
int		check_path(t_map *map);

#endif
