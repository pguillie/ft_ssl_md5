/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ssl_invalid_command.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguillie <pguillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 20:13:25 by pguillie          #+#    #+#             */
/*   Updated: 2020/01/07 20:36:56 by pguillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

int ft_ssl_invalid_command(const char *invalid)
{
	ft_puterr("ft_ssl: Error: '");
	ft_puterr(invalid);
	ft_puterr("' is an invalid command.\n");
	ft_puterr("\nStandard commands:\n"
		"\nMessage Digest commands:\n"
		"md5\n"
		"sha256\n"
		"\nCipher commands:\n");
	return (1);
}
