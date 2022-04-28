/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchristi <lchristi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 21:14:14 by lchristi          #+#    #+#             */
/*   Updated: 2022/04/26 21:14:37 by lchristi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

int	ft_atoi(const char *nptr) //long?
{
	int			i;
	int			sign;
	long int	old;
	long int	num;

	i = 0;
	sign = 1;
	num = 0;
	while (nptr[i] == '\t' || nptr[i] == '\n' || nptr[i] == '\v' \
					|| nptr[i] == '\f' || nptr[i] == '\r' || nptr[i] == ' ')
		i++;
	if (nptr[i] == '-')
		sign = -1;
	if (nptr[i] == '-' || nptr[i] == '+')
		i++;
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		old = num;
		num = num * 10 + (nptr[i++] - '0');
		if ((old < 0 && num > 0) || (old > 0 && num < 0))
			return ((sign == 1) * -1);
	}
	return (num * sign);
}
