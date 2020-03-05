/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjasper <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 17:01:35 by bjasper           #+#    #+#             */
/*   Updated: 2019/09/20 16:35:53 by bjasper          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t hay_len;
	size_t need_len;

	if (!*needle)
		return ((char *)haystack);
	hay_len = ft_strlen(haystack);
	need_len = ft_strlen(needle);
	if (hay_len > len)
		hay_len = len;
	while (hay_len >= need_len)
	{
		if (ft_memcmp(haystack, needle, need_len) == 0)
			return ((char *)haystack);
		--hay_len;
		++haystack;
	}
	return (NULL);
}
