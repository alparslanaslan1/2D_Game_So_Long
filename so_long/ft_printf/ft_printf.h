/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaslan <alaslan@student.42kocaeli.tr >    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 17:31:23 by alaslan           #+#    #+#             */
/*   Updated: 2024/01/15 11:33:36 by alaslan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>

int		ft_int(int nb);
int		ft_unsigned_int(unsigned int nb);
int		ft_putstr(char *str);
int		ft_putchar(char n);
int		ft_hexadecimal(unsigned int n, char format);
int		ft_point(unsigned long a, int sign);
int		ft_control(char str);
int		ft_format(va_list *arg, char l);
int		ft_printf(const char *str, ...);
#endif