#include "../includes/lem_in.h"

static void	print_ant(t_ant *ant, t_rooms *rooms)
{
	int		n;
	int		*room_pointer;
	char	*name;

	n = ant->n;
	room_pointer = (int *)ant->path->content;
	name = rooms->room_names[*room_pointer];
	ft_putchar('L');
	ft_putnbr(n);
	ft_putchar('-');
	ft_putstr(name);
	ft_putchar(' ');
}

static void	move_ants(t_list **ants, t_rooms *rooms, int *can_continue)
{
	t_list	*i;
	t_ant	*current;

	i = *ants;
	*can_continue = 0;
	while (i)
	{
		current = (t_ant *)i->content;
		if (current->path->next)
		{
			*can_continue = 1;
			current->path = current->path->next;
			print_ant(current, rooms);
		}
		i = i->next;
	}
}

static int	add_ants(t_list *paths, t_list **ant_list, int ants, int *ants_left)
{
	t_list	*i;
	t_ant	*ta;
	t_list	*tal;
	int		tr;

	if (*ants_left < 1)
		return (0);
	i = paths;
	tr = 0;
	while (i && i->content_size && *ants_left >= 1)
	{
		ta = (t_ant *)malloc(sizeof(t_ant));
		ta->path = (t_list *)i->content;
		ta->n = (ants - *ants_left) + 1;
		tal = (t_list *)malloc(sizeof(t_list));
		tal->content = ta;
		tal->content_size = sizeof(ta);
		ft_lstadd(ant_list, tal);
		(*ants_left)--;
		tr = 1;
		i->content_size--;
		i = i->next;
	}
	return (tr);
}

void		delete_paths(void *content, size_t content_size)
{
	t_list	*ts;

	ts = (t_list *)content;
	content_size = 0;
	ft_lstdel(&ts, &delete_generic);
}

void		print_ants(int ants, int start, int end, t_rooms *rooms)
{
	t_list	*paths;
	t_list	*ant_list;
	int		can_continue;
	int		ants_left;

	if (!ants)
		return ;
	//On recupère la liste des chemins possible et exploitable
	paths = get_paths(rooms, start, end);
	send_error(!paths);
	//Maintenant qu'on à recuperer les paths on les tries pour connaitre les plus
	//efficace
	sort_paths(&paths);
	//On regarde combien de fourmis le path peut contenir simultanement
	find_path_capacity(paths, ants);
	//Ecriture du chemin emprunté dans un fichier dédié
	write_paths_file(paths, rooms);
	ant_list = NULL;
	can_continue = 1;
	ants_left = ants;
	//Tant que l'on peut continuer on continue
	while (can_continue)
	{
		//On deplace les fourmis, en les affichants par la meme occasion
		move_ants(&ant_list, rooms, &can_continue);
		//Si il reste des fourmis et des operation à effectuer on retourne à la ligne
		if (ant_list && can_continue)
			ft_putchar('\n');
		//On ajoute de nouvelles fourmis si il en reste à faire passer.
		//Ce qui permet de savoir si on peut continuer ou si il n'y a plus d'operation 
		can_continue = add_ants(paths, &ant_list, ants, &ants_left)
					|| can_continue;
	}
	ft_lstdel(&paths, &delete_paths);
	ft_lstdel(&ant_list, &delete_generic);
}
