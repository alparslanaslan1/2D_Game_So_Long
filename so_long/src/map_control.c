/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_control.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaslan <alaslan@student.42kocaeli.tr >    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 18:35:08 by alaslan           #+#    #+#             */
/*   Updated: 2024/03/20 23:48:51 by alaslan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "so_long.h"
#include <fcntl.h>
#include <unistd.h>

void	map_name_control(char *map_name, int fd)
{
	int		name_size;
	char	*line;

	name_size = ft_strlen(map_name) - 1;
	if (map_name[name_size] != 'r' || map_name[name_size - 1] != 'e'
		|| map_name[name_size - 2] != 'b' || map_name[name_size - 3] != '.')
		(close(fd), err_msg("ERROR\n->File Extension isn't Correct.<-"));
	line = get_next_line(fd, 0, 1);
	if (!line || !line[0])
	{
		(free(line), close(fd));
		err_msg("Error\n->Map is Empty.<-");
	}
	(free(line), close(fd));
}

void	get_map_size(t_data *data, int x, int y, int fd)
{
	char	*line;

	line = get_next_line(fd, 0, 1);
	x = (int) ft_strlen(line);
	while (1)
	{
		free(line);
		y++;
		line = get_next_line(fd, 0, 1);
		if (!line)
			return ;
		if (line[0] == '\0')
			break ;
		if (x != (int)ft_strlen(line))
		{
			(free(line), close(fd));
			err_msg("Error\n--The Map Should Be Rectangular.--");
		}
	}
	free(line);
	data->map_height = y;
	data->map_width = x - 1;
}

void	map_read(t_data *data, int fd, int x, int y)
{
	char	*area;

	data->map = (char **)malloc(sizeof(char *) * data->map_height + 1);
	if (!data->map)
		(close(fd), exit (1));
	while (x < data->map_height)
	{
		area = get_next_line(fd, 0, 1);
		if (area == NULL)
			break ;
		data->map[x] = (char *)malloc(sizeof(char) * data->map_width + 2);
		if (!data->map[x])
		{
			close(fd);
			(free(area), map_free(data->map, data, 1, "\0"));
		}
		y = 0;
		while (area[y])
		{
			data->map[x][y] = area[y];
			y++;
		}
		data->map[x++][y] = '\0';
		free(area);
	}
}

void	wall_control(t_data *data, int i, int j)
{
	while (i < data->map_width)
	{
		if (data->map[0][i] != '1' || data->map[data->map_height - 1][i] != '1')
			map_free(data->map, data, 2,
				"ERROR\n--The Map Must Be Surrounded By Closed Walls.--");
		++i;
	}
	while (j < data->map_height)
	{
		if (data->map[j][0] != '1' || data->map[j][data->map_width - 1] != '1')
			map_free(data->map, data, 2,
				"ERROR\n->The Map Must Be Surrounded By Closed Walls.<-");
		++j;
	}
}

void	map_control(char *map_name, t_data *data)
{
	int	fd;

	data->in_map_name = map_name;
	fd = open(map_name, O_RDONLY);
	if (fd == -1)
		err_msg("Error\n->Map file isn't found.<-");
	map_name_control(map_name, fd);
	close (fd);
	fd = open(data->in_map_name, O_RDONLY);
	if (fd == -1)
		err_msg("Error\n->Map File isn't Found.<-");
	get_map_size(data, 0, 0, fd);
	close(fd);
	fd = open(data->in_map_name, O_RDONLY);
	if (fd == -1)
		err_msg("Error\n->Map File Not Found.<-");
	map_read(data, fd, 0, 0);
	close(fd);
	wall_control(data, 0, 0);
}
