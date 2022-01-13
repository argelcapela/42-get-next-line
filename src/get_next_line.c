#include "get_next_line.h"

int index_last_bn(char *str)
{
	int i;

	i = 0;
	while(str[i] != '\n')
		i++;
	return(i);
}

static char	*get_line_hold_rest(int fd, char **rest, ssize_t result, char *buffer){
// recursion line until \n
	buffer[result] = '\0';
	*rest = ft_strjoin(*rest, buffer);
	if(ft_strrchr(*rest, '\n')) // 1) verificar se tem \n no *rest
	{
		// auxiliary vars
			//char *line;
			char *leak_line;
			char *rest2;
			int len;
		// 2) retorna a linha do começo, ignorando caracteres não printavéis, até o barra\n
			len = index_last_bn(*rest);
			leak_line = ft_substr(*rest, 0, len + 1);

		// 3) pega o *rest e atribuí a ele um ponteiro, apontando para o primeiro caracter depois do \n
			rest2 = ft_strdup(&(rest[0][len + 1]));
			free(*rest);
			*rest = NULL;
			*rest = rest2;
			return (leak_line);
	}
	else if(result == 0)
	{
		if(ft_strlen(*rest) > 0)
		{
			char *str;
			str = ft_strdup(*rest);
			free(*rest);
			*rest = NULL;
			return (str);
		}
		else
		{
			free(*rest);
			*rest = NULL;
			return (NULL);
		}
	}

	return (get_line_hold_rest(fd, rest, read(fd, buffer, BUFFER_SIZE), &buffer[0]));
}

char	*get_next_line(int fd)
{
// auxiliary vars
	static char *rest;
	char buffer[BUFFER_SIZE + 1];
	ssize_t result;
	char *line;
// check fd
	if(read(fd, buffer, 0) < 0 || BUFFER_SIZE < 1)
		return (NULL);
// init vars
	if(rest == 0)
		rest = ft_strdup("");
	result = read(fd, buffer, BUFFER_SIZE);
	// return line until \n & hold rest
	if(rest != NULL)
		line = get_line_hold_rest(fd, &rest, result, &buffer[0]);
	else
		return (NULL);
// fix leaks
	/*int i = 0;
	while(line[i] != '\0')
		i++;
	if (line[i] == '\0')
	{
		free(rest);
		rest = NULL;
	}*/
	return (line);
}
