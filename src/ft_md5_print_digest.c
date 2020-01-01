/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_md5_print_digest.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguillie <pguillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/23 18:18:52 by pguillie          #+#    #+#             */
/*   Updated: 2019/12/29 12:47:21 by pguillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_md5.h"

void ft_md5_print_digest(const uint32_t digest[4])
{
	unsigned char *d;
	char buf[33];
	size_t i;
	size_t j;

	d = (unsigned char *)digest;
	i = 0;
	j = 0;
	while (i < 16) {
		buf[j] = d[i] / 16;
		buf[j + 1] = d[i] % 16;
		buf[j] += (buf[j] < 10) ? '0' : 'a' - 10;
		buf[j + 1] += (buf[j + 1] < 10) ? '0' : 'a' - 10;
		i += 1;
		j += 2;
	}
	buf[32] = '\n';
	write(1, buf, sizeof(buf));
}
