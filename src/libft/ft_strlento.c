/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlento.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjasper <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 17:40:12 by bjasper           #+#    #+#             */
/*   Updated: 2019/09/18 19:46:47 by bjasper          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlento(char *s, char c)
{
	size_t len;

	len = 0;
	while (*s != c && *s)
	{
		++len;
		++s;
	}
	return (len);
}
