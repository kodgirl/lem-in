/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjasper <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/08 18:01:06 by bjasper           #+#    #+#             */
/*   Updated: 2019/09/21 13:51:08 by bjasper          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	int					a;
	unsigned long int	b;
	size_t				check;

	a = 1;
	b = 0;
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	if (*str == 45)
	{
		a = -a;
		str++;
	}
	else if (*str == 43)
		str++;
	while (*str >= 48 && *str <= 57)
	{
		check = b;
		b = (*str - 48) + b * 10;
		if (check != b / 10)
			return (a == 1 ? -1 : 0);
		str++;
	}
	return (a * b);
}
