#include "../includes/lem_in.h"

#include <stdio.h>

t_list		*new_list(int i)
{
	t_list	*tr;
	int		*hi;

	tr = (t_list *)malloc(sizeof(t_list));
	hi = (int *)malloc(sizeof(int));
	*hi = i;
	tr->content = hi;
	tr->content_size = 0;
	tr->next = NULL;
	return (tr);
}

static int	get_ants(void)
{
	char	*line;
	int		tr;

	//Lecture de la premiere avec gnl
	gnl(&line);
	//Conversion du nb de fourmis en string
	tr = ft_atoi(line);
	free(line);
	send_error(tr <= 0);
	return (tr);
}

int			main(void)
{
	t_rooms	*rooms;
	int		ants;
	int		start;
	int		end;

	//Recuperation du nombre de fourmis
	ants = get_ants();
	rooms = NULL;
	start = -1;
	end = -1;
	//Recuperation des rooms et link
	add_rooms(&rooms, &start, &end);
	print_ants(ants, start, end, rooms);
	free_rooms(rooms);
	return (0);
}
