/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ssl.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguillie <pguillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/23 12:30:32 by pguillie          #+#    #+#             */
/*   Updated: 2020/01/15 21:57:47 by pguillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SSL_H
# define FT_SSL_H

# include "ft_md5.h"
# include "ft_sha256.h"
# include "libft.h"

typedef int		(*t_ssl_command)(char *arg[]);

struct			s_ssl_cmd
{
	char			*cmd;
	t_ssl_command	func;
};

int				ft_ssl_invalid_command(const char *invalid);

t_ssl_command	ft_ssl_set_command(const char *command);

#endif
