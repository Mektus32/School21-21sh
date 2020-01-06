#include "sh21.h"

void quotes(int *count_double_quotes, int *count_quotes, char ch)
{
	if (ch == '\"')
	{
		if (*count_quotes)
			return ;
		else if (*count_double_quotes)
			--(*count_double_quotes);
		else
			++(*count_double_quotes);
	}
	else
	{
		if (*count_double_quotes)
			return ;
		else if (*count_quotes)
			--(*count_quotes);
		else
			++(*count_quotes);
	}
}

int		print_ch(int ch)
{
	write(1, &ch, 1);
	return '\n';
}

char *read_buffer(t_general *sh)
{
	char	c;
	char	*buffer;
	int		count_quotes;
	int		count_double_quotes;

	buffer = ft_strnew(0);
	count_double_quotes = 0;
	count_quotes = 0;
	while (read(STDIN_FILENO, &c, 1) > 0 || count_double_quotes || count_quotes)
	{
		if (ft_isprint(c))
		{
			c == '\'' || c == '"' ? quotes(&count_double_quotes, &count_quotes, c) : 0;
			buffer = ft_strplussymb(buffer, c);//write an input function to any place in the string
			write(1, "check1\n", 7);
			tputs("kek", 1, putchar);
			write(1, "check2\n", 7);

		}
		else
			ft_strplussymb(buffer, c);
	}

}
