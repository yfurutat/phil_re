/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_act.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfurutat <yfurutat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 19:47:24 by efmacm23          #+#    #+#             */
/*   Updated: 2023/12/30 06:16:58 by yfurutat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	_philo_pick_up_fork(t_ph *philo);
static int	_philo_eat(t_ph *philo);
static int	_philo_sleep(t_ph *philo);
static int	_philo_think(t_ph *philo);

// 13L
void	*philo_act(void *param)
{
	t_ph	*philo;

	philo = (t_ph *)param;
	if (wait_until_start_time(philo) != OK)
		return (NULL);
	if (philo->pr->min_times_to_eat == 0)
		return (NULL);
	if (philo->id % 2 == 0)
		ft_millisleep(philo->pr->time_to_eat / 2);
	while (1)
	{
		if (_philo_eat(philo))
			break ;
		if (_philo_sleep(philo))
			break ;
		if (_philo_think(philo))
			break ;
	}
	return (NULL);
}

// 23L
static int	_philo_pick_up_fork(t_ph *philo)
{
	pthread_mutex_lock(philo->first_fork);
	if (print_msg(philo, ACT_FORK) == DEAD || philo->pr->num_philos == 1)
	{
		pthread_mutex_unlock(philo->first_fork);
		return (DEAD);
	}
	pthread_mutex_lock(philo->second_fork);
	if (print_msg(philo, ACT_FORK) == DEAD)
	{
		pthread_mutex_unlock(philo->second_fork);
		pthread_mutex_unlock(philo->first_fork);
		return (DEAD);
	}
	return (OK);
}

// 20L
static int	_philo_eat(t_ph *philo)
{
	if (_philo_pick_up_fork(philo) != OK)
		return (DEAD);
	pthread_mutex_lock(philo->dine);
	if (print_msg(philo, ACT_EAT) == DEAD)
	{
		pthread_mutex_unlock(philo->dine);
		pthread_mutex_unlock(philo->second_fork);
		pthread_mutex_unlock(philo->first_fork);
		return (DEAD);
	}
	philo->last_eat_time = get_current_time(NULL);
	philo->eat_times++;
	pthread_mutex_unlock(philo->dine);
	if (ft_millisleep(philo->pr->time_to_eat))
		return (E_GETTIME);
	pthread_mutex_unlock(philo->second_fork);
	pthread_mutex_unlock(philo->first_fork);
	if (philo->eat_times == philo->pr->min_times_to_eat)
		return (FULL);
	return (OK);
}

// 5L
static int	_philo_sleep(t_ph *philo)
{
	if (print_msg(philo, ACT_SLEEP) == DEAD)
		return (DEAD);
	if (ft_millisleep(philo->pr->time_to_sleep))
		return (E_GETTIME);
	return (OK);
}

// 3L
static int	_philo_think(t_ph *philo)
{
	if (print_msg(philo, ACT_THINK) == DEAD)
		return (DEAD);
	return (OK);
}
