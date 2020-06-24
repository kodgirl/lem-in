#include "../includes/lem_in.h"

void 	print_ants(int ant, char *room, short space)
{
	ft_putchar('L');
	ft_putnbr(ant);
	ft_putchar('-');
	ft_putstr(room);
	if (space)
		ft_putchar(' ');
}