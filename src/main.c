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

int	main(int ac, char **av)
{
	t_struct	all;
	int			visual;

	ft_bzero(&all, sizeof(t_struct));
	if (ac == 1)
	{
        parser(&all);
		ft_solution(&all, NULL, NULL, 0, NULL);
        exit(0);
    }
	return (0);
}
