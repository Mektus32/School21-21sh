#include "sh21.h"

char *read_buffer(t_general *sh)
{
	long	c;

	sh->line_params.str = ft_strnew(0);
	sh->line_params.str_len = 0;
	c = 0;
	while (read(STDIN_FILENO, &c, sizeof(long)) > 0)
	{
		/*ft_printf("{set:fd}[read_buffer] x = %d, y = %d\n", g_fd, sh->line_params.imagin_cursor_x,
				  sh->line_params.cursor_y);*/
		if (c > 31 && c < 127)
		{
			ft_printf("{set:fd}%p\n", g_fd, sh->line_params.str);
			++sh->line_params.imagin_cursor_x;
			++sh->line_params.str_len;
			sh->line_params.str = ft_insert_symbol(sh->line_params.str, sh->line_params.real_cursor_x,
												   sh->line_params.cursor_y, (char) c);
			//ft_printf("{set:fd}output\n", g_fd);
		}
		else if (c == '\n')
		{
			if (sh->line_params.input_mode == STANDART_MODE)
				return (NULL);
			//sh->line_params.str = ft_strplussymb(sh->line_params.str, (char) c);
			//break;
		}
		else
			keys(c, &sh->line_params);
		ft_print_buffer(&sh->line_params);
		c = 0;
	}
	return (NULL);
}