/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acapela- < acapela-@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 03:01:30 by acapela-          #+#    #+#             */
/*   Updated: 2022/01/17 15:51:41 by acapela-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

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

char	*ft_strjoin(char *s1, char *s2)
{
	size_t		ls1;
	size_t		ls2;
	char		*newstr;

	ls1 = -1;
	ls2 = -1;
	newstr = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!newstr)
		return (NULL);
	while (s1[++ls1])
		newstr[ls1] = s1[ls1];
	while (s2[++ls2])
		newstr[ls1 + ls2] = s2[ls2];
	newstr[ls1 + ls2] = '\0';
	free(s1);
	s1 = NULL;
	return (newstr);
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
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
	*new = '\0';
	return (temp);
}
