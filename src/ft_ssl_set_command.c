/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ssl_set_command.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguillie <pguillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 20:19:27 by pguillie          #+#    #+#             */
/*   Updated: 2020/01/15 22:01:36 by pguillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

struct s_ssl_cmd	g_ssl_command[] = {
	{"md5", &ft_md5},
	{"sha256", &ft_sha256}
};

t_ssl_command	ft_ssl_set_command(const char *command)
{
	size_t n;

	n = sizeof(g_ssl_command) / sizeof(g_ssl_command[0]);
	while (n--)
	{
		if (ft_strcmp(g_ssl_command[n].cmd, command) == 0)
			return (g_ssl_command[n].func);
	}
	return (NULL);
}
