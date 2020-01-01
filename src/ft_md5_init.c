/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_md5_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguillie <pguillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/29 10:24:19 by pguillie          #+#    #+#             */
/*   Updated: 2020/01/01 16:06:34 by pguillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_md5.h"

void ft_md5_init(struct s_md5_data *data)
{
	const uint8_t md5_init_digest[16] = {
		0x01, 0x23, 0x45, 0x67, 0x89, 0xab, 0xcd, 0xef,
		0xfe, 0xdc, 0xba, 0x98, 0x76, 0x54, 0x32, 0x10
	};

	data->length = 0;
	memcpy(data->digest, md5_init_digest, sizeof(data->digest)); // libft
	data->end = NULL;
}
