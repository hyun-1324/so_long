/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donheo <donheo@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 11:40:41 by donheo            #+#    #+#             */
/*   Updated: 2025/05/19 10:45:55 by donheo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_err(char *str)
{
	if (str)
		write(2, str, ft_strlen(str));
	write(2, "\n", 1);
	exit(1);
}

int	main(int ac, char **av)
{
	t_map	*map;
	t_game	*game;

	if (ac != 2)
		print_err("Invalid input");
	map = check_map_validation(av[1]);
	init_game(game);


	free_map(map);
	return (0);
}
