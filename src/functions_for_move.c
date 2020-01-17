#include "sh21.h"

void	ft_left_arrow(t_params_line *cursor)
{
	int		x;
	int		y;

	x = cursor->imagin_cursor_x;
	y = cursor->cursor_y;
	if (cursor->input_mode == STANDART_MODE)
	{
		ft_printf("{set:fd}[ft_left_arrow] x = %d, y = %d\n", g_fd, x, y);
		if (y == 0 && x == 0)
			print_command("\a");
		else if (y == 0 && x > 0)
		{
			print_command(tgetstr("le", NULL));
			--x;
		}
		else if (y != 0 && x > 0)
		{
			print_command(tgetstr("le", NULL));
			--x;
		}
		else if (y != 0 && x == 0)
		{
			print_command(tgetstr("le", NULL));
			x = get_len_line(cursor->str, --y);
			if (x == -1)
			{
				ft_printf("{set:fd} error coordinates then move left\n");
				ft_exit(0);
			}
		}
	}
	cursor->imagin_cursor_x = x;
	cursor->cursor_y = y;
	cursor->real_cursor_x = cursor->imagin_cursor_x;
}

void	ft_right_arrow(t_params_line *cursor)
{
	int		x;
	int 	y;
	int		len;

	x = cursor->imagin_cursor_x;
	y = cursor->cursor_y;
	len = get_len_line(cursor->str, y);
	if (cursor->input_mode == STANDART_MODE)
	{
		if (x == len)
		{
			if (get_len_line(cursor->str, y + 1) == -1)
				print_command("\a");
			else
			{
				x = 0;
				++y;
			}
		}
		else
		{
			print_command(tgetstr("nb", NULL));
			++x;
		}
	}
	cursor->imagin_cursor_x = x;
	cursor->cursor_y = y;
	//cursor->real_cursor_x = cursor->imagin_cursor_x;
}