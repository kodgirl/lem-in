#include "../includes/lem_in.h"

void 	print_way(t_room **arr)
{
	int 	i;

	i = 0;

	ft_printf("\nWays\n");
	while (arr[i])
	{
		ft_printf("%s -> ", arr[i]->name);
		i++;
	}
}