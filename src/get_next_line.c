#include "get_next_line.h"

int index_last_bn(char *str)
{
	int i;

	i = ft_strlen(str);
	while(str[i] != '\n')
		i--;
	return(i);
}

char	*get_line_hold_rest(int fd, char **rest, ssize_t result, char *buffer){
// auxiliary vars
	char *line;
	int len;
// recursion line until \n
	buffer[BUFFER_SIZE] = '\0';
	*rest = ft_strjoin(*rest, buffer);
	if(ft_strrchr(*rest, '\n', &(*rest))) // 1) verificar se tem \n no *rest
	{
		// 2) retorna a linha do começo, ignorando caracteres não printavéis, até o barra\n
			len = index_last_bn(*rest);
			line = ft_substr(*rest, 0, len + 1);
		// 3) pega o *rest e atribuí a ele um ponteiro, apontando para o primeiro caracter depois do \n
			*rest = ft_strdup(&(rest[0][len + 1]));
		return (line);
	}
	else if(result == 0)
	{
		return (NULL);
	}
	else
	{
		result = read(fd, buffer, BUFFER_SIZE);
		get_line_hold_rest(fd, rest, result, &buffer[0]);
	}
}

char	*get_next_line(int fd)
{
// auxiliary vars
	static char *rest;
	char buffer[BUFFER_SIZE + 1];
	ssize_t result;
// check fd
	//if(read(fd, buffer, 0) < 0)
		//return (NULL);
// init vars
	if(rest == 0)
		rest = ft_strdup("");
	result = read(fd, buffer, BUFFER_SIZE);
// return line until \n & hold rest
	return (get_line_hold_rest(fd, &rest, result, &buffer[0]));
}
