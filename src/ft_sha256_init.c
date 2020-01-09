/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sha256_init.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguillie <pguillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/29 10:24:19 by pguillie          #+#    #+#             */
/*   Updated: 2020/01/09 20:01:24 by pguillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sha256.h"

void ft_sha256_init(struct s_sha256_data *data)
{
	(data->digest)[0] = 0x6a09e667;
        (data->digest)[1] = 0xbb67ae85;
        (data->digest)[2] = 0x3c6ef372;
        (data->digest)[3] = 0xa54ff53a;
        (data->digest)[4] = 0x510e527f;
        (data->digest)[5] = 0x9b05688c;
        (data->digest)[6] = 0x1f83d9ab;
	(data->digest)[7] = 0x5be0cd19;
	data->length = 0;
	data->end = NULL;
}
