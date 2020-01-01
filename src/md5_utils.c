/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   md5_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguillie <pguillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/23 15:08:10 by pguillie          #+#    #+#             */
/*   Updated: 2019/12/29 12:20:20 by pguillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

inline uint32_t md5_f(uint32_t x, uint32_t y, uint32_t z)
{
	return ((x & y) | (~x & z));
}

inline uint32_t md5_g(uint32_t x, uint32_t y, uint32_t z)
{
	return ((x & z) | (y & ~z));
}

inline uint32_t md5_h(uint32_t x, uint32_t y, uint32_t z)
{
	return (x ^ y ^ z);
}

inline uint32_t md5_i(uint32_t x, uint32_t y, uint32_t z)
{
	return (y ^ (x | ~z));
}

inline uint32_t md5_shift(uint32_t x, int s)
{
	return ((x << s) | (x >> (32 - s)));
}
