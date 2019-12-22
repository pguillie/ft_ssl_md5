#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pguillie <pguillie@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/12/22 15:06:34 by pguillie          #+#    #+#              #
#    Updated: 2019/12/22 15:28:05 by pguillie         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME := ft_ssl

CC	= gcc
CFLAGS	= -Wall -Werror -Wextra -I$(incdir)

incdir := include/
srcdir := src/

headers = $(addprefix $(incdir),		\
)

sources = $(addprefix $(srcdir),		\
	main.c					\
)

objects = $(sources:%.c=%.o)

all: $(NAME)

$(NAME): $(objects)
	$(CC) -o $@ $^

clean:
	$(RM) $(objects)

fclean:
	$(RM) $(objects) $(NAME)

re: fclean all
