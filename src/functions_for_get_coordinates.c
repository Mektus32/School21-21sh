#include "sh21.h"

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
