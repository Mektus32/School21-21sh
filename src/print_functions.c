#include "sh21.h"

void	ft_print_buffer(t_params_line *cursor)
{
	int		x;
	int		y;

	x = cursor->real_cursor_x;
	y = cursor->cursor_y;
	if (cursor->input_mode == STANDART_MODE)
	{
		while (y > 0)
		{
			--y;
			print_command(tgetstr("up", NULL));
		}
		while (x > 0)
		{
			--x;
			print_command(tgetstr("le", NULL));
		}
		ft_printf("%s", cursor->str);
		get_x_y_after_print(cursor->str, &x, &y);
		ft_printf("{set:fd}[print_buffer] x = %d or x = %d\n", g_fd ,cursor->imagin_cursor_x, x);
		cursor->real_cursor_x = cursor->imagin_cursor_x;
		while (x > cursor->imagin_cursor_x)
		{
			--x;
			print_command(tgetstr("le", NULL));
		}
		while (y > cursor->cursor_y)
		{
			--y;
			print_command(tgetstr("up", NULL));
		}
	}
}