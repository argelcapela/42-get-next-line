#include "get_next_line.h"

char	*ft_strrchr(const char *str, int ch)
{
	int	j;

	j = 0;
	if (str == NULL)
		return (NULL);
	j = ft_strlen(str);
	while (j >= 0)
	{
		if (str[j] == (unsigned char)ch)
			return ((char *)(str + j));
		j--;
	}
	return (NULL);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t		i;
	size_t		f;
	char		*str;

	f = 0;
	i = 0;
	if (!s1 || !s2)
		return (NULL);
	str = malloc((ft_strlen(s1) + ft_strlen(s2)) + 1, sizeof(char));
	if (str == NULL)
		return (NULL);
	while (i < (ft_strlen(s1) + ft_strlen(s2)))
	{
		if (i < ft_strlen(s1))
			str[i] = s1[i];
		else
		{
			str[i] = s2[f];
			f++;
		}
		i++;
	}
	str[i] = '\0';
	free(s1);
	return (str);
}

size_t	ft_strlen(char const *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strdup(const char *s)
{
	int		i;
	char	*strd;

	i = 0;
	strd = (char *)malloc((ft_strlen(s) + 1) * sizeof(char));
	if (!strd)
		return (NULL);
	while (s[i])
	{
		strd[i] = s[i];
		i++;
	}
	strd[i] = '\0';
	return (strd);
}

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (!dest && !src && !size)
		return (0);
	if (size > 0)
	{
		while (i < size - 1 && src[i])
		{
			dest[i] = src[i];
			i++;
		}
		dest[i] = '\0';
	}
	return (ft_strlen(src));
}
