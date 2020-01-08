#include "sh21.h"

void	main_loop(t_general *sh)
{
	while (TRUE)
	{
		ft_putstr("$>");
		read_buffer(sh);
	}
}