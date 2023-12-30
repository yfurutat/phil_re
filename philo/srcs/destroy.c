/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfurutat <yfurutat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 19:45:29 by efmacm23          #+#    #+#             */
/*   Updated: 2023/12/30 05:42:01 by yfurutat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// 15L
int	destroy_data(t_data *data)
{
	int		ret;

	ret = OK;
	if (data)
	{
		if (data->philos)
			free(data->philos);
		if (data->threads)
			free(data->threads);
		if (data->forks)
			ret = destroy_mutex_array(data->forks, (size_t)data->pr.num_philos);
		if (data->dine)
			ret = destroy_mutex_array(data->dine, (size_t)data->pr.num_philos);
	}
	return (ret);
}

// 16L
int	destroy_mutex_array(pthread_mutex_t *ptr, size_t num)
{
	size_t	i;
	int		err_id;

	err_id = OK;
	if (ptr == NULL)
		return (E_EMPTY);
	i = 0;
	while (i < num)
	{
		err_id = pthread_mutex_destroy(&ptr[i]);
		if (err_id != OK)
			break ;
		i++;
	}
	free(ptr);
	return (err_id);
}
