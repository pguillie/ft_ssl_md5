/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_md5_stdin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguillie <pguillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/08 17:34:27 by pguillie          #+#    #+#             */
/*   Updated: 2020/01/09 12:09:17 by pguillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_md5.h"

int ft_md5_stdin(int echo)
{
	struct s_md5_data data;
	char buf[1024];
	ssize_t n;

	ft_md5_init(&data);
	while ((n = read(0, buf, sizeof(buf))) > 0) {
		if (echo)
			write(1, buf, n);
		ft_md5_process_message(&data, buf, n);
	}
	close(0);
	ft_md5_append_length(&data);
	ft_md5_print_digest(data.digest);
	write(1, "\n", 1);
	return (0);
}
