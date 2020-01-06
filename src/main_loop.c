#include "sh21.h"

void	main_loop(t_general *sh)
{
	while (TRUE)
	{
		sh->terminal_buffer = read_buffer(sh);
	}
}