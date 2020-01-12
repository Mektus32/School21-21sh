#include "sh21.h"

void keys(long ch, t_params_line *cursor)
{
	if (ch == LEFT_ARROW)
	{
		ft_printf("{set:fd} left_arrow\n", g_fd);
		ft_left_arrow(cursor);
	}
}
