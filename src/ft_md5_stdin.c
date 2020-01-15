/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_md5_stdin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguillie <pguillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/08 17:34:27 by pguillie          #+#    #+#             */
/*   Updated: 2020/01/15 22:17:09 by pguillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_md5.h"

static void	process_buffer(struct s_md5_data *data, const char *message,
	size_t *n, int tee)
{
	if (tee)
		write(1, message, *n);
	ft_md5_process_message(data, message, *n);
	*n = 0;
}

static void	read_stdin(struct s_md5_data *data, int tee)
{
	char	buf[2][1024];
	ssize_t	n;
	size_t	i;
	size_t	j;

	i = 0;
	while ((n = read(0, buf[0], sizeof(buf[0]))) > 0)
	{
		j = sizeof(buf[1]) - i;
		if ((size_t)n >= j)
		{
			ft_memcpy(buf[1] + i, buf[0], j);
			i += j;
			process_buffer(data, buf[1], &i, tee);
			n -= j;
		}
		else
			j = 0;
		ft_memcpy(buf[1] + i, buf[0] + j, n);
		i += n;
	}
	close(0);
	if (i > 0)
		process_buffer(data, buf[1], &i, tee);
}

int			ft_md5_stdin(int tee)
{
	struct s_md5_data data;

	ft_md5_init(&data);
	read_stdin(&data, tee);
	ft_md5_append_length(&data);
	ft_md5_print_digest(data.digest);
	write(1, "\n", 1);
	return (0);
}
