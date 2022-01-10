#include "../src/get_next_line.h"
#include <stdio.h>

/*
 * COMPILE AND EXECUTE DIRECT OF THIS CURRENT DIRECTORY
   ALSO DELETE .GCH file

clear && gcc -Wall -Wextra -Werror -D BUFFER_SIZE=2 ../src/get_next_line.h ../src/get_next_line_utils.c ../src/get_next_line.c main.c && rm ../src/*.gch && ./a.out && valgrind --leak-check=full ./a.out


clear && gcc -D BUFFER_SIZE=2 ../src/get_next_line.h ../src/get_next_line_utils.c ../src/get_next_line.c main.c -g && rm ../src/*.gch && ./a.exe
 */

int main(void)
{
	// testing mandatory
	int lyric1 = open("files/41_with_nl", O_RDONLY);
	printf("%s", get_next_line(lyric1));
	//printf("%s", get_next_line(lyric1));
	//printf("%s", get_next_line(lyric1));
	//get_next_line(lyric1);

	return(0);
}
