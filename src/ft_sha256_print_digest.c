/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sha256_print_digest.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguillie <pguillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 14:39:12 by pguillie          #+#    #+#             */
/*   Updated: 2020/01/15 21:18:06 by pguillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sha256.h"

void ft_sha256_print_digest(const uint32_t digest[8])
{
	unsigned char *d;
	char buf[64];
	size_t i;
	size_t j;

	d = (unsigned char *)digest;
	i = 0;
	while (i < 32) {
		j = ((i & -4) | ((~i) & 3)) << 1;
		buf[j] = d[i] / 16;
		buf[j + 1] = d[i] % 16;
		buf[j] += (buf[j] < 10) ? '0' : 'a' - 10;
		buf[j + 1] += (buf[j + 1] < 10) ? '0' : 'a' - 10;
		i += 1;
	}
	write(1, buf, sizeof(buf));
}
