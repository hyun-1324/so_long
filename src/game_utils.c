/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donheo <donheo@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 11:58:46 by donheo            #+#    #+#             */
/*   Updated: 2025/05/20 15:07:32 by donheo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	collect_item(t_game *game, int x, int y)
{
	int	i;

	i = 0;
	if (game->map->content[y][x] == 'C')
	{
		game->map->content[y][x] = '0';
		while (i < game->map->collectibles)
		{
			if (game->img_collectible->instances[i].x == x * TILE_SIZE \
				&& game->img_collectible->instances[i].y == y * TILE_SIZE)
			{
				game->img_collectible->instances[i].enabled = false;
				break ;
			}
			i++;
		}
		game->collectibles--;
	}
}

static void	move_player(t_game *game, int new_pos_x, int new_pos_y)
{
	if (game->map->content[new_pos_y][new_pos_x] == '1')
		return ;
	game->map->player_x = new_pos_x;
	game->map->player_y = new_pos_y;
	game->img_player->instances->x = new_pos_x * TILE_SIZE;
	game->img_player->instances->y = new_pos_y * TILE_SIZE;
	game->steps++;
	ft_putstr_fd("steps: ", 1);
	ft_putnbr_fd(game->steps, 1);
	ft_putchar_fd('\n', 1);
	if (game->map->content[new_pos_y][new_pos_x] == 'E' \
		&& game->collectibles <= 0)
	{
		ft_putstr_fd("You win!", 1);
		close_game(game);
	}
	collect_item(game, new_pos_x, new_pos_y);
}

void	handle_key_presses(mlx_key_data_t key_data, void *param)
{
	t_game	*game;
	int		x;
	int		y;

	game = (t_game *)param;
	x = game->map->player_x;
	y = game->map->player_y;
	if (key_data.key == MLX_KEY_RIGHT && key_data.action == MLX_PRESS)
		move_player(game, x + 1, y);
	else if (key_data.key == MLX_KEY_LEFT && key_data.action == MLX_PRESS)
		move_player(game, x - 1, y);
	else if (key_data.key == MLX_KEY_DOWN && key_data.action == MLX_PRESS)
		move_player(game, x, y + 1);
	else if (key_data.key == MLX_KEY_UP && key_data.action == MLX_PRESS)
		move_player(game, x, y - 1);
	else if (key_data.key == MLX_KEY_ESCAPE && key_data.action == MLX_PRESS)
		close_game(game);
}

void	render_objects(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->map->length)
	{
		x = 0;
		while (x < game->map->width)
		{
			if (game->map->content[y][x] == 'C')
				if (mlx_image_to_window(game->mlx, game->img_collectible, \
					x * TILE_SIZE, y * TILE_SIZE) < 0)
					terminate_with_error(game);
			if (game->map->content[y][x] == 'E')
				if (mlx_image_to_window(game->mlx, game->img_exit, \
					x * TILE_SIZE, y * TILE_SIZE) < 0)
					terminate_with_error(game);
			x++;
		}
		y++;
	}
}

void	render_background(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->map->length)
	{
		x = 0;
		while (x < game->map->width)
		{
			if (game->map->content[y][x] == '1')
			{
				if (mlx_image_to_window(game->mlx, game->img_wall, \
					x * TILE_SIZE, y * TILE_SIZE) < 0)
					terminate_with_error(game);
			}
			else
			{
				if (mlx_image_to_window(game->mlx, game->img_floor, \
					x * TILE_SIZE, y * TILE_SIZE) < 0)
					terminate_with_error(game);
			}
			x++;
		}
		y++;
	}
}
