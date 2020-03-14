/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjasper <bjasper@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 14:47:25 by bjasper           #+#    #+#             */
/*   Updated: 2020/03/14 19:35:47 by bjasper          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void			free_mem(char **str)
{
	int				i;

	i = 0;
	while (str[i])
	{
		free(&str[i]);
		i++;
	}
	free(str);
}

static size_t		ft_count(const char *s, char c)
{
	size_t			n;

	n = 0;
	while (*s)
	{
		while (*s == c && *s)
			++s;
		if (*s != c && *s)
		{
			while (*s != c && *s)
				++s;
			++n;
		}
	}
	return (n);
}

char				**ft_strsplit(const char *s, char c)
{
	char			**fresh;
	size_t			len;
	size_t			count;
	int				j;

	if (!s || !c)
		return (NULL);
	count = ft_count(s, c);
	if (!(fresh = (char **)malloc(sizeof(char *) * (count + 1))))
		return (NULL);
	j = 0;
	while (*s && count--)
	{
		s = ft_skip_sym(s, c);
		len = ft_strlento((char *)s, c);
		if (!(fresh[j] = ft_strnew(len)))
		{
			free_mem(fresh);
			return (NULL);
		}
		fresh[j] = ft_strccpy(fresh[j], s, c);
		++j;
		s += len;
	}
	fresh[j] = NULL;
	return (fresh);
}
