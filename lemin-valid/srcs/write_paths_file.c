#include "../includes/lem_in.h"
#include <fcntl.h>

void	write_paths_file(t_list *paths, t_rooms *rooms)
{
	t_list	*i;
	t_list	*j;
	int		fd;

	fd = open("paths.txt", O_CREAT | O_WRONLY);
	if (fd == -1)
		return ;
	i = paths;
	while (i)
	{
		j = (t_list *)i->content;
		while (j)
		{
			ft_putendl_fd(rooms->room_names[gfp((int *)j->content)], fd);
			j = j->next;
		}
		if (i->next)
			ft_putstr_fd("~~~\n", fd);
		i = i->next;
	}
	close(fd);
}
