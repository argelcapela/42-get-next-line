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
<<<<<<< HEAD
	int lyric1 = open("files/legends", O_RDONLY);


	printf("%s", get_next_line(lyric1));
	printf("%s", get_next_line(lyric1));
	printf("%s", get_next_line(lyric1));
	printf("%s", get_next_line(lyric1));
	//get_next_line(lyric1);
=======
	int lyric1 = open("files/enemy", O_RDONLY);

	/*int i = 0;
	while (i < 61)
	{
			printf("%s", get_next_line(lyric1));
			i++;
	}*/

	printf("%s",get_next_line(lyric1));
	printf("%s",get_next_line(lyric1));
	printf("%s",get_next_line(lyric1));
	printf("%s",get_next_line(lyric1));
	printf("%s",get_next_line(lyric1));
	printf("%s",get_next_line(lyric1));
	printf("%s",get_next_line(lyric1));
	printf("%s",get_next_line(lyric1));



>>>>>>> 51791a529318c0f054f6b631bff569d754c4db82

	/*int i = 0;
	while(i < 45)
	{
		printf("%s", get_next_line(lyric1));
		i++;
	}*/
	return(0);
}
