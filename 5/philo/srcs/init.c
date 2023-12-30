/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfurutat <yfurutat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 15:44:24 by efmacm23          #+#    #+#             */
/*   Updated: 2023/12/30 01:09:29 by yfurutat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static pthread_mutex_t	*_create_mutex_array(size_t num);

// 18L
int	init(t_data *data)
{
	size_t	num;

	num = (size_t)data->pr.num_philos;
	data->philos = malloc(num * sizeof(t_ph));
	if (data->philos == NULL)
		return (E_ALLOC);
	data->threads = malloc(num * sizeof(pthread_t));
	if (data->threads == NULL)
		return (E_ALLOC);
	data->forks = _create_mutex_array(num);
	if (data->forks == NULL)
		return (E_ALLOC);
	data->dine = _create_mutex_array(num);
	if (data->dine == NULL)
		return (E_ALLOC);
	if (pthread_mutex_init(&data->pr.act_order, NULL) != OK)
		return (E_ALLOC);
	return (OK);
}

// 21L
static pthread_mutex_t	*_create_mutex_array(size_t num)
{
	pthread_mutex_t	*ptr;
	size_t			i;
	int				err_id;

	if (num == 0)
		return (NULL);
	ptr = malloc(num * sizeof(pthread_mutex_t));
	if (ptr == NULL)
		return (NULL);
	i = 0;
	while (i < num)
	{
		err_id = pthread_mutex_init(&ptr[i], NULL);
		if (err_id != OK)
		{
			destroy_mutex_array(ptr, i);
			return (NULL);
		}
		i++;
	}
	return (ptr);
}
