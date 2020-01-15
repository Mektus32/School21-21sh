#include "libft.h"

static int		get_len_line(char *str, int y)
{
	int		i;
	int		count;
	int		len;

	if (!str)
		return (-1);
	if (!ft_strlen(str))
		return (0);
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
		{
			++count;
			if (str[i + 1] == '\0')
				return (0);
		}
	}
	return (-1);
}

static int		get_index(char *str, int x, int y)
{
	int		i;
	int		index;

	i = -1;
	index = 0;
	while (++i < y)
		index += get_len_line(str, i) + 1;
	index += x;
	return (index);
}

char	*ft_insert_symbol(char *str, int x, int y, char ch)
{
	int		len_line;
	char	*new;
	int		index;
	int		i;
	int		j;

	if (!str || x < 0 || y < 0)
		return (NULL);
	if ((len_line = get_len_line(str, y)) == -1 || len_line < x)
		return (NULL);
	if (!(new = (char*)malloc(sizeof(char) * (ft_strlen(str) + 2))))
		return (NULL);
	index = get_index(str, x, y);
	new[index] = ch;
	i = 0;
	j = 0;
	while (str[i] != '\0')
	{
		if (j == index)
			++j;
		new[j] = str[i];
		++i;
		++j;
	}
	free(str);
	return (new);
}

