#include "sh21.h"

char *read_buffer(t_general *sh)
{
	long	c;
	t_params_line *tpl;
	int		x;

	tpl = &sh->line_params;
	tpl->str = ft_strnew(0);
	tpl->str_len = 0;
	c = 0;
	while (read(STDIN_FILENO, &c, sizeof(long)) > 0)
	{
		if (c > 31 && c < 127)
		{
			if (c == '\'' || c == '"')
				tpl->input_mode = quotes(tpl, (char)c) ? QUOTES_MODE : STANDART_MODE;
			++tpl->str_len;
			tpl->str = ft_insert_symbol(tpl->str, sh->line_params.cursor_x,
												   tpl->cursor_y, (char)c);
			write(STDOUT_FILENO, &c, 1);
			++tpl->cursor_x;
			ft_print_buffer(tpl, FALSE);
		}
		else if (c == '\n')
		{
			write(STDOUT_FILENO, &c, 1);
			++tpl->str_len;
			if (tpl->input_mode == STANDART_MODE)
				return (tpl->str = ft_strplussymb(tpl->str, (char)c));
			else
			{
				x = get_index(tpl->str, tpl->cursor_y, tpl->cursor_x);
				if (x != -1)
				{
					tpl->str = ft_insert_symbol(tpl->str, get_len_line(tpl->str, tpl->cursor_y), tpl->cursor_y, '\n');
					ft_printf("{set:fd}[%s]\n", g_fd, tpl->str);
					ft_printf("quotes>");
					++tpl->cursor_y;
					tpl->cursor_x = 0;
				}
			}
			ft_print_buffer(tpl, FALSE);
		}
		else
			keys(c, tpl);
		c = 0;
	}
	return (NULL);
}
