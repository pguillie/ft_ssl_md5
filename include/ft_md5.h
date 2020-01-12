/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_md5.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguillie <pguillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/23 15:24:51 by pguillie          #+#    #+#             */
/*   Updated: 2020/01/11 15:01:19 by pguillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MD5_H
# define FT_MD5_H

# include <sys/stat.h>
# include <stddef.h>
# include <unistd.h>
# include <stdint.h>
# include <fcntl.h>

# include "libft.h"

# include <stdio.h> //

# define MD5_QUIET (3)
# define MD5_REVERSE (1)

struct s_md5_data {
	uint32_t digest[4];
	uint64_t length;
	const char *end;
};

int ft_md5(char *av[]);

int ft_md5_string(const char *str, int opt);
int ft_md5_file(const char *filenamem, int opt);
int ft_md5_stdin(int tee);

void ft_md5_init(struct s_md5_data *data);
void ft_md5_process_message(struct s_md5_data *data, const char *str,
	uint64_t length);
void ft_md5_process_block(uint32_t digest[4], uint32_t block[16]);
void ft_md5_append_length(struct s_md5_data *data);
void ft_md5_print_digest(const uint32_t digest[4]);

#endif /* FT_MD5_H */
