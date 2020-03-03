/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjasper <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/09 14:58:16 by bjasper           #+#    #+#             */
/*   Updated: 2019/09/21 14:18:06 by bjasper          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strncpy(char *dst, const char *src, size_t len)
{
	char	*buf;

	buf = dst;
	while (len && *src)
	{
		*dst = *src;
		dst++;
		src++;
		len--;
	}
	while (len)
	{
		*dst++ = '\0';
		len--;
	}
	return (buf);
}
