/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfurutat <yfurutat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 10:51:34 by efmacm23          #+#    #+#             */
/*   Updated: 2023/12/30 06:40:45 by yfurutat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// 20L
int	main(int argc, char **argv)
{
	t_data	data;
	int		ret;

	ret = prep_party(argc, argv, &data);
	if (ret != OK)
		return (party_over(&data, ret));
	ret = start_party(&data);
	if (ret != OK)
		return (party_over(&data, ret));
	while (ret == OK)
		ret = observe_party(&data);
	if (join_the_line(data.threads, data.pr.num_philos) != OK)
		ret = E_PTHREAD_JOIN;
	return (party_over(&data, ret));
}

__attribute__((destructor))
static void	destructor()
{
	system("leaks -q philo");
	// system("sudo leaks -q philo");
	// system("leaks -q test.sh");
}
