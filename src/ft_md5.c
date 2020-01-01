/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_md5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguillie <pguillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/23 12:37:49 by pguillie          #+#    #+#             */
/*   Updated: 2019/12/29 13:04:29 by pguillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_md5.h"

#include <stdio.h>
void ft_md5_string(const char *str)
{
	struct s_md5_data data;

	printf("INIT\n");
	ft_md5_init(&data);
	ft_md5_print_digest(data.digest);
	printf("PROCESS\n");
	ft_md5_process_message(&data, str, strlen(str)); //libft
	ft_md5_print_digest(data.digest);
	printf("LENGTH\n");
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


////////////////////////////////////////////////////////////////////////////////

/* /\* F, G, H and I are basic MD5 functions. */
/*  *\/ */
/* #define F(x, y, z) (((x) & (y)) | ((~x) & (z))) */
/* #define G(x, y, z) (((x) & (z)) | ((y) & (~z))) */
/* #define H(x, y, z) ((x) ^ (y) ^ (z)) */
/* #define I(x, y, z) ((y) ^ ((x) | (~z))) */

/* /\* ROTATE_LEFT rotates x left n bits. */
/*  *\/ */
/* #define ROTATE_LEFT(x, n) (((x) << (n)) | ((x) >> (32-(n)))) */

/* /\* FF, GG, HH, and II transformations for rounds 1, 2, 3, and 4. */
/* Rotation is separate from addition to prevent recomputation. */
/*  *\/ */
/* /\* Round 1. *\/ */
/* /\* Let [abcd k s i] denote the operation */
/*    a = b + ((a + F(b,c,d) + X[k] + T[i]) <<< s). *\/ */
/* #define FF(a, b, c, d, x, s, ac) {	       \ */
/*  (a) += F ((b), (c), (d)) + (x) + (UINT4)(ac); \ */
/*  (a) = ROTATE_LEFT ((a), (s)); \ */
/*  (a) += (b); \ */
/*   } */
/* #define GG(a, b, c, d, x, s, ac) { \ */
/*  (a) += G ((b), (c), (d)) + (x) + (UINT4)(ac); \ */
/*  (a) = ROTATE_LEFT ((a), (s)); \ */
/*  (a) += (b); \ */
/*   } */
/* #define HH(a, b, c, d, x, s, ac) { \ */
/*  (a) += H ((b), (c), (d)) + (x) + (UINT4)(ac); \ */
/*  (a) = ROTATE_LEFT ((a), (s)); \ */
/*  (a) += (b); \ */
/*   } */
/* #define II(a, b, c, d, x, s, ac) { \ */
/*  (a) += I ((b), (c), (d)) + (x) + (UINT4)(ac); \ */
/*  (a) = ROTATE_LEFT ((a), (s)); \ */
/*  (a) += (b); \ */
/*   } */
