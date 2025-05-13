/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donheo <donheo@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 11:40:41 by donheo            #+#    #+#             */
/*   Updated: 2025/05/13 14:04:23 by donheo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	print_err(char *str)
{
	if (str)
		perror(str);
	else
		perror("Invalid error message");
	exit(1);
}

int	main(int ac, char **av)
{
	check_map_validation(av[1]);



}
