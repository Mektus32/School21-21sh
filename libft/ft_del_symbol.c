#include "libft.h"

static int	get_len_line(const char *str, int y)
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

static int	get_index(const char *str, int y, int x)
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

char	*ft_del_symbol(char * str, int x, int y)
{
	int		index;
	char	*new_str;
	int		i;
	int		j;

	if (!str || x < 0 || y < 0)
		return (NULL);
	if ((index = get_index(str, y, x)) == -1)
		return (NULL);
	if (!(new_str = (char*)malloc(sizeof(char) * (ft_strlen(str) - 1))))
		return (NULL);
	i = -1;
	j = 0;
	while (str[++i] != '\0')
	{
		if (i == index)
			++i;
		new_str[j++] = str[i];
	}
	free(str);
	return (new_str);
}