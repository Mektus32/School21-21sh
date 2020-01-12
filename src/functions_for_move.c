#include "sh21.h"

void	ft_left_arrow(t_params_line *cursor)
{
	char	*tmp;
	int		len;

	tmp = NULL;
	if (cursor->input_mode == STANDART_MODE)
	{
		if (cursor->cursor_x > 0)
		{
			--cursor->cursor_x;
			tmp = tgetstr("le", NULL);
			write(1, tmp, ft_strlen(tmp));
		}
		else if (cursor->cursor_x == 0)
		{
			if (cursor->cursor_y == 0)
			{
				tmp = tgetstr("bl", NULL);
				write(1, tmp, ft_strlen(tmp));
			}
			else
			{
				--cursor->cursor_y;
				len = get_len_line(cursor->str, cursor->cursor_y);
				if (len < 0)
				{
					ft_printf("{set:fd}error change x coordinate str = %s, y = %d\n", 3, cursor->str, cursor->cursor_y);
					ft_exit(0);
				}
				tmp = tgetstr("le", NULL);
				write(1, tmp, ft_strlen(tmp));
			}
		}
	}
}