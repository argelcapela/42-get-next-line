#include "../src/get_next_line.h"
#include <stdio.h>

int main(void)
{
	// testing mandatory
	int lyric1 = open("files/enemy", O_RDONLY);
	printf("%s", get_next_line(lyric1));

	return(0);
}
