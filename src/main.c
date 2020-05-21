/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjasper <bjasper@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 15:33:18 by bjasper           #+#    #+#             */
/*   Updated: 2020/03/14 20:22:58 by bjasper          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

//FIXME проработать момент ошибки в парсере. Если ошибка, то не должен идти в ft_solution.
//FIXME поэтому сегается также, когда нет комнат.
//FIXME Сегается, когда нет решения, т.к. переходит к решению.
//TODO узнать как правильно понять требование The program accepts ant-farms with commands other than ##start ##end.
//TODO узнать что значит Commands and comments are printed on the standart output;
//FIXME  тесте из сабджекта не показывает количество муравьёв.
//FIXME любой дополнительный комментарий вызывает ошибку.

int		main(int ac, char **av)
{
	t_struct	all;
	int			visual;
	short 		i;

	i = 0;
	ft_bzero(&all, sizeof(t_struct));
	ft_printf("OLOLOLOLO");
	if (ac == 1)
	{
        if (!parser(&all, NULL, NULL))
			return (0);
		i = ft_solution(&all, NULL, NULL, NULL);
		if (i)
			exit (1); // Распечатай ошибку и освободи всё.
        exit(0);
    }
	return (0);
}
