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

int				main(int ac, char **av)
{
	t_struct	*all;
	short		i;

	i = 0;
	all = (t_struct *)ft_memalloc(sizeof(t_struct));
	ft_bzero(all, sizeof(t_struct));
	if (ac == 1)
	{
		if (!parser(all, NULL, NULL, 0))
			return (0);
		start_actions(all);
		exit(0);
	}
	free(all);
	return (0);
}
