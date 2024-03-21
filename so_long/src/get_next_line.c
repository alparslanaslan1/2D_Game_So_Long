/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaslan <alaslan@student.42kocaeli.tr >    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 03:03:59 by alaslan           #+#    #+#             */
/*   Updated: 2024/03/20 23:47:47 by alaslan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

char	*get_next_line(int fd, int i, int rd_byte)
{
	char	buffer;
	char	*line;

	line = (char *)malloc(sizeof(char) * 8888);
	buffer = 0;
	if (fd < 0 || !line)
		return (NULL);
	while (rd_byte > 0)
	{
		rd_byte = read(fd, &buffer, 1);
		if (rd_byte <= 0)
			break ;
		if (buffer == '\n')
		{
			line[i++] = buffer;
			break ;
		}
		if (i < 8887)
		{
			line[i] = buffer;
			i++;
		}
	}
	line[i] = '\0';
	return (line);
}
