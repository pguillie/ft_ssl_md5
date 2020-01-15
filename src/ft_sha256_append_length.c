/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sha256_append_length.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguillie <pguillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/29 10:42:16 by pguillie          #+#    #+#             */
/*   Updated: 2020/01/15 22:20:00 by pguillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sha256.h"

void	ft_sha256_append_length(struct s_sha256_data *data)
{
	char	block[128];
	size_t	len;
	size_t	size;

	len = (data->length & 0x1ff) >> 3;
	ft_memcpy(block, data->end, len);
	size = (len < 56) ? 64 : 128;
	block[len++] = (char)(1 << 7);
	while (len < size - 8)
		block[len++] = 0;
	*(uint64_t *)(block + len) = \
		((data->length << 56) & ((uint64_t)0xff << 56))
		| ((data->length << 40) & ((uint64_t)0xff << 48))
		| ((data->length << 24) & ((uint64_t)0xff << 40))
		| ((data->length << 8) & ((uint64_t)0xff << 32))
		| ((data->length >> 8) & (0xff << 24))
		| ((data->length >> 24) & (0xff << 16))
		| ((data->length >> 40) & (0xff << 8))
		| ((data->length >> 56) & (0xff));
	ft_sha256_process_message(data, block, size);
}
