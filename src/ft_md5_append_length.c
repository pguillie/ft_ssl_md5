/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_md5_append_length.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguillie <pguillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/29 10:42:16 by pguillie          #+#    #+#             */
/*   Updated: 2020/01/09 12:17:42 by pguillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_md5.h"

void ft_md5_append_length(struct s_md5_data *data)
{
	char block[128];
	size_t len;
	size_t size;

	len = (data->length & 0x1ff) >> 3;
	ft_memcpy(block, data->end, len);
	size = (len < 56) ? 64 : 128;
	block[len++] = (char)(1 << 7);
	while (len < size - 8)
		block[len++] = 0;
	*(uint64_t *)(block + len) = data->length;
	ft_md5_process_message(data, block, size);
}
