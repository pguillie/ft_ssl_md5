#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pguillie <pguillie@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/12/22 15:06:34 by pguillie          #+#    #+#              #
#    Updated: 2019/12/29 12:06:46 by pguillie         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME := ft_ssl

CC	= gcc
CFLAGS	= -Wall -Werror -Wextra -I$(incdir)

incdir := include/
srcdir := src/

headers = $(addprefix $(incdir),		\
	ft_ssl.h				\
	ft_md5.h				\
)

sources = $(addprefix $(srcdir),		\
	main.c					\
	ft_md5.c				\
	ft_md5_init.c				\
	ft_md5_process_message.c		\
	ft_md5_process_block.c			\
	ft_md5_append_length.c			\
	ft_md5_print_digest.c			\
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
