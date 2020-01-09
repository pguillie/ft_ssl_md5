#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pguillie <pguillie@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/12/22 15:06:34 by pguillie          #+#    #+#              #
#    Updated: 2020/01/10 10:52:30 by pguillie         ###   ########.fr        #
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
	libft.h					\
)

sources = $(addprefix $(srcdir),		\
	main.c					\
	ft_ssl_set_command.c			\
	ft_ssl_invalid_command.c		\
	ft_md5.c				\
	ft_md5_string.c				\
	ft_md5_file.c				\
	ft_md5_stdin.c				\
	ft_md5_init.c				\
	ft_md5_process_message.c		\
	ft_md5_process_block.c			\
	ft_md5_append_length.c			\
	ft_md5_print_digest.c			\
	ft_sha256.c				\
	ft_sha256_string.c			\
	ft_sha256_file.c			\
	ft_sha256_stdin.c			\
	ft_sha256_init.c			\
	ft_sha256_process_message.c		\
	ft_sha256_process_block.c		\
	ft_sha256_append_length.c		\
	ft_sha256_print_digest.c		\
	ft_strlen.c				\
	ft_putstr.c				\
	ft_puterr.c				\
	ft_strcmp.c				\
	ft_strcpy.c				\
	ft_memcpy.c				\
)

objects = $(sources:%.c=%.o)

all: $(NAME)

$(NAME): $(objects)
	$(CC) -o $@ $^

$(objects): Makefile $(headers)

clean:
	$(RM) $(objects)

fclean:
	$(RM) $(objects) $(NAME)

re: fclean all
