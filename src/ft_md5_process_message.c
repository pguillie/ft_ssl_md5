/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_md5_process_message.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguillie <pguillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/23 18:32:22 by pguillie          #+#    #+#             */
/*   Updated: 2019/12/29 12:19:27 by pguillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_md5.h"

void ft_md5_process_message(struct s_md5_data *data, const char *msg, uint64_t len)
{
	data->length += len << 3;
	while (len >= 64) {
		ft_md5_process_block(data->digest, (uint32_t *)msg);
		len -= 64;
		msg += 64;
	}
	if (len != 0)
		data->end = msg;
}
