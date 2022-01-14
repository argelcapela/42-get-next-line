#include "../src/get_next_line.h"
#include <stdio.h>

/*
 * COMPILE AND EXECUTE DIRECT OF THIS CURRENT DIRECTORY
   ALSO DELETE .GCH file

clear && gcc -Wall -Wextra -Werror -D BUFFER_SIZE=2 ../src/get_next_line.h ../src/get_next_line_utils.c ../src/get_next_line.c main.c && ./a.out

&& valgrind --leak-check=full ./a.out


clear && gcc -D BUFFER_SIZE=2 ../src/get_next_line.h ../src/get_next_line_utils.c ../src/get_next_line.c main.c -g && rm ../src/ *.gch && ./a.exe
 */

int main(void)
{
	// testing mandatory
	int lyric1 = open("files/41_with_nl", O_RDONLY);


	int i = 0;
	while(i < 1)
	{
		char *resposta = get_next_line(lyric1);
		printf("%s", resposta);
		free(resposta);
		i++;
	}

	return(0);
}
