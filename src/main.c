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

int		main(int ac, char **av)
{
	t_struct	all;
	int			visual;
	short 		i;

	i = 0;
	ft_bzero(&all, sizeof(t_struct));
	if (ac == 1)
	{
		//FIXME проработать момент ошибки в парсере. Если ошибка, то не должен идти в ft_solution.
		//FIXME поэтому сегается также, когда нет комнат.
		//FIXME Сегается, когда нет решения, т.к. переходит к решению.
		//TODO узнать как правильно понять требование The program accepts ant-farms with commands other than ##start ##end.
		//TODO узнать что значит Commands and comments are printed on the standart output;

        parser(&all);
		i = ft_solution(&all, NULL, NULL, NULL);
		if (i)
			exit (1); // Распечатай ошибку и освободи всё.
        exit(0);
    }
	return (0);
}
