/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_md5_file.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguillie <pguillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 20:31:03 by pguillie          #+#    #+#             */
/*   Updated: 2020/01/15 22:12:16 by pguillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_md5.h"

static int	ft_md5_file_open(const char *file)
{
	struct stat	sb;
	int			fd;

	fd = open(file, O_RDONLY);
	if (fd == -1 || fstat(fd, &sb) == -1)
	{
		ft_puterr("ft_ssl: md5: ");
		ft_puterr(file);
		ft_puterr(": unable to open file\n");
		return (-1);
	}
	if (S_ISDIR(sb.st_mode))
	{
		ft_puterr("ft_ssl: md5: ");
		ft_puterr(file);
		ft_puterr(": is a directory\n");
		close(fd);
		return (-1);
	}
	return (fd);
}

static void	ft_md5_file_print(uint32_t digest[4], const char *file, int opt)
{
	if (!(opt & MD5_REVERSE))
	{
		ft_putstr("MD5 (");
		ft_putstr(file);
		ft_putstr(") = ");
	}
	ft_md5_print_digest(digest);
	if (opt == MD5_REVERSE)
	{
		ft_putstr(" ");
		ft_putstr(file);
	}
	ft_putstr("\n");
}

int			ft_md5_file(const char *filename, int opt)
{
	struct s_md5_data	data;
	char				buf[1024];
	ssize_t				n;
	int					fd;

	fd = ft_md5_file_open(filename);
	if (fd == -1)
		return (1);
	ft_md5_init(&data);
	while ((n = read(fd, buf, sizeof(buf))) > 0)
		ft_md5_process_message(&data, buf, n);
	close(fd);
	ft_md5_append_length(&data);
	ft_md5_file_print(data.digest, filename, opt);
	return (0);
}
