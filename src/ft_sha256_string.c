/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sha256_string.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguillie <pguillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 20:30:36 by pguillie          #+#    #+#             */
/*   Updated: 2020/01/13 22:53:01 by pguillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sha256.h"

int ft_sha256_string(const char *str, int opt)
{
	struct s_sha256_data data;

	ft_sha256_init(&data);
	ft_sha256_process_message(&data, str, ft_strlen(str));
	ft_sha256_append_length(&data);
	if (!(opt & SHA256_REVERSE)) {
		ft_putstr("SHA256 (\"");
		ft_putstr(str);
		ft_putstr("\") = ");
	}
	ft_sha256_print_digest(data.digest);
	if (opt == SHA256_REVERSE) {
		ft_putstr(" \"");
		ft_putstr(str);
		ft_putstr("\"\n");
	} else {
		ft_putstr("\n");
	}
	return (0);
}
