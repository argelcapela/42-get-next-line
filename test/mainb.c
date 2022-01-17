#include "../src/get_next_line_bonus.h"
#include <stdio.h>

int main(void)
{
	// fd #1
	int fd = open("files/legend", O_RDONLY);
	char *resposta = get_next_line(fd);

	printf("%s", resposta);
	while(resposta)
	{
		printf("%s", resposta);
		free(resposta);
		resposta = get_next_line(fd);
	}
	// fd #2
	fd = open("files/enemy", O_RDONLY);
	resposta = get_next_line(fd);

	printf("%s", resposta);
	while(resposta)
	{
		printf("%s", resposta);
		free(resposta);
		resposta = get_next_line(fd);
	}

	return(0);
}
