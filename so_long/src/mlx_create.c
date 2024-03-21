/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_create.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaslan <alaslan@student.42kocaeli.tr >    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 18:36:20 by alaslan           #+#    #+#             */
/*   Updated: 2024/03/14 04:47:54 by alaslan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minilibx/mlx.h"
#include "so_long.h"

void	print_coin(t_data *data, int i, int j, int n)
{
	if (n >= 6)
		n = 0;
	if (n == 0)
		data->err_x = mlx_put_image_to_window(data->mlx, data->win,
				data->img.coin1, j * IMG_SIZE, i * IMG_SIZE);
	else if (n == 1)
		data->err_x = mlx_put_image_to_window(data->mlx, data->win,
				data->img.coin2, j * IMG_SIZE, i * IMG_SIZE);
	else if (n == 2)
		data->err_x = mlx_put_image_to_window(data->mlx, data->win,
				data->img.coin3, j * IMG_SIZE, i * IMG_SIZE);
	else if (n == 3)
		data->err_x = mlx_put_image_to_window(data->mlx, data->win,
				data->img.coin4, j * IMG_SIZE, i * IMG_SIZE);
	else if (n == 4)
		data->err_x = mlx_put_image_to_window(data->mlx, data->win,
				data->img.coin5, j * IMG_SIZE, i * IMG_SIZE);
	else if (n == 5)
		data->err_x = mlx_put_image_to_window(data->mlx, data->win,
				data->img.coin6, j * IMG_SIZE, i * IMG_SIZE);
}

void	print_img(t_data *data, int i, int j)
{
	int			x;
	static int	n = 0;

	x = 0;
	if (data->map[i][j] == '1')
		data->err_x = mlx_put_image_to_window(data->mlx, data->win,
				data->img.wall, j * IMG_SIZE, i * IMG_SIZE);
	else if (data->map[i][j] == 'C')
		print_coin(data, i, j, n++);
	else if (data->map[i][j] == 'E')
		data->err_x = mlx_put_image_to_window(data->mlx, data->win,
				data->img.door, j * IMG_SIZE, i * IMG_SIZE);
	else if (data->map[i][j] == 'P')
		data->err_x = mlx_put_image_to_window(data->mlx, data->win,
				data->img.character, j * IMG_SIZE, i * IMG_SIZE);
	if (data->err_x == -1)
	{
		destroy(data);
		map_free(data->map, data, 2,
			"ERROR\n--The Image Could Not Be Suppressed.--");
	}
}

void	print_background(t_data *data, int i, int j)
{
	data->win = mlx_new_window(data->mlx, data->map_width * IMG_SIZE,
			data->map_height * IMG_SIZE, "so_long");
	while (++i < data->map_height)
	{
		j = -1;
		while (++j < data->map_width)
		{
			if (mlx_put_image_to_window(data->mlx, data->win,
					data->img.background, j * IMG_SIZE, i * IMG_SIZE) == -1)
			{
				destroy(data);
				map_free(data->map, data, 2,
					"ERROR\n--The Image Could Not Be Suppressed.--");
			}
			print_img(data, i, j);
		}
	}
}

void	image_create(t_data *data)
{
	data->img.background = mlx_xpm_file_to_image(data->mlx,
			"img/background.xpm", &data->img.img_w, &data->img.img_h);
	data->img.character = mlx_xpm_file_to_image(data->mlx, "img/character.xpm",
			&data->img.img_w, &data->img.img_h);
	data->img.coin1 = mlx_xpm_file_to_image(data->mlx, "img/coin1.xpm",
			&data->img.img_w, &data->img.img_h);
	data->img.coin2 = mlx_xpm_file_to_image(data->mlx, "img/coin2.xpm",
			&data->img.img_w, &data->img.img_h);
	data->img.coin3 = mlx_xpm_file_to_image(data->mlx, "img/coin3.xpm",
			&data->img.img_w, &data->img.img_h);
	data->img.coin4 = mlx_xpm_file_to_image(data->mlx, "img/coin4.xpm",
			&data->img.img_w, &data->img.img_h);
	data->img.coin5 = mlx_xpm_file_to_image(data->mlx, "img/coin5.xpm",
			&data->img.img_w, &data->img.img_h);
	data->img.coin6 = mlx_xpm_file_to_image(data->mlx, "img/coin6.xpm",
			&data->img.img_w, &data->img.img_h);
	data->img.wall = mlx_xpm_file_to_image(data->mlx, "img/wall.xpm",
			&data->img.img_w, &data->img.img_h);
	data->img.door = mlx_xpm_file_to_image(data->mlx, "img/door.xpm",
			&data->img.img_w, &data->img.img_h);
	if (!data->img.background || !data->img.character || !data->img.coin1
		|| !data->img.coin2 || !data->img.coin3 || !data->img.coin4
		|| !data->img.coin5 || !data->img.coin6 || !data->img.wall
		|| !data->img.door)
		data->err_x = -1;
}

void	mlx_create(t_data *data)
{
	data->mlx = mlx_init();
	image_create(data);
	if (data->err_x == -1)
	{
		destroy(data);
		map_free(data->map, data, 2,
			"ERROR\n-> Xpm File Not Translated to Image.");
	}
	print_background(data, -1, -1);
	playable_map(data, data->exit_x, data->exit_y, 0);
	if (data->i_map.read_count != data->coin_count + 1)
		map_free(data->map, data, 2, "Error\n--Map is wrong--!");
	mlx_hook(data->win, 2, 0, key_hook, data);
	mlx_hook(data->win, 17, 0, mouse_hook, data);
	mlx_loop(data->mlx);
}
