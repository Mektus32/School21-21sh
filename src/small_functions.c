#include "sh21.h"

int		print_ch(int ch)
{
	write(1, &ch, 1);
	return '\n';
}

void	ft_exit(int status)
{
	exit(status);
}

void print_command(char *str)
{
	if (str)
		write(1, str, 1);
}