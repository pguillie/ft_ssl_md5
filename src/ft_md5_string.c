/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_md5_string.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguillie <pguillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 20:30:36 by pguillie          #+#    #+#             */
/*   Updated: 2020/01/15 22:17:47 by pguillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_md5.h"

int	ft_md5_string(const char *str, int opt)
{
	struct s_md5_data data;

	ft_md5_init(&data);
	ft_md5_process_message(&data, str, ft_strlen(str));
	ft_md5_append_length(&data);
	if (!(opt & MD5_REVERSE))
	{
		ft_putstr("MD5 (\"");
		ft_putstr(str);
		ft_putstr("\") = ");
	}
	ft_md5_print_digest(data.digest);
	if (opt == MD5_REVERSE)
	{
		ft_putstr(" \"");
		ft_putstr(str);
		ft_putstr("\"\n");
	}
	else
		ft_putstr("\n");
	return (0);
}
