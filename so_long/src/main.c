/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaslan <alaslan@student.42kocaeli.tr >    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 18:36:27 by alaslan           #+#    #+#             */
/*   Updated: 2024/03/20 22:26:47 by alaslan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int ac, char **av)
{
	t_data	data;

	if (ac != 2)
		err_msg("Error\n--Only 2 Arguments Needed.--");
	map_control(av[1], &data);
	map_chars(&data);
	mlx_create(&data);
	map_free(data.map, &data, 0, "\0");
}
