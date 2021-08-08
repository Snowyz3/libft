#include "libft.h"

static size_t	ft_getcount(const char *s, const char c)
{
	size_t	count;
	size_t	i;

	i = 0;
	count = 0;
	while (s[i])
	{
		while (s[i] == c && s[i])
			i++;
		if (s[i] != c && s[i])
		{
			count++;
			while (s[i] != c && s[i])
				i++;
		}
	}
	return (count);
}

static size_t	ft_setstr(char const *s, char c, size_t i, size_t j, char **str)
{
	size_t	len;

	len = 0;
	while (s[i] == c)
		i++;
	while (s[i + len] != c && s[i + len])
		len++;
	str[j] = malloc(sizeof(*s) * len + 1);
	ft_strlcpy(str[j], s + i, len + 1);
	i += len + 1;
	return (i);
}

char	**ft_split(char const *s, char c)
{
	char	**str;
	size_t	i;
	size_t	j;
	size_t	count;

	i = 0;
	j = 0;
	count = ft_getcount(s, c);
	str = malloc(sizeof(s) * (count + 1));
	if (!str)
		return (0);
	while (j < count)
	{
		i = ft_setstr(s, c, i, j, str);
		j++;
	}
	str[j] = '\0';
	return (str);
}

#include <stdio.h>
int main()
{
	char **tab = ft_split("  tripouille  42  ", ' ');
	size_t i = 0;
	while (i < ft_getcount("  tripouille  42  ", ' '))
	{
		printf("%s\n", tab[i]);
		i++;
	}
}