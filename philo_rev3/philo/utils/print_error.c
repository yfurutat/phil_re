/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfurutat <yfurutat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 04:21:52 by yfurutat          #+#    #+#             */
/*   Updated: 2023/12/30 05:40:25 by yfurutat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static char	*_what_error(int err_id);

// 18L
int	print_error(int err_id)
{
	int			ret;
	const char	*str = _what_error(err_id);

	if (err_id == OK || err_id == FULL)
		return (OK);
	ret = ft_putstr_fd(ANSI_BOLD_RED, STDERR_FILENO);
	if (ret < 0)
		return (print_error(err_id));
	ret = ft_putstr_fd("ERROR: ", STDERR_FILENO);
	if (ret < 0)
		return (print_error(err_id));
	ret = ft_putstr_fd(str, STDERR_FILENO);
	if (ret < 0)
		return (print_error(err_id));
	ret = ft_putstr_fd(ANSI_RESET, STDERR_FILENO);
	if (ret < 0)
		return (print_error(err_id));
	return (OK);
}

// 25L
static char	*_what_error(int err_id)
{
	if (err_id == E_EMPTY)
		return ("EMPTY PARAMETER\n");
	else if (err_id == E_INVALID_ARGC)
		return ("INVALID_ARGC\n");
	else if (err_id == E_NONDIGIT)
		return ("NON-DIGIT ARGV\n");
	else if (err_id == E_INVALID_LEN)
		return ("INVALID LENGTH\n");
	else if (err_id == E_INVALID_VALUE)
		return ("INVALID VALUE\n");
	else if (err_id == E_ALLOC)
		return ("ALLOCATION FAILED\n");
	else if (err_id == E_INITF)
		return ("INITIALIZATION FAILED\n");
	else if (err_id == E_GETTIME)
		return ("GETTIME FAILED\n");
	else if (err_id == E_PTHREAD_CREATE)
		return ("PTHREAD CREATION FAILED\n");
	else if (err_id == E_DESTROY)
		return ("DESTRUCTION FAILED\n");
	else if (err_id == E_PRINT)
		return ("PRINT FAILED\n");
	return ("NO ERROR...ACTUALLY\n");
}
