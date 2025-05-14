/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donheo <donheo@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 11:40:41 by donheo            #+#    #+#             */
/*   Updated: 2025/05/14 11:36:51 by donheo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int ac, char **av)
{
	t_map	*map;

	if (ac != 2)
		print_err("Invalid input");
	map = check_map_validation(av[1]);

	free_map(map);
	if (map != 0 && ac == 0)
		return (0);
	return (0);
}
