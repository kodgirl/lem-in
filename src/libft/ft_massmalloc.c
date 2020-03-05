/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_massmalloc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjasper <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 18:04:40 by bjasper           #+#    #+#             */
/*   Updated: 2019/09/18 20:20:49 by bjasper          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_massmalloc(char **dst, size_t len, int index)
{
	if (!(dst[index] = (char*)ft_memalloc(sizeof(char) * (len + 1))))
	{
		while (index >= 0)
		{
			free(dst[index]);
			--index;
		}
		return (NULL);
	}
	return (*dst);
}
