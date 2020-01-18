#include "libft.h"

char	*ft_get_str_to_delim(const char *str, int x, char delim)
{
	char	*new_str;
	int		i;
	int		len;
	int		j;

	if (!str || x < 0)
		return (NULL);
	i = x - 1;
	len = 0;
	while (str[++i] != '\0' && str[i] != delim)
		++len;
	if (!(new_str = (char*)malloc(sizeof(char) * (len + 2))))
		return (NULL);
	new_str[len + 1] = '\0';
	i = x - 1;
	j = 0;
	while (str[++i] != '\0' && str[i] != delim)
		new_str[j++] = str[i];
	new_str[j] = str[i];
	return (new_str);
}