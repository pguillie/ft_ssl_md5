/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sha256.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguillie <pguillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/23 15:24:51 by pguillie          #+#    #+#             */
/*   Updated: 2020/01/09 20:20:27 by pguillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SHA256_H
# define FT_SHA256_H

# include <sys/stat.h>
# include <stddef.h>
# include <unistd.h>
# include <stdint.h>
# include <fcntl.h>

# include "libft.h"

# include <stdio.h> //

# define SHA256_QUIET (3)
# define SHA256_REVERSE (1)

struct s_sha256_data {
	uint32_t digest[8];
	uint64_t length;
	const char *end;
};

int ft_sha256(char *av[]);

int ft_sha256_string(const char *str, int opt);
int ft_sha256_file(const char *filenamem, int opt);
int ft_sha256_stdin(int echo);

void ft_sha256_init(struct s_sha256_data *data);
void ft_sha256_process_message(struct s_sha256_data *data, const char *str,
	uint64_t length);
void ft_sha256_process_block(uint32_t digest[8], uint32_t block[16]);
void ft_sha256_append_length(struct s_sha256_data *data);
void ft_sha256_print_digest(const uint32_t digest[8]);

#endif /* FT_SHA256_H */
