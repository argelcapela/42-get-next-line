#include "get_next_line.h"

char	*get_line_hold_rest(int fd, char **rest, ssize_t result, char *buffer){
// recursion line until \n
	if(ft_strrchr(*rest, '\n', &(*rest)))
	{
		return (NULL);
	}
	else
	{
		if(result > 0)
		{
			*rest = ft_strjoin(*rest, buffer);
			get_line_hold_rest(fd, rest, read(fd, buffer, BUFFER_SIZE) , buffer);
		}
		else
			return (NULL);
	}
	return (*rest);
}

char	*get_next_line(int fd)
{
// auxiliary vars
	static char *rest;
	char buffer[BUFFER_SIZE + 1];
	ssize_t result;
// check fd
	if(read(fd, buffer, 0) < 0)
		return (NULL);
// init vars
	if(rest == 0)
		rest = ft_strdup("");
	result = read(fd, buffer, BUFFER_SIZE);
	buffer[BUFFER_SIZE] = '\0';
// return line until \n & hold rest
	return (get_line_hold_rest(fd, &rest, result, &buffer[0]));
}


