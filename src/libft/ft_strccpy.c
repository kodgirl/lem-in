/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjasper <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 19:17:57 by bjasper           #+#    #+#             */
/*   Updated: 2019/09/18 19:37:18 by bjasper          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strccpy(char *dst, const char *src, char c)
{
	int i;

	i = 0;
	while (*src != c && *src)
	{
		dst[i] = *src;
		++i;
		++src;
	}
	return (dst);
}
