/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjasper <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 14:22:07 by bjasper           #+#    #+#             */
/*   Updated: 2019/09/11 15:55:42 by bjasper          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*point;

	point = (unsigned char *)s;
	while (n)
	{
		if (*point == (unsigned char)c)
			return (point);
		point++;
		n--;
	}
	return (NULL);
}
