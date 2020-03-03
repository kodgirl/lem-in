/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   liba.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjasper <bjasper@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/08 18:01:06 by bjasper           #+#    #+#             */
/*   Updated: 2020/03/03 21:33:35 by bjasper          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/lem_in.h"

// void	f_lstadd(t_swap **stack, t_swap *new)
// {
// 	if (!*stack)
// 		new->next = NULL;
// 	else
// 	{
// 		new->next = *stack;
// 		*stack = new;
// 	}
// }

// t_swap	*f_lstnew(int num)
// {
// 	t_swap	*new;

// 	if (!(new = (t_swap *)ft_memalloc(sizeof(t_swap))))
// 		return (NULL);
// 	new->num = num;
// 	new->next = NULL;
// 	return (new);
// }

int		check_char(int *b, char str, int *error)
{
	int	check;

	check = *b;
	*b = (str - 48) + *b * 10;
	if (check != *b / 10)
	{
		*error = 1;
		write(1, ERROR_BIGGER_INT, 42);
		return (1);
	}
	return (0);
}

int		f_atoi(char *str, int *error)
{
	int		a;
	int		b;

	a = 1;
	b = 0;
	if (*str == 45 && str++)
		a = -a;
	if (*str < 48 || *str > 57)
	{
		*error = 1;
		write(1, ERROR_NOT_INT, 32);
		return (0);
	}
	while (*str >= 48 && *str <= 57)
	{
		if (check_char(&b, *str, error))
			return (0);
		str++;
	}
	if (*str != '\0')
	{
		*error = 1;
		write(1, ERROR_NOT_INT, 32);
	}
	return (a * b);
}

int 	array_len(char **str)
{
	int len;

	len = 0;
	while (str[len])
		++len;
	return (len);
}