/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donheo <donheo@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 11:37:43 by donheo            #+#    #+#             */
/*   Updated: 2025/05/24 17:36:02 by donheo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <fcntl.h>
# include "libft.h"
# include "MLX42.h"

// Constants for rendering
# define TILE_SIZE 64
# define MONITOR_WIDTH 3840
# define MONITOR_LENGTH 2048

// Texture paths
# define WALL "./textures/wall.png"
# define FLOOR "./textures/floor.png"
# define COLLECTIBLE "./textures/collectible.png"
# define EXIT "./textures/exit.png"
# define PLAYER "./textures/player.png"

// Struct to store map information
typedef struct s_map
{
	int		length;
	int		width;
	int		player_x;
	int		player_y;
	int		collectibles;
	char	**content;
}	t_map;

// Struct to store game state and resources
typedef struct s_game
{
	t_map		*map;
	mlx_t		*mlx;
	mlx_image_t	*img_wall;
	mlx_image_t	*img_floor;
	mlx_image_t	*img_collectible;
	mlx_image_t	*img_exit;
	mlx_image_t	*img_player;
	int			steps;
	int			collectibles;
}	t_game;

// Core functions and memory/error handling
int		main(int ac, char **av);
void	print_err(char *str);
void	free_map(t_map *map);
void	free_content(char **content);

// Map validation helpers
t_map	*check_map_validation(char *map_name);
char	*without_next_line(char *str, int *last_line);
char	*get_next_line(int fd, t_map *map);
void	init_map(t_map *map);
int		check_chars(t_map *map, int exit_check, int player_check);
int		check_path(t_map *map);

// Rendering and gameplay logic
void	handle_key_presses(mlx_key_data_t key_data, void *param);
void	render_objects(t_game *game);
void	render_background(t_game *game);
void	close_game(void *param);
void	terminate_with_error(t_game *game);
void	init_game(t_game *game);

#endif
