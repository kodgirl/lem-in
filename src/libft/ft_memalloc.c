/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjasper <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 16:58:06 by bjasper           #+#    #+#             */
/*   Updated: 2019/09/18 20:27:11 by bjasper          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void	*ar;

	if (size && (ar = (void*)malloc(sizeof(void) * size)))
		ft_bzero(ar, size);
	else
		return (NULL);
	return (ar);
}
