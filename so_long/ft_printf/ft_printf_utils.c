/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaslan <alaslan@student.42kocaeli.tr >    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 12:07:44 by alaslan           #+#    #+#             */
/*   Updated: 2024/01/15 11:34:31 by alaslan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>

int	ft_int(int nb)
{
	long		n;
	static int	len;

	n = nb;
	len = 0;
	if (n < 0)
	{
		if (ft_putchar('-') == -1)
			return (-1);
		n *= -1;
	}
	if (n > 9)
	{
		if (ft_int (n / 10) == -1)
			return (-1);
		len++;
	}
	if (ft_putchar((n % 10) + 48) == -1)
		return (-1);
	if (nb < 0)
		len++;
	return (len + 1);
}

int	ft_unsigned_int(unsigned int nb)
{
	static int	len;

	len = 0;
	if (nb > 9)
	{
		if (ft_unsigned_int (nb / 10) == -1)
			return (-1);
		len++;
	}
	if (ft_putchar((nb % 10) + 48) == -1)
		return (-1);
	return (len + 1);
}

int	ft_putstr(char *str)
{
	unsigned int	i;

	i = 0;
	if (str == NULL)
	{
		if (ft_putstr("(null)") == -1)
			return (-1);
		return (6);
	}
	while (str[i])
	{
		if (ft_putchar(str[i]) == -1)
			return (-1);
		i++;
	}
	return (i);
}

int	ft_hexadecimal(unsigned int n, char format)
{
	static int	len;

	len = 0;
	if (n >= 16)
	{
		if (ft_hexadecimal(n / 16, format) == -1)
			return (-1);
		len++;
	}
	if (format == 'x')
	{
		if (write(1, &"0123456789abcdef"[n % 16], 1) == -1)
			return (-1);
	}
	else if (format == 'X')
		if (write(1, &"0123456789ABCDEF"[n % 16], 1) == -1)
			return (-1);
	return (len + 1);
}

int	ft_point(unsigned long a, int sign)
{
	int	ret;

	ret = 0;
	if (sign == 1)
	{
		ret += write(1, "0x", 2);
		if (ret == -1)
			return (-1);
		sign = 0;
	}
	if (a >= 16)
		ret += ft_point(a / 16, sign);
	if (write(1, &"0123456789abcdef"[a % 16], 1) == -1)
		return (-1);
	return (ret + 1);
}
