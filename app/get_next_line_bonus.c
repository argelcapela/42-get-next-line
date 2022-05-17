/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acapela- < acapela-@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 03:05:41 by acapela-          #+#    #+#             */
/*   Updated: 2022/01/19 18:15:34 by acapela-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"get_next_line_bonus.h"

static int	index_first_bn(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\n')
		i++;
	return (i);
}

static char	*clean_leak(char **ptr)
{
	free (*ptr);
	*ptr = NULL;
	return (*ptr);
}

static char	*get_line_hold_rest(int fd, char **rest,
int result, char *buffer){
	char	*line;
	char	*tmp_rest;

	buffer[result] = '\0';
	*rest = ft_strjoin(*rest, buffer);
	if (ft_strrchr(*rest, '\n'))
	{
		line = ft_substr(*rest, 0, index_first_bn(*rest) + 1);
		tmp_rest = ft_strdup(&(rest[0][index_first_bn(*rest) + 1]));
		clean_leak(rest);
		*rest = tmp_rest;
		return (line);
	}
	else if (result == 0 && ft_strlen(*rest) > 0)
	{
		line = ft_strdup(*rest);
		clean_leak(rest);
		return (line);
	}
	else if (result == 0 && ft_strlen(*rest) <= 0)
		return (clean_leak(rest));
	return (get_line_hold_rest(fd, rest, read(fd, buffer,
				BUFFER_SIZE), &buffer[0]));
}

char	*get_next_line(int fd)
{
	static char	*rest[FD_LIMIT];
	char		*buffer;
	int			result;
	char		*line;

	buffer = malloc(BUFFER_SIZE + 1);
	if (read(fd, buffer, 0) < 0 || BUFFER_SIZE < 1)
	{
		free (buffer);
		return (NULL);
	}
	if (rest[fd] == 0)
		rest[fd] = ft_strdup("");
	result = read(fd, buffer, BUFFER_SIZE);
	if (rest[fd] != NULL)
		line = get_line_hold_rest(fd, &rest[fd], result, &buffer[0]);
	else
	{
		free(buffer);
		return (NULL);
	}
	free (buffer);
	return (line);
}
