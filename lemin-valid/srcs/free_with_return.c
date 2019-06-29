#include "../includes/lem_in.h"

int	free_with_return(char *str, int r)
{
	free(str);
	return (r);
}
