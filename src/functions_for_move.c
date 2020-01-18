#include "sh21.h"

void	ft_left_arrow(t_params_line *cursor)
{
	int		x;
	int		y;

	x = cursor->cursor_x;
	y = cursor->cursor_y;
	if (cursor->input_mode == STANDART_MODE)
	{
		ft_printf("{set:fd}[ft_left_arrow] x = %d, y = %d\n", g_fd, x, y);
		if (y == 0 && x == 0)
			print_command("\a", 0);
		else if (y == 0 && x > 0)
		{
			print_command(tgetstr("le", NULL), LEFT_ARROW);
			--x;
		}
		else if (y != 0 && x > 0)
		{
			print_command(tgetstr("le", NULL), LEFT_ARROW);
			--x;
		}
		else if (y != 0 && x == 0)
		{
			print_command(tgetstr("le", NULL), LEFT_ARROW);
			x = get_len_line(cursor->str, --y);
			if (x == -1)
			{
				ft_printf("{set:fd} error coordinates then move left\n");
				ft_exit(0);
			}
		}
	}
	else
	{
		if (x == 0)
			print_command("\a", 0);
		else
		{
			print_command(tgetstr("le", NULL), LEFT_ARROW);
			--x;
		}
	}
	cursor->cursor_x = x;
	cursor->cursor_y = y;
}

void	ft_right_arrow(t_params_line *cursor)
{
	int		x;
	int 	y;
	int		len;

	x = cursor->cursor_x;
	y = cursor->cursor_y;
	len = get_len_line(cursor->str, y);
	if (cursor->input_mode == STANDART_MODE)
	{
		if (x >= len)
		{
			if (get_len_line(cursor->str, y + 1) == -1)
				print_command("\a", 0);
			else
			{
				x = 0;
				++y;
			}
		}
		else
		{
			print_command(NULL, RIGHT_ARROW);
			++x;
		}
	}
	else
	{
		if (x >= len)
			print_command("\a", 0);
		else
		{
			print_command(NULL, RIGHT_ARROW);
			++x;
		}
	}
	cursor->cursor_x = x;
	cursor->cursor_y = y;
}

void	ft_del_arrow(t_params_line *cursor)
{
	char *tmp;

	if ((cursor->input_mode == QUOTES_MODE && cursor->cursor_x == 0)
	|| (cursor->input_mode == STANDART_MODE && cursor->cursor_x == 0 && cursor->cursor_y == 0))
	{
		print_command("\a", 0);
		return ;
	}
	tmp = ft_del_symbol(cursor->str, cursor->cursor_x - 1, cursor->cursor_y);
	if (!tmp)
		return ;
	cursor->str = tmp;
	ft_printf("{set:fd}[del_arrow][%s]\n", g_fd, cursor->str);
	--cursor->cursor_x;
	--cursor->str_len;
	print_command("\b", 0);
	cursor->str = ft_strplussymb(cursor->str, ' ');
	ft_printf("{set:fd}[del_arrow][%s]\n", g_fd, cursor->str);
	ft_print_buffer(cursor, TRUE);
	tmp = ft_strsub(cursor->str, 0, ft_strlen(cursor->str) - 1);
	ft_strdel(&cursor->str);
	cursor->str = tmp;
	ft_printf("{set:fd}[del_arrow][%s]\n", g_fd, cursor->str);
	//ft_strdel(&tmp);
}