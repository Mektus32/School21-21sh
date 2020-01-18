#include "sh21.h"

char *read_buffer(t_general *sh)
{
	long	c;
	t_params_line *tpl;

	tpl = &sh->line_params;
	tpl->str = ft_strnew(0);
	tpl->str_len = 0;
	c = 0;
	while (read(STDIN_FILENO, &c, sizeof(long)) > 0)
	{
		if (c > 31 && c < 127)
		{
			++tpl->str_len;
			tpl->str = ft_insert_symbol(tpl->str, sh->line_params.cursor_x,
												   tpl->cursor_y, (char)c);
			write(STDOUT_FILENO, &c, 1);
			++tpl->cursor_x;
		}
		else if (c == '\n')
		{
			if (tpl->input_mode == STANDART_MODE)
				return (NULL);
		}
		else
			keys(c, tpl);
		ft_print_buffer(tpl);
		c = 0;
	}
	return (NULL);
}
