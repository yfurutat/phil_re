/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_wait_sleep.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfurutat <yfurutat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 18:13:57 by yfurutat          #+#    #+#             */
/*   Updated: 2023/12/30 15:37:22 by yfurutat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// 9L
t_time	get_current_time(int *err_ptr)
{
	struct timeval	tp;
	int				err_id;

	err_id = gettimeofday(&tp, NULL);
	if (err_ptr)
		*err_ptr = err_id;
	if (err_id != OK)
		return (UINTMAX_MAX);
	return ((tp.tv_usec / 1000) + (tp.tv_sec * 1000));
}

// 9L
int	wait_until_start_time(t_ph *philo)
{
	pthread_mutex_lock(&philo->pr->act_order);
	if (philo->pr->end_status == true)
	{
		philo->dead = true;
		pthread_mutex_unlock(&philo->pr->act_order);
		return (DEAD);
	}
	pthread_mutex_unlock(&philo->pr->act_order);
	sleep_until(philo->pr->start_time);
	return (OK);
}

// 9L
int	sleep_until(t_time finish_time)
{
	int	err_id;

	while (get_current_time(&err_id) < finish_time)
	{
		if (err_id != OK)
			return (E_GETTIME);
		usleep(US_TIME);
	}
	return (OK);
}

// 13L
int	ft_millisleep(t_time sleep_time)
{
	t_time	start_time;
	int		err_id;

	start_time = get_current_time(&err_id);
	if (err_id != OK)
		return (err_id);
	while (get_current_time(&err_id) - start_time < sleep_time)
	{
		if (err_id != OK)
			return (E_GETTIME);
		usleep(US_TIME);
	}
	return (OK);
}
