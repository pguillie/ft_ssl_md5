/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sha256.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguillie <pguillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 14:25:57 by pguillie          #+#    #+#             */
/*   Updated: 2020/01/09 14:34:53 by pguillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sha256.h"

static int ft_sha256_invalid_opt(char opt)
{
	char msg[64];

	ft_strcpy(msg, "ft_ssl: sha256: invalid option -- '?'\n");
	msg[32] = opt;
	ft_puterr(msg);
	return (-1);
}

static int ft_sha256_opt_s(char *str, char *arg, int opt)
{
	if (*str != '\0') {
		ft_sha256_string(str, opt);
		return (1);
	} else if (arg != NULL) {
		ft_sha256_string(arg, opt);
		return (2);
	}
	ft_puterr("ft_ssl: sha256: option requires an argument -- 's'\n");
	return (-1);
}

static int ft_sha256_opt(char **arg, int *opt, int *input)
{
	char *str;

	str = *arg;
	while (*++str) {
		if (*str == 'p') {
			*input += 1;
			ft_sha256_stdin(1);
		} else if (*str == 'q') {
			*opt |= SHA256_QUIET;
		} else if (*str == 'r') {
			*opt |= SHA256_REVERSE;
		} else if (*str == 's') {
			*input += 1;
			return (ft_sha256_opt_s(str + 1, *(arg + 1), *opt));
		} else {
			return (ft_sha256_invalid_opt(*str));
		}
	}
	return (1);
}

static char **ft_sha256_arg(char **arg, int *opt, int *input)
{
	int inc;

	while (*arg && (*arg)[0] == '-' && (*arg)[1] != '\0') {
		if (ft_strcmp(*arg, "--") == 0) {
			arg++;
			break;
		}
		inc = ft_sha256_opt(arg, opt, input);
		if (inc < 0) {
			*opt = -1;
			break;
		}
		arg += inc;
	}
	return (arg);
}

int ft_sha256(char *args[])
{
	char **file;
	int opt;
	int input;

	opt = 0;
	input = 0;
	file = ft_sha256_arg(args, &opt, &input);
	if (opt < 0)
		return (1);
	if (*file == NULL && !input)
		ft_sha256_stdin(0);
	while (*file)
		ft_sha256_file(*file++, opt);
	return (0);
}
