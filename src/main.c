/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguillie <pguillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/22 15:28:54 by pguillie          #+#    #+#             */
/*   Updated: 2020/01/08 15:55:11 by pguillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

int main(int argc, char *argv[])
{
	t_ssl_command command;

	if (argc == 1) {
		ft_putstr("Usage: ft_ssl command"
			" [ command_opts ] [ command_args ]\n");
		return (1);
	}
	command = ft_ssl_set_command(argv[1]);
	if (command == NULL)
		return (ft_ssl_invalid_command(argv[1]));
	return (command(argv + 2));
}
