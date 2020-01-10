#include "sh21.h"

void	main_loop(t_general *sh)
{
//	while (TRUE)
	{
		ft_putstr("$>");
		sh->line_params.cursor_x += ft_strlen("$>");
		read_buffer(sh);
	}
}