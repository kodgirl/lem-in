/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjasper <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 14:12:35 by bjasper           #+#    #+#             */
/*   Updated: 2019/09/19 19:11:50 by bjasper          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strdup(const char *src)
{
	int			len;
	char		*res;
	int			i;

	i = 0;
	len = ft_strlen(src);
	res = (char*)malloc(sizeof(char) * (len + 1));
	if (res == NULL)
		return (NULL);
	while (src[i])
	{
		res[i] = (char)src[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}
