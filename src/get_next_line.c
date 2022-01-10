#include "get_next_line.h"

int	count_before_br_bz(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\n' && str[i] != '\0')
		i++;
	return (i);
}

char	*get_line_hold_rest(int fd, char **rest, ssize_t result, char *buffer){
	char *line;
	int len;
// concatenate the buffers & check if has \n
	while(result > 0)
	{
		buffer[BUFFER_SIZE] = '\0';
		*rest = ft_strjoin(*rest, buffer);
		if(ft_strrchr(*rest, '\n'))
			break;
		result = read(fd, buffer, BUFFER_SIZE);
	}

	len = count_before_br_bz(*rest);
	line = ft_substr(*rest,0, len + 1);
	*rest = ft_strdup(&rest[0][len + 1]);
	return(line);
}

char	*get_next_line(int fd)
{
// auxiliary vars
	static char *rest;
	char buffer[BUFFER_SIZE + 1];
	ssize_t result;
	char *line;
// check fd
	if(read(fd, buffer, 0) < 0)
		return (NULL);
// init vars
	if(rest == 0)
		rest = ft_strdup("");
	result = read(fd, buffer, BUFFER_SIZE);
	buffer[BUFFER_SIZE] = '\0';
// return line until \n & hold rest
	line = get_line_hold_rest(fd, &rest, result, &(buffer[0]));
	//printf("*%s*", rest);
	return(line);
}

