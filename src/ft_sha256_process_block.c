/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sha256_process_block.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguillie <pguillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/24 19:19:35 by pguillie          #+#    #+#             */
/*   Updated: 2020/01/15 23:23:17 by pguillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sha256.h"

/*
** table[i] represents the first thirty-two bits of the fractional
** parts of the cube roots of the i-th prime number.
*/

const uint32_t			g_sha256_table[64] = {
	0x428a2f98, 0x71374491, 0xb5c0fbcf, 0xe9b5dba5, 0x3956c25b,
	0x59f111f1, 0x923f82a4, 0xab1c5ed5, 0xd807aa98, 0x12835b01,
	0x243185be, 0x550c7dc3, 0x72be5d74, 0x80deb1fe, 0x9bdc06a7,
	0xc19bf174, 0xe49b69c1, 0xefbe4786, 0x0fc19dc6, 0x240ca1cc,
	0x2de92c6f, 0x4a7484aa, 0x5cb0a9dc, 0x76f988da, 0x983e5152,
	0xa831c66d, 0xb00327c8, 0xbf597fc7, 0xc6e00bf3, 0xd5a79147,
	0x06ca6351, 0x14292967, 0x27b70a85, 0x2e1b2138, 0x4d2c6dfc,
	0x53380d13, 0x650a7354, 0x766a0abb, 0x81c2c92e, 0x92722c85,
	0xa2bfe8a1, 0xa81a664b, 0xc24b8b70, 0xc76c51a3, 0xd192e819,
	0xd6990624, 0xf40e3585, 0x106aa070, 0x19a4c116, 0x1e376c08,
	0x2748774c, 0x34b0bcb5, 0x391c0cb3, 0x4ed8aa4a, 0x5b9cca4f,
	0x682e6ff3, 0x748f82ee, 0x78a5636f, 0x84c87814, 0x8cc70208,
	0x90befffa, 0xa4506ceb, 0xbef9a3f7, 0xc67178f2
};

static inline uint32_t	rotr(uint32_t x, int n)
{
	return ((x >> n) | (x << (32 - n)));
}

static void				prepare_schedule(uint32_t w[64], uint32_t block[16])
{
	size_t i;

	i = 0;
	while (i < 16)
	{
		w[i] = \
			((block[i] & 0xff) << 24)
			| ((block[i] & (0xff << 8)) << 8)
			| ((block[i] & (0xff << 16)) >> 8)
			| ((block[i] & (0xff << 24)) >> 24);
		i++;
	}
	while (i < 64)
	{
		w[i] = w[i - 7] + w[i - 16];
		w[i] += rotr(w[i - 2], 17) ^ rotr(w[i - 2], 19)
			^ (w[i - 2] >> 10);
		w[i] += rotr(w[i - 15], 7) ^ rotr(w[i - 15], 18)
			^ (w[i - 15] >> 3);
		i++;
	}
}

static void				compute(uint32_t d[4], uint32_t w[64])
{
	uint32_t	t[2];
	size_t		i;

	i = 0;
	while (i < 64)
	{
		t[0] = (rotr(d[4], 6) ^ rotr(d[4], 11) ^ rotr(d[4], 25))
			+ ((d[4] & d[5]) ^ ((~d[4]) & d[6]))
			+ d[7] + g_sha256_table[i] + w[i];
		t[1] = (rotr(d[0], 2) ^ rotr(d[0], 13) ^ rotr(d[0], 22))
			+ ((d[0] & d[1]) ^ (d[0] & d[2]) ^ (d[1] & d[2]));
		d[7] = d[6];
		d[6] = d[5];
		d[5] = d[4];
		d[4] = d[3] + t[0];
		d[3] = d[2];
		d[2] = d[1];
		d[1] = d[0];
		d[0] = t[0] + t[1];
		i++;
	}
}

void					ft_sha256_process_block(uint32_t digest[8],
		uint32_t block[16])
{
	uint32_t	save[8];
	uint32_t	schedule[64];
	size_t		i;

	prepare_schedule(schedule, block);
	ft_memcpy(save, digest, sizeof(save));
	compute(digest, schedule);
	i = 8;
	while (i--)
		digest[i] += save[i];
}
