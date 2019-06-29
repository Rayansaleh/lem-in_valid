#include "../includes/lem_in.h"

static void	convert_content_size(t_list *paths, int ants)
{
	t_list	*i;
	t_list	*c;

	while (ants > 0)
	{
		i = paths;
		while (i)
		{
			ants--;
			c = (t_list *)i->content;
			c->content_size++;
			if (i->next && i->next->content_size >=
				i->content_size + c->content_size)
				break ;
			i = i->next;
		}
	}
}

void		find_path_capacity(t_list *paths, int ants)
{
	t_list	*i;

	convert_content_size(paths, ants);
	i = paths;
	while (i)
	{
		i->content_size = ((t_list *)i->content)->content_size;
		i = i->next;
	}
}
