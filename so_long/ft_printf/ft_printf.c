/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaslan <alaslan@student.42kocaeli.tr >    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 17:02:29 by alaslan           #+#    #+#             */
/*   Updated: 2024/01/15 11:35:34 by alaslan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>

int	ft_putchar(char n)
{
	return (write(1, &n, 1));
}

int	ft_printf(const char *str, ...)
{
	va_list		args;
	int			len;
	int			i;
	int			tmp;

	i = -1;
	len = 0;
	va_start (args, str);
	while (str[++i])
	{
		if (str[i] == '%' && ft_control(str[i + 1]))
		{
			tmp = ft_format(&args, str[++i]);
			if (tmp == -1)
				return (-1);
			len += tmp;
			continue ;
		}
		else if (ft_putchar(str[i]) == -1)
			return (-1);
		len++;
	}
	va_end(args);
	return (len);
}

int	ft_control(char str)
{
	if (str == 'd' || str == 'i' || str == 'u' || str == 'x'
		|| str == 'X' || str == 'p' || str == 's' || str == 'c' || str == '%')
		return (1);
	return (0);
}

int	ft_format(va_list *arg, char l)
{
	if (l == 'c')
		return (ft_putchar(va_arg((*arg), int)));
	else if (l == 's')
		return (ft_putstr(va_arg((*arg), char *)));
	else if (l == 'i' || l == 'd')
		return (ft_int(va_arg((*arg), int)));
	else if (l == 'u')
		return (ft_unsigned_int(va_arg((*arg), unsigned int)));
	else if (l == 'x' || l == 'X')
		return (ft_hexadecimal(va_arg((*arg), unsigned int), l));
	else if (l == 'p')
		return (ft_point(va_arg((*arg), unsigned long), 1));
	else if (l == '%')
		return (ft_putchar('%'));
	else
		return (0);
}
