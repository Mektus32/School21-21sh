#include "sh21.h"

char *read_buffer(t_general *sh)
{
	long	c;
	char	*buffer;
	char	*tmp;
	int		x = 0;
	int		y = 0;

	buffer = ft_strnew(0);
	c = 0;
	while (read(STDIN_FILENO, &c, sizeof(long)) > 0)
	{
		if (c > 31 && c < 127)
		{
			while (x != ft_strlen(buffer))
			{
				tmp = tgetstr("le", NULL);
				write(1, tmp, ft_strlen(tmp));
				x++;
			}
			buffer = ft_strplussymb(buffer, (char)c);
			write(1, buffer, ft_strlen(buffer));
			x = 0;
		}
		else if (c == '\n')
		{
			buffer = ft_strplussymb(buffer, (char)c);
			//break;
		}
		else
			keys(c, sh->line_params);
		c = 0;
	}
	change_terminal_mode("std", &sh->mode);
}
