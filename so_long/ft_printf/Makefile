# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alaslan <alaslan@student.42kocaeli.tr >    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/15 11:33:00 by alaslan           #+#    #+#              #
#    Updated: 2024/01/15 11:33:03 by alaslan          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 	=	 libftprintf.a
CC		=	 gcc
CFLAGS	= 	-Wall -Wextra -Werror
RM		= 	rm -rf

SRC		=	ft_printf_utils.c	\
			ft_printf.c

OBJ		= 	$(SRC:.c=.o)

all		: 	$(NAME)

$(NAME)	:	$(OBJ)
		ar rc $(NAME) $(OBJ)

clean	:
			$(RM) $(OBJ)

fclean	:	clean
			$(RM) $(NAME)

re		:	fclean all

.PHONY	:	all clean fclean re
