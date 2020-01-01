/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_md5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguillie <pguillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/23 12:37:49 by pguillie          #+#    #+#             */
/*   Updated: 2020/01/01 16:01:43 by pguillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_md5.h"

void ft_md5_string(const char *str)
{
	struct s_md5_data data;

	ft_md5_init(&data);
	ft_md5_process_message(&data, str, strlen(str)); //libft
	ft_md5_append_length(&data);
	ft_md5_print_digest(data.digest);
}

/* void ft_md5_file(const char *filename) */
/* { */
/* 	struct s_md5_data data; */
/* 	char buf[1024]; */
/* 	ssize_t n; */
/* 	int fd; */

/* 	ft_md5_init(&data); */
/* 	fd = open(filename, O_RDONLY); */
/* 	while ((n = read(fd, buf, sizeof(buf))) > 0) { */
/* 		end = ft_md5_process_message(&data, buf, n); */
/* 	} */
/* 	close(fd); */
/* 	ft_md5_append_length(data, end); */
/* 	ft_md5_print_digest(data.digest); */
/* } */
