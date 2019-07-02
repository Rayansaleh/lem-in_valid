#include "../includes/lem_in.h"

static int	*get_rooms(int n)
{
	int	*tr;
	int	i;

	tr = (int *)malloc(sizeof(int) * n);
	i = 0;
	while (i < n)
	{
		tr[i] = 0;
		i++;
	}
	return (tr);
}

void		delete_generic(void *content, size_t content_size)
{
	free(content);
	content_size = 0;
}

t_rooms		*new_rooms(void)
{
	t_rooms	*tr;

	tr = (t_rooms *)malloc(sizeof(t_rooms));
	tr->paths = NULL;
	tr->num_of_rooms = 0;
	tr->room_names = NULL;
	tr->room_name_list = NULL;
	return (tr);
}

void		add_rooms_to_array(t_rooms **rooms, int *start, int *end)
{
	t_rooms	*r;
	t_list	*j;
	int		i;

	//Initialisation d'une variable tmp pour manipuler le contenu des adresse
	//Sans modification de l'addresse en elle meme.
	r = *rooms;
	//On malloc paths au nombre de room connu car le nombre de path depend
	//Du nombre de room
	r->paths = (int **)malloc(sizeof(int *) * r->num_of_rooms);
	//On malloc room_names au nombre de room connu car il y a autant
	//De nom que de room
	r->room_names = (char **)malloc(sizeof(int *) * (1 + r->num_of_rooms));
	i = 0;
	j = r->room_name_list;
	//On va modifier le contenue de paths et room_names pour chaque room
	while (i < r->num_of_rooms)	
	{	
		//On va parcourir toutes les paths et les initialiser à zero
		//on crée ainsi une matrice d'ajdacence
		r->paths[i] = get_rooms(r->num_of_rooms);
		//Pendant que l'on crée la matrice on en profite pour
		//Recuperer le nom des rooms
		r->room_names[i] = ft_strdup((char *)j->content);
		j = j->next;
		i++;
	}
	r->room_names[i] = NULL;
	ft_lstdel(&(r->room_name_list), &delete_generic);
	r->room_name_list = NULL;
	//Positionnement de start et end aux addresses correspondante
	*start = r->num_of_rooms - (1 + *start);
	*end = r->num_of_rooms - (1 + *end);
}

void		free_rooms(t_rooms *rooms)
{
	int	i;

	i = 0;
	while (i < rooms->num_of_rooms)
	{
		free(rooms->room_names[i]);
		free(rooms->paths[i]);
		i++;
	}
	free(rooms->room_names);
	free(rooms->paths);
	free(rooms);
}
