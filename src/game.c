/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donheo <donheo@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 10:22:30 by donheo            #+#    #+#             */
/*   Updated: 2025/05/19 10:51:30 by donheo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	handle_game_error(t_game *game)
{
	if (game->mlx)
		mlx_terminate(game->mlx);
	if (game->map)
		free_map(game->map);
	print_err("failed to initialize MLX");
}

void	init_image(t_game *game)
{
	game->img_wall = load(game, WALL);
	if (!game->img_wall)
		handle_game_error(game);
	game->img_empty_space = load(game, EMPTY_SPACE);
	if (!game->img_empty_space)
		handle_game_error(game);
	game->img_collectible = load(game, COLLECTIBLE);
	if (!game->img_collectible)
		handle_game_error(game);
	game->img_exit = load(game, EXIT);
	if (!game->img_exit)
		handle_game_error(game);
	game->img_player = load(game, PLAYER);
	if (!game->img_player)
		handle_game_error(game);
}

void	init_game(t_game *game)
{
	game->mlx = mxl_init(TILE_SIZE * game->map->width,
		TILE_SIZE * game->map->length, "so_long", false);
	if (!game->mlx)
		handle_game_error(game);
	init_image(game);
}
