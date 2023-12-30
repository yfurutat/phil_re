/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efmacm23 <efmacm23@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 11:45:03 by efmacm23          #+#    #+#             */
/*   Updated: 2023/12/27 11:55:03 by efmacm23         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long long	ft_atoll(const char *str)
{
	long long	num;
	int			sign;

	num = 0;
	sign = 1;
	if (*str == '-')
		sign = -1;
	if (*str == '+' || *str == '-')
		str++;
	while (ft_isdigit(*str))
	{
		if (num > LLONG_MAX / 10 || \
			(num == LLONG_MAX / 10 && *str - '0' > LLONG_MAX % 10))
		{
			if (sign == -1)
				return (LLONG_MIN);
			return (LLONG_MAX);
		}
		num = (num * 10) + (*str - '0');
		str++;
	}
	return (num * sign);
}
