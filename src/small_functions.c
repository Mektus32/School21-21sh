#include "sh21.h"

int		print_ch(int ch)
{
	write(STDOUT_FILENO, &ch, 1);
	return '\n';
}

void	ft_exit(int status)
{
	exit(status);
}

void print_command(char *str, long ch)
{
	if (str)
		write(STDOUT_FILENO, str, 1);
	else
		write(STDOUT_FILENO, &ch, sizeof(long));
}