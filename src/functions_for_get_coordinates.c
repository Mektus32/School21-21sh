#include "sh21.h"

int		get_index(char *str, int y, int x)
{
	int		index;
	int		check_y;
	int		len;

	if (!str || y < 0 || x < 0)
		return (-1);
	check_y = -1;
	index = 0;
	while (++check_y < y && (len = get_len_line(str, check_y)) != -1)
		index += len;
	if (check_y != y || (len = get_len_line(str, check_y)) == -1 || len < x)
		return (-1);
	return (index + x);
}

int		get_len_line(char *str, int y)
{
	int		i;
	int		count;
	int		len;

	if (!str)
		return (-1);
	i = -1;
	count = 0;
	len = 0;
	while (str[++i] != '\0')
	{
		if (count == y)
		{
			while (str[i] != '\0' && str[i] != '\n')
			{
				++len;
				++i;
			}
			return (len);
		}
		if (str[i] == '\n')
			++count;
	}
	return (-1);
}

void	get_x_y_after_print(char *str, int *x, int *y)
{
	int		i;
	int		value;

	i = 0;
	value = -1;
	while ((value = get_len_line(str, i)) != -1)
	{
		*x = value;
		*y = i;
		++i;
	}
}
