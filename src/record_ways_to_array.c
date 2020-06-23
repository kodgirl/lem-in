#include "../includes/lem_in.h"

t_room	**record_to_array(t_way *way, int quantity)
{
	t_room **array;
	t_way *read_way;
	unsigned i;

	i = 0;
	read_way = way;
	if (!(array = (t_room **)malloc(sizeof(t_room) * (quantity + 1))))
		exit(-1);
	while (read_way)
	{
		array[i] = read_way->room;
		read_way = read_way->next;
		i++;
	}
	return (array);
}