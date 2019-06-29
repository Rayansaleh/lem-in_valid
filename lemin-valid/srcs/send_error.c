#include "../includes/lem_in.h"

void	send_error(int b)
{
	if (b)
	{
		write(2, "ERROR\n", 6);
		exit(0);
	}
}
