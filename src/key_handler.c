#include "sh21.h"

void keys(long ch, t_params_line *cursor)
{
	if (ch == LEFT_ARROW)
	{
		ft_left_arrow(cursor);
	}
	else if (ch == RIGHT_ARROW)
	{
		ft_right_arrow(cursor);
	}
	else if (ch == DEL)
	{
		ft_del_arrow(cursor);
	}
}
