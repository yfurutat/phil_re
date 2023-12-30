/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfurutat <yfurutat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 12:52:53 by efmacm23          #+#    #+#             */
/*   Updated: 2023/12/30 05:28:05 by yfurutat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// 13L
int	print_msg(t_ph *philo, const char *action)
{
	t_time	time_stamp;

	pthread_mutex_lock(&philo->pr->act_order);
	time_stamp = get_current_time(NULL) - (philo->pr->start_time);
	if (philo->pr->end_status == true)
	{
		pthread_mutex_unlock(&philo->pr->act_order);
		return (DEAD);
	}
	printf("%ju %lld %s\n", time_stamp, philo->id, action);
	if (action[0] == 'd')
		philo->pr->end_status = true;
	pthread_mutex_unlock(&philo->pr->act_order);
	return (OK);
}

ssize_t	ft_putstr_fd(const char *str, int fd)
{
	return (write(fd, str, ft_strlen(str)));
}

size_t	ft_strlen(const char *str)
{
	size_t	len;

	if (str == NULL)
		return (0);
	len = 0;
	while (str[len])
	{
		len++;
	}
	return (len);
}
