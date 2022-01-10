#include "get_next_line.h"
#include <string.h>


char	*get_next_line(int fd)
{	
// auxiliary vars
	static char *rest;
	char *buffer;
	ssize_t result;
// check fd
	if(!read(fd, buffer, BUFFER_SIZE))
		return (NULL);
// return until \n & hold rest
	return (get_line_hold_rest(fd));
}

char	*get_line_cut_rest(int fd)
{
	
}


