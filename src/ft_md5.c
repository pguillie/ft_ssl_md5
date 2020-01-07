/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_md5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguillie <pguillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/23 12:37:49 by pguillie          #+#    #+#             */
/*   Updated: 2020/01/08 20:42:21 by pguillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_md5.h"

static int ft_md5_invalid_opt(char opt)
{
	char msg[64];

	ft_strcpy(msg, "ft_ssl: md5: invalid option -- '?'\n");
	msg[32] = opt;
	ft_puterr(msg);
	return (-1);
}

static int ft_md5_opt_s(char *str, char *arg, int opt)
{
	if (*str != '\0') {
		ft_md5_string(str, opt);
		return (1);
	} else if (arg != NULL) {
		ft_md5_string(arg, opt);
		return (2);
	}
	ft_puterr("ft_ssl: md5: option requires an argument -- 's'\n");
	return (-1);
}

static int ft_md5_opt(char **arg, int *opt, int *input)
{
	char *str;

	str = *arg;
	while (*++str) {
		if (*str == 'p') {
			*input += 1;
			ft_md5_stdin(1);
		} else if (*str == 'q') {
			*opt |= MD5_QUIET;
		} else if (*str == 'r') {
			*opt |= MD5_REVERSE;
		} else if (*str == 's') {
			*input += 1;
			return (ft_md5_opt_s(str + 1, *(arg + 1), *opt));
		} else {
			return (ft_md5_invalid_opt(*str));
		}
	}
	return (1);
}

static char **ft_md5_arg(char **arg, int *opt, int *input)
{
	int inc;

	while (*arg && (*arg)[0] == '-' && (*arg)[1] != '\0') {
		if (ft_strcmp(*arg, "--") == 0) {
			arg++;
			break;
		}
		inc = ft_md5_opt(arg, opt, input);
		if (inc < 0) {
			*opt = -1;
			break;
		}
		arg += inc;
	}
	return (arg);
}

int ft_md5(char *args[])
{
	char **file;
	int opt;
	int input;

	opt = 0;
	input = 0;
	file = ft_md5_arg(args, &opt, &input);
	if (opt < 0)
		return (1);
	if (*file == NULL && !input)
		ft_md5_stdin(0);
	while (*file)
		ft_md5_file(*file++, opt);
	return (0);
}
