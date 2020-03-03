/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjasper <bjasper@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/21 14:35:54 by bjasper           #+#    #+#             */
/*   Updated: 2020/01/20 21:10:59 by bjasper          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_static(char *str, char **line)
{
	ssize_t		lento;
	ssize_t		lenstr;
	char		*tmp;

	lento = ft_strlento(str, '\n');
	*line = ft_strsub(str, 0, lento);
	lenstr = ft_strlen(str) - lento - 1;
	tmp = NULL;
	if (lenstr > 0)
	{
		tmp = ft_strsub(str, (lento + 1), lenstr);
		ft_strdel(&str);
	}
	if (tmp)
	{
		str = ft_strdup(tmp);
		ft_strdel(&tmp);
	}
	else
		ft_strdel(&str);
	return (str);
}

char			*ft_joindel(char *s1, char *s2)
{
	char		*s3;

	s3 = ft_strjoin(s1, s2);
	ft_strdel(&s1);
	return (s3);
}

int				get_next_line(const int fd, char **line)
{
	char		buff[BUFF_SIZE + 1];
	static char	*str[10520];
	int			i;

	if (fd < 0 || !line)
		return (-1);
	while ((i = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[i] = '\0';
		str[fd] = (str[fd]) ? ft_joindel(str[fd], buff) : ft_strdup(buff);
		if (ft_strchr(str[fd], '\n') || i < BUFF_SIZE)
			break ;
	}
	if (i < 0)
		return (-1);
	if (str[fd])
		str[fd] = ft_static(str[fd], line);
	else
		return (0);
	return (1);
}
