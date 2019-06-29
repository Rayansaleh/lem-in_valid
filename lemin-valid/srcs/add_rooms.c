#include "../includes/lem_in.h"

static int	will_continue(char **line)
{
	gnl(line);
	if (!ft_strlen(*line))
	{
		free(*line);
		return (0);
	}
	return (1);
}

static void	add_links(t_rooms **rooms, char *fl, int *start, int *end)
{
	char	*line;

	//Verification que start et end ai deja ete defini
	send_error(*start == -1 || *end == -1);
	add_rooms_to_array(rooms, start, end);
	add_link_to_list(rooms, fl);
	while (will_continue(&line))
		add_link_to_list(rooms, line);
}

static void	set_start_and_end(int *start, int *end, int ta, int *mode)
{
	if (*mode == 1)
		*start = ta;
	else if (*mode == 2)
		*end = ta;
	*mode = 0;
}

static int	add_new_room(t_rooms *rooms, char *line)
{
	char	**split;

	split = ft_strsplit(line, ' ');
	send_error(split == NULL || split[0] == NULL || split[0][0] == 'L');
	send_error(!split[1] || !split[2] || split[3]);
	free(line);
	ft_lstadd(&(rooms->room_name_list), ft_lstnew(split[0],
				ft_strlen(split[0]) + 1));
	free_split(split);
	rooms->num_of_rooms++;
	return (rooms->num_of_rooms - 1);
}

void		add_rooms(t_rooms **rooms, int *start, int *end)
{
	char	*line;
	int		mode;

	*rooms = new_rooms();
	mode = 0;
	while (1)
	{
		//Lecture des rooms et links
		gnl(&line);
		//Si on detecte un - alors c'est un link
		if (ft_strchr(line, '-') != NULL)
		{
			//On l'ajoute alors en tant que tel
			add_links(rooms, line, start, end);
			break ;
		}
		//Si on detecte un start on le signale en retournant
		//une valeure specifique
		if (ft_strequ("##start", line))
			mode = free_with_return(line, 1);
		//Si on detecte un end on fait de meme
		else if (ft_strequ("##end", line))
			mode = free_with_return(line, 2);
		//Sinon on considere que la ligne designe une room et on lajoute
		else
			set_start_and_end(start, end, add_new_room(*rooms, line), &mode);
	}
}
