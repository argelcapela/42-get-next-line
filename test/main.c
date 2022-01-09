#include "../src/get_next_line.h"
#include <stdio.h>

/*
 * COMPILE AND EXECUTE DIRECT OF THIS CURRENT DIRECTORY
   ALSO DELETE .GCH file

gcc -D BUFFER_SIZE=2 ../src/get_next_line.h ../src/get_next_line_utils.c ../src/get_next_line.c main.c && rm ../src/*.gch 
&& ./a.exe|out

 */


int main(void)
{
	// testing mandatory
	int lyric1 = open("files/enemy", O_RDONLY);
	printf("%s", get_next_line(lyric1));

	return(0);
}
