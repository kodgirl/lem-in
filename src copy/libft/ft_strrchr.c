/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjasper <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 15:49:54 by bjasper           #+#    #+#             */
/*   Updated: 2019/09/20 16:32:47 by bjasper          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char *tmp;

	tmp = NULL;
	while (*s)
	{
		if (*s == (char)c)
			tmp = (char *)s;
		++s;
	}
	if (*s == '\0' && (char)c == '\0')
		tmp = (char *)s;
	return (tmp);
}
