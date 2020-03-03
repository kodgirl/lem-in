/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjasper <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 20:00:18 by bjasper           #+#    #+#             */
/*   Updated: 2019/09/19 21:40:02 by bjasper          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char	*dst;
	ssize_t	len;

	len = 0;
	if (!s)
		return (NULL);
	while (*s && (*s == ' ' || *s == '\n' || *s == '\t'))
		++s;
	while (*s)
	{
		++s;
		++len;
	}
	while (len && (*s == ' ' || *s == '\n' || *s == '\t' || *s == '\0'))
	{
		--len;
		--s;
	}
	if (!(dst = (char *)ft_strnew(len + 1)))
		return (NULL);
	while (len >= 0)
		dst[len--] = *s--;
	return (dst);
}
