/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfurutat <yfurutat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 12:46:04 by efmacm23          #+#    #+#             */
/*   Updated: 2023/12/30 05:38:06 by yfurutat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void		_set_param(char **argv, t_param *pr);
static int		_check_range(t_param *pr);

// 10L
int	parse_args(int argc, char **argv, t_param *pr)
{
	int	err_id;

	if (argc != 5 && argc != 6)
		return (E_INVALID_ARGC);
	err_id = ft_aredigit_strs(argv);
	if (err_id != OK)
		return (err_id);
	_set_param(argv, pr);
	err_id = _check_range(pr);
	return (err_id);
}

// 7L
static void	_set_param(char **argv, t_param *pr)
{
	pr->num_philos = ft_atoll(argv[1]);
	pr->time_to_die = ft_atoll(argv[2]);
	pr->time_to_eat = ft_atoll(argv[3]);
	pr->time_to_sleep = ft_atoll(argv[4]);
	pr->min_times_to_eat = INT_MAX;
	if (argv[5])
		pr->min_times_to_eat = ft_atoll(argv[5]);
}

// 11L
static int	_check_range(t_param *pr)
{
	if (pr->num_philos <= 0 || pr->num_philos > INT_MAX)
		return (E_INVALID_VALUE);
	if (pr->time_to_die <= 0 || pr->time_to_die > INT_MAX)
		return (E_INVALID_VALUE);
	if (pr->time_to_eat <= 0 || pr->time_to_eat > INT_MAX)
		return (E_INVALID_VALUE);
	if (pr->time_to_sleep <= 0 || pr->time_to_sleep > INT_MAX)
		return (E_INVALID_VALUE);
	if (pr->min_times_to_eat < 0 || pr->min_times_to_eat > INT_MAX)
		return (E_INVALID_VALUE);
	return (OK);
}
