/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaslan <alaslan@student.42kocaeli.tr >    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 18:36:42 by alaslan           #+#    #+#             */
/*   Updated: 2024/03/20 23:46:47 by alaslan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf/ft_printf.h"
#include "../libft/libft.h"
#include "../minilibx/mlx.h"
#include "so_long.h"

void	err_msg(char *msg)
{
	ft_printf("%s", msg);
	exit(0);
}

void	map_free(char **map, t_data *data, int flag, char *msg)
{
	int	i;

	i = 0;
	if (msg)
		ft_printf("%s", msg);
	while (i < data->map_height)
	{
		free(map[i]);
		i++;
	}
	free(map);
	if (flag == 0)
		ft_printf("Error\n--Exit Success--");
	else if (flag == 1)
		ft_printf("Error\n->Memory Allocation Failed!<-");
	exit(0);
}

void	destroy(t_data *data)
{
	if (data->img.background)
		mlx_destroy_image(data->mlx, data->img.background);
	if (data->img.coin1)
		mlx_destroy_image(data->mlx, data->img.coin1);
	if (data->img.coin2)
		mlx_destroy_image(data->mlx, data->img.coin2);
	if (data->img.coin3)
		mlx_destroy_image(data->mlx, data->img.coin3);
	if (data->img.coin4)
		mlx_destroy_image(data->mlx, data->img.coin4);
	if (data->img.coin5)
		mlx_destroy_image(data->mlx, data->img.coin5);
	if (data->img.coin6)
		mlx_destroy_image(data->mlx, data->img.coin6);
	if (data->img.wall)
		mlx_destroy_image(data->mlx, data->img.wall);
	if (data->img.door)
		mlx_destroy_image(data->mlx, data->img.door);
	if (data->img.character)
		mlx_destroy_image(data->mlx, data->img.character);
	mlx_destroy_window(data->mlx, data->win);
}

int	mouse_hook(t_data *data)
{
	destroy(data);
	map_free(data->map, data, 0, "\0");
	return (0);
}

void	exit_door(t_data *data)
{
	ft_printf("%s", "\n\n--GAME FINISH--");
	ft_printf("\n\nTotal Movement:\t%d\n\n", data->step_count);
	destroy(data);
	map_free(data->map, data, 2, "\0");
}
