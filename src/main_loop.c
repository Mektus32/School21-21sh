#include "sh21.h"

void	main_loop(t_general *sh)
{
	//while (TRUE)
	{
		ft_putstr("$>");
		sh->line_params.cursor_x = 0;
		sh->line_params.cursor_y = 0;
		read_buffer(sh);
		//parser(sh->line_params.str)
	}
}