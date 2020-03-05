/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjasper <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 13:38:06 by bjasper           #+#    #+#             */
/*   Updated: 2019/09/20 16:34:40 by bjasper          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	size_t hay_len;
	size_t need_len;

	hay_len = ft_strlen(haystack);
	need_len = ft_strlen(needle);
	if (!*needle)
		return ((char *)haystack);
	while (need_len <= hay_len)
	{
		if (ft_memcmp(haystack, needle, need_len) == 0)
			return ((char *)haystack);
		--hay_len;
		++haystack;
	}
	return (NULL);
}
