#include "../includes/lem_in.h"

int		pop_to_visit(t_queue *to_visit)
{
	t_list	*val;
	int		tr;

	val = pop(to_visit);
	tr = gfp((int *)val->content);
	free(val->content);
	free(val);
	return (tr);
}

t_list	*get_connecting_rooms(int visiting, t_rooms *rooms, int end)
{
	t_list	*room_list;
	int		i;

	if (visiting == end)
		return (NULL);
	room_list = NULL;
	i = 0;
	while (i < rooms->num_of_rooms)
	{
		//On ce positionne sur la room courante et on verifie`
		//Et on passe en revu chaque room adjacente jusqu'à en 
		//trouver une accessible si elle existe on l'a marque comme
		//valide et on l'ajoute aux chemins possible.
		if (rooms->paths[visiting][i] && i != visiting &&
			(!rooms->paths[i][i] || i == end))
		{
			rooms->paths[i][i] = rooms->paths[i][i] | 1;
			ft_lstadd(&room_list, new_list(i));
		}
		i++;
	}
	return (room_list);
}

void	remove_visited(t_rooms *rooms, int start)
{
	int	i;

	i = 0;
	while (i < rooms->num_of_rooms)
	{
		if (i != start)
			rooms->paths[i][i] = rooms->paths[i][i] & 2;
		i++;
	}
}

t_list	*get_path(t_rooms *rooms, int end, int *room_pointers)
{
	t_list	*path;
	t_list	*wrapper;
	int		c;
	size_t	length;

	path = NULL;
	c = end;
	length = 0;
	while (room_pointers[c] != c)
	{
		rooms->paths[c][c] = rooms->paths[c][c] | 2;
		ft_lstadd(&path, new_list(c));
		c = room_pointers[c];
		length++;
	}
	if (c != end)
		ft_lstadd(&path, new_list(c));
	length = c != end ? length + 1 : length;
	if (path == NULL)
		return (NULL);
	wrapper = (t_list *)malloc(sizeof(t_list));
	wrapper->content = path;
	wrapper->content_size = length - 1;
	wrapper->next = NULL;
	return (wrapper);
}

void	iap(t_queue **tv, int s, int *rp, t_rooms *r)
{
	*tv = new_t_queue();
	push(*tv, new_list(s));
	get_room_pointers(rp, r);
}
