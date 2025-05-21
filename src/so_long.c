/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donheo <donheo@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 11:40:41 by donheo            #+#    #+#             */
/*   Updated: 2025/05/21 08:02:58 by donheo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_err(char *str)
{
	write (2, "Error\n", 6);
	if (str)
		write(2, str, ft_strlen(str));
	write(2, "\n", 1);
	exit(1);
}

int	main(int ac, char **av)
{
	t_map	*map;
	t_game	game;

	if (ac != 2)
		print_err("Invalid input");
	map = check_map_validation(av[1]);
	game.map = map;
	init_game(&game);
	mlx_close_hook(game.mlx, close_game, &game);
	mlx_key_hook(game.mlx, handle_key_presses, &game);
	mlx_loop(game.mlx);
	free_map(map);
	return (0);
}
