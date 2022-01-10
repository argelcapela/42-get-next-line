#include "get_next_line.h"

char	*get_next_line(int fd)
{	
// auxiliary vars
	static char *rest;
	char *buffer;
	ssize_t result;
// init vars
	if(rest == 0)
		rest = ft_strdup("");
	result = read(fd, buffer, BUFFER_SIZE);
// check fd
	if(read(fd, buffer, BUFFER_SIZE) < 0)
		return (NULL);
// return line until \n & hold rest
	return (get_line_hold_rest(fd, &rest, &result, &buffer));
}

char	*get_line_hold_rest(int fd, char **rest, ssize_t *result, char **buffer)
{
	if(result == 0)
		return (NULL);	
	else
	{
		return (*rest);


	}	
}



/*

01234567890123456789012345678901234567890\n01234567890123456789012345678901234567890z\n

*/
