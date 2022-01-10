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
	str = malloc(((ft_strlen(s1) + ft_strlen(s2)) + 1) * sizeof(char));
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

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*new;
	char	*temp;

	new = malloc(len + 1);
	temp = new;
	while (start > 0)
	{
		s++;
		start--;
	}
	while (len > 0 && *s)
	{
		*new++ = *s++;
		len--;
	}
	*new = 0;
	return (temp);
}
