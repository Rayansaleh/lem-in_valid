#include "../includes/lem_in.h"

void	gnl(char **line)
{
	char	*l;

	while (1)
	{
		get_next_line(0, &l);
		//Verfication que le 1er octet n'est pas un # et que la ligne 
		//ne contient ni start ni de end
		if (l[0] != '#' || ft_strequ("##start", l) || ft_strequ("##end", l))
		{
			*line = l;
			ft_putstr(l);
			ft_putchar('\n');
			break ;
		}
		free(l);
	}
}
