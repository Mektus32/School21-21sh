#include "sh21.h"

char *read_buffer(t_general *sh)
{
	long	c;
	char	*buffer;
	char	*tmp;
	int		x = 0;
	int		y = 0;

	sh->line_params.str = ft_strnew(0);
	c = 0;
	while (read(STDIN_FILENO, &c, sizeof(long)) > 0)
	{
		ft_printf("{set:fd}[read_buffer] x = %d, y = %d\n", g_fd, sh->line_params.imagin_cursor_x, sh->line_params.cursor_y);
		if (c > 31 && c < 127)
		{
			++sh->line_params.imagin_cursor_x;
			sh->line_params.str = ft_insert_symbol(sh->line_params.str, sh->line_params.real_cursor_x, sh->line_params.cursor_y, (char)c);
		}
		else if (c == '\n')
		{
			sh->line_params.str = ft_strplussymb(sh->line_params.str, (char)c);
			//break;
		}
		else
			keys(c, &sh->line_params);
		ft_print_buffer(&sh->line_params);
		c = 0;
	}
	change_terminal_mode("std", &sh->mode);
}
