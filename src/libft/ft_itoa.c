/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjasper <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 15:42:57 by bjasper           #+#    #+#             */
/*   Updated: 2019/09/17 21:17:09 by bjasper          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	char	*str;
	size_t	len;
	int		a;

	a = 1;
	len = ft_nbrlen(n);
	if (!(str = ft_strnew(len)))
		return (NULL);
	if (n < 0)
		a = -1;
	while (len)
	{
		--len;
		str[len] = (char)((n % 10) * a + 48);
		n /= 10;
	}
	if (a == -1)
		str[0] = '-';
	return (str);
}
