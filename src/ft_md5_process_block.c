/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_md5_process_block.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguillie <pguillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/24 19:19:35 by pguillie          #+#    #+#             */
/*   Updated: 2020/01/09 20:11:26 by pguillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_md5.h"

/*
** table[i] is equal to the integer part of 4294967296 times abs(sin(i + 1)),
** where i is in radians.
*/
const uint32_t g_md5_process_table[64] = {
	0xd76aa478, 0xe8c7b756, 0x242070db, 0xc1bdceee, 0xf57c0faf,
	0x4787c62a, 0xa8304613, 0xfd469501, 0x698098d8, 0x8b44f7af,
	0xffff5bb1, 0x895cd7be, 0x6b901122, 0xfd987193, 0xa679438e,
	0x49b40821, 0xf61e2562, 0xc040b340, 0x265e5a51, 0xe9b6c7aa,
	0xd62f105d, 0x02441453, 0xd8a1e681, 0xe7d3fbc8, 0x21e1cde6,
	0xc33707d6, 0xf4d50d87, 0x455a14ed, 0xa9e3e905, 0xfcefa3f8,
	0x676f02d9, 0x8d2a4c8a, 0xfffa3942, 0x8771f681, 0x6d9d6122,
	0xfde5380c, 0xa4beea44, 0x4bdecfa9, 0xf6bb4b60, 0xbebfbc70,
	0x289b7ec6, 0xeaa127fa, 0xd4ef3085, 0x04881d05, 0xd9d4d039,
	0xe6db99e5, 0x1fa27cf8, 0xc4ac5665, 0xf4292244, 0x432aff97,
	0xab9423a7, 0xfc93a039, 0x655b59c3, 0x8f0ccc92, 0xffeff47d,
	0x85845dd1, 0x6fa87e4f, 0xfe2ce6e0, 0xa3014314, 0x4e0811a1,
	0xf7537e82, 0xbd3af235, 0x2ad7d2bb, 0xeb86d391
};

static void ft_md5_round1(uint32_t d[4], uint32_t x[16])
{
	const int s[4] = {7, 12, 17, 22};
	uint32_t tmp;
	int k;
	int i;

	k = 0;
	i = 0;
	while (i < 16) {
		d[0] += ((d[1] & d[2]) | (~d[1] & d[3])) + x[k]
			+ g_md5_process_table[i];
		d[0] = ((d[0] << s[i & 0x3]) | (d[0] >> (32 - s[i & 0x3])));
		d[0] += d[1];
		tmp = d[3];
		d[3] = d[2];
		d[2] = d[1];
		d[1] = d[0];
		d[0] = tmp;
		k = (k + 1) & 0xf;
		i += 1;
	}
}

static void ft_md5_round2(uint32_t d[4], uint32_t x[16])
{
	const int s[4] = {5, 9, 14, 20};
	uint32_t tmp;
	int k;
	int i;

	k = 1;
	i = 16;
	while (i < 32) {
		d[0] += ((d[1] & d[3]) | (d[2] & ~d[3])) + x[k]
			+ g_md5_process_table[i];
		d[0] = ((d[0] << s[i & 0x3]) | (d[0] >> (32 - s[i & 0x3])));
		d[0] += d[1];
		tmp = d[3];
		d[3] = d[2];
		d[2] = d[1];
		d[1] = d[0];
		d[0] = tmp;
		k = (k + 5) & 0xf;
		i += 1;
	}

}

static void ft_md5_round3(uint32_t d[4], uint32_t x[16])
{
	const int s[4] = {4, 11, 16, 23};
	uint32_t tmp;
	int k;
	int i;

	k = 5;
	i = 32;
	while (i < 48) {
		d[0] += (d[1] ^ d[2] ^ d[3]) + x[k] + g_md5_process_table[i];
		d[0] = ((d[0] << s[i & 0x3]) | (d[0] >> (32 - s[i & 0x3])));
		d[0] += d[1];
		tmp = d[3];
		d[3] = d[2];
		d[2] = d[1];
		d[1] = d[0];
		d[0] = tmp;
		k = (k + 3) & 0xf;
		i += 1;
	}

}

static void ft_md5_round4(uint32_t d[4], uint32_t x[16])
{
	const int s[4] = {6, 10, 15, 21};
	uint32_t tmp;
	int k;
	int i;

	k = 0;
	i = 48;
	while (i < 64) {
		d[0] += (d[2] ^ (d[1] | ~d[3])) + x[k] + g_md5_process_table[i];
		d[0] = ((d[0] << s[i & 0x3]) | (d[0] >> (32 - s[i & 0x3])));
		d[0] += d[1];
		tmp = d[3];
		d[3] = d[2];
		d[2] = d[1];
		d[1] = d[0];
		d[0] = tmp;
		k = (k + 7) & 0xf;
		i += 1;
	}

}

void ft_md5_process_block(uint32_t digest[4], uint32_t block[16])
{
	uint32_t save[4];
	size_t i;

	ft_memcpy(save, digest, sizeof(save));
	ft_md5_round1(digest, block);
	ft_md5_round2(digest, block);
	ft_md5_round3(digest, block);
	ft_md5_round4(digest, block);
	i = 4;
	while (i--)
		digest[i] += save[i];
}
