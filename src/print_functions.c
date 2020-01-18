#include "sh21.h"

void	ft_print_buffer(t_params_line *cursor)
{
	int		x;
	char	*output;
	int		len;

	output = NULL;
	len = 0;
	ft_printf("{set:fd}[print_buffer] cursor_x = %d, str_len = %d\n", g_fd, cursor->cursor_x, cursor->str_len);
	if (cursor->cursor_x != cursor->str_len)
	{
		x = get_index(cursor->str, cursor->cursor_y, cursor->cursor_x);
		ft_printf("{set:fd}[print_buffer] x = %d\n", g_fd, x);
		if (x != -1)
		{
			output = ft_get_str_to_delim(cursor->str, x, '\n');
			if (output)
			{
				len = ft_strlen(output);
				ft_printf("%s", output);
				while (len-- > 0)
					print_command(tgetstr("le", NULL), 0);
			}
		}
		ft_strdel(&output);
	}
}