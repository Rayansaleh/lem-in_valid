#include "../includes/lem_in.h"

void	delete_list(t_list *list)
{
	if (!list)
		return ;
	delete_list(list->next);
	free(list);
}
