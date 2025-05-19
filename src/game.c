/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donheo <donheo@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 10:22:30 by donheo            #+#    #+#             */
/*   Updated: 2025/05/19 15:40:47 by donheo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static mlx_image_t	*load_image(t_game *game, char *img_path)
{
	mlx_texture_t	*texture;
	mlx_image_t		*img;

	texture = mlx_load_png(img_path);
	if (!texture)
		terminate_with_error(game);
	img = mlx_texture_to_image(game->mlx, texture);
	if (!img)
	{
		mlx_delete_texture(texture);
		terminate_with_error(game);
	}
	mlx_delete_texture(texture);
	return (img);
}

static void	init_images(t_game *game)
{
	game->img_wall = load_image(game, WALL);
	if (!game->img_wall)
		terminate_with_error(game);
	game->img_floor = load_image(game, FLOOR);
	if (!game->img_floor)
		terminate_with_error(game);
	game->img_collectible = load_image(game, COLLECTIBLE);
	if (!game->img_collectible)
		terminate_with_error(game);
	game->img_exit = load_image(game, EXIT);
	if (!game->img_exit)
		terminate_with_error(game);
	game->img_player = load_image(game, PLAYER);
	if (!game->img_player)
		terminate_with_error(game);
}

void	close_game(void *param)
{
	t_game	*game;

	game = (t_game *)param;
	if (game->mlx)
		mlx_terminate(game->mlx);
	if (game->map)
		free_map(game->map);
	ft_putendl_fd("Thanks for playing!", 1);
	exit(0);
}

void	terminate_with_error(t_game *game)
{
	if (game->mlx)
		mlx_terminate(game->mlx);
	if (game->map)
		free_map(game->map);
	print_err("failed to initialize MLX");
}

void	init_game(t_game *game)
{
	game->mlx = mlx_init(TILE_SIZE * game->map->width, \
		TILE_SIZE * game->map->length, "so_long", false);
	if (!game->mlx)
		terminate_with_error(game);
	init_images(game);
	game->steps = 0;
	game->collectibles = game->map->collectibles;
	render_background(game);
	render_objects(game);
}
