#include "sh21.h"

void	main_loop(t_general *sh)
{
	//while (TRUE)
	{
		ft_putstr("$>");
		sh->line_params.prompt_len = ft_strlen("$>");
		sh->line_params.imagin_cursor_x = 0;
		sh->line_params.cursor_y = 0;
		sh->line_params.real_cursor_x = 0;
		read_buffer(sh);
		//parser(sh->line_params.str)
	}
}