#include "sh21.h"

void change_terminal_mode(char *mode, t_terminal_mode *term)
{
	static struct termios newt;

	if (!ft_strcmp("raw", mode))
	{
		newt = term->oldt;
		newt.c_lflag &= ~(ICANON | ECHO);
		newt.c_cc[VTIME] = 0;
		newt.c_cc[VMIN] = 1;
		tcsetattr(STDIN_FILENO, TCSANOW, &newt);
		term->is_set = TRUE;
	}
	else if (!ft_strcmp("std", mode))
	{
		if (term->is_set)
		{
			tcsetattr(STDIN_FILENO, TCSANOW, &term->oldt);
			term->is_set = FALSE;
		}
	}
}
