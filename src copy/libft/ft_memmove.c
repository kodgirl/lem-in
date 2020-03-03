/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjasper <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 16:57:03 by bjasper           #+#    #+#             */
/*   Updated: 2019/09/18 19:28:47 by bjasper          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*d;
	unsigned char	*s;
	size_t			i;

	i = 0;
	d = (unsigned char *)dst;
	s = (unsigned char *)src;
	if (d < s)
	{
		while (i < len)
		{
			d[i] = s[i];
			++i;
		}
	}
	else if (d > s)
	{
		i = 1;
		while (i <= len)
		{
			d[len - i] = s[len - i];
			++i;
		}
	}
	return (dst);
}
