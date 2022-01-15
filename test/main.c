#include "../src/get_next_line.h"
#include <stdio.h>

int main(void)
{
	// test #1
	int fd = open("habibi.txt", O_RDONLY);
	char *resposta = get_next_line(fd);

	while(resposta)
	{
		printf("%s", resposta);
		free(resposta);
		resposta = get_next_line(fd);
	}

	return(0);
}
