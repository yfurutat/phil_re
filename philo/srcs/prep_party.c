/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prep_party.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfurutat <yfurutat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 21:18:37 by efmacm23          #+#    #+#             */
/*   Updated: 2023/12/30 14:55:41 by yfurutat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	_register_philos(t_data *data);
static void	_prep_forks(t_data *data, size_t i);

// 11L
int	prep_party(int argc, char **argv, t_data *data)
{
	int	err_id;

	memset(data, '\0', sizeof(t_data));
	err_id = parse_args(argc, argv, &(data->pr));
	if (err_id != OK)
		return (err_id);
	err_id = init(data);
	if (err_id != OK)
		return (err_id);
	_register_philos(data);
	return (err_id);
}

// 23L
static void	_register_philos(t_data *data)
{
	size_t	i;

	i = 0;
	while (i < (size_t)data->pr.num_philos)
	{
		data->philos[i].eat_times = 0;
		data->philos[i].dine = &data->dine[i];
		data->philos[i].id = i + 1;
		data->philos[i].pr = &data->pr;
		_prep_forks(data, i);
		i++;
	}
}

// 5L
// static void	_prep_forks(t_data *data, size_t i)
// {
// 	data->philos[i].first_fork = &data->forks[i];
// 	if (i + 1 == (size_t)data->pr.num_philos)
// 		data->philos[i].second_fork = &data->forks[0];
// 	else
// 		data->philos[i].second_fork = &data->forks[i + 1];
// }

// 18L
static void	_prep_forks(t_data *data, size_t i)
{
	pthread_mutex_t	*fork_r;
	pthread_mutex_t	*fork_l;

	fork_r = &data->forks[i];
	fork_l = &data->forks[(i + 1)% data->pr.num_philos];
	if (data->philos[i].id % 2 == 0)
	{
		data->philos[i].first_fork = fork_r;
		data->philos[i].second_fork = fork_l;
	}
	else if (data->philos[i].id % 2 == 1)
	{
		data->philos[i].first_fork = fork_l;
		data->philos[i].second_fork = fork_r;
	}
}
