#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (!*little)
		return ((char *)little);
	else if (!*big)
		return (0);
	else if (len <= 0)
		return (0);
	while (big[i] && i < len)
	{
		j = 0;
		while (big[i + j] == little[j])
		{
			j++;
			if (!little[j] && (i + j - 1) < len)
				return ((char *)(big + i));
		}
		i++;
	}
	return (0);
}
/*
#include <stdio.h>
#include <string.h>
int    main()
{
    char big[] = "abcdefcdzack";
    char small[] = "cdz";
    printf("%s\n", ft_strnstr(big, small, 99));
    return (0);
}*/