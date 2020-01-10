#include "sh21.h"

void	usage()
{
	ft_printf("usage: ./21sh\n");
	exit(0);
}

void	print_error(char *error)
{
	ft_printf("%s\n", error);
	exit(0);
}