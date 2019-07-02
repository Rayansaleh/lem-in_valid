#include "../includes/lem_in.h"

static int	get_index(char *name, t_rooms *rooms)
{
	int		i;
	char	**names;

	i = 0;
	names = rooms->room_names;
	while (names[i])
	{
		if (ft_strequ(names[i], name))
			return (i);
		i++;
	}
	send_error(1);
	return (-1);
}

void		free_split(char **split)
{
	int	i;

	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

void		add_link_to_list(t_rooms **rooms, char *line)
{
	char	**split;
	int		first;
	int		second;

	//On retire le '-' pour conserver uniquement les room relatives au
	//link courant
	split = ft_strsplit(line, '-');
	free(line);
	send_error(!split[1] || split[2]);
	//On fait correspondre la premiere room du link
	//Avec l'index affilier à son nom
	first = get_index(split[0], *rooms);
	//On fait de meme pour la deuxieme room du link
	second = get_index(split[1], *rooms);
	//On set le path à 1 dans la matrice d'adjacence à l'index
	//des 2 rooms constituant le link
	(*rooms)->paths[first][second] = 1;
	(*rooms)->paths[second][first] = 1;
	free_split(split);
}
