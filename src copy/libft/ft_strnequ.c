/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjasper <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 20:32:38 by bjasper           #+#    #+#             */
/*   Updated: 2019/09/20 13:15:45 by bjasper          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strnequ(char const *s1, char const *s2, size_t n)
{
	unsigned char	*s11;
	unsigned char	*s22;

	s11 = (unsigned char *)s1;
	s22 = (unsigned char *)s2;
	if (!s1 || !s2)
		return (0);
	if (n == 0)
		return (1);
	else
	{
		while ((*s11 || *s22) && n)
		{
			if (*s11 != *s22)
				return (0);
			s11++;
			s22++;
			n--;
		}
		return (1);
	}
	return (0);
}
