/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sha256_file.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguillie <pguillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 20:31:03 by pguillie          #+#    #+#             */
/*   Updated: 2020/01/15 23:25:38 by pguillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sha256.h"

static int	ft_sha256_file_open(const char *file)
{
	struct stat	sb;
	int			fd;

	fd = open(file, O_RDONLY);
	if (fd == -1 || fstat(fd, &sb) == -1)
	{
		ft_puterr("ft_ssl: sha256: ");
		ft_puterr(file);
		ft_puterr(": unable to open file\n");
		return (-1);
	}
	if (S_ISDIR(sb.st_mode))
	{
		ft_puterr("ft_ssl: sha256: ");
		ft_puterr(file);
		ft_puterr(": is a directory\n");
		close(fd);
		return (-1);
	}
	return (fd);
}

static void	ft_sha256_file_print(uint32_t digest[4], const char *file, int opt)
{
	if (!(opt & SHA256_REVERSE))
	{
		ft_putstr("SHA256 (");
		ft_putstr(file);
		ft_putstr(") = ");
	}
	ft_sha256_print_digest(digest);
	if (opt == SHA256_REVERSE)
	{
		ft_putstr(" ");
		ft_putstr(file);
	}
	ft_putstr("\n");
}

int			ft_sha256_file(const char *filename, int opt)
{
	struct s_sha256_data	data;
	char					buf[1024];
	ssize_t					n;
	int						fd;

	fd = ft_sha256_file_open(filename);
	if (fd == -1)
		return (1);
	ft_sha256_init(&data);
	while ((n = read(fd, buf, sizeof(buf))) > 0)
		ft_sha256_process_message(&data, buf, n);
	close(fd);
	ft_sha256_append_length(&data);
	ft_sha256_file_print(data.digest, filename, opt);
	return (0);
}
