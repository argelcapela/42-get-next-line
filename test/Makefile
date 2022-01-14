SRC=./
CFLAGS= -Wall -Wextra -Werror
BUFFER_SIZE=2

all:
	clear && gcc $(CFLAGS) -ggdb3 -D BUFFER_SIZE=$(BUFFER_SIZE) $(SRC)/get_next_line.h $(SRC)/get_next_line_utils.c $(SRC)/get_next_line.c main.c -g

win:
	clear && gcc $(CFLAGS) -ggdb3 -D BUFFER_SIZE=$(BUFFER_SIZE) $(SRC)/get_next_line.h $(SRC)/get_next_line_utils.c $(SRC)/get_next_line.c main.c -g && ./a.exe

wincat:
	clear && gcc $(CFLAGS) -ggdb3 -D BUFFER_SIZE=$(BUFFER_SIZE) $(SRC)/get_next_line.h $(SRC)/get_next_line_utils.c $(SRC)/get_next_line.c main.c -g && ./a.exe | cat -e

lin:
	clear && gcc $(CFLAGS) -ggdb3 -D BUFFER_SIZE=$(BUFFER_SIZE) $(SRC)/get_next_line.h $(SRC)/get_next_line_utils.c $(SRC)/get_next_line.c main.c -g && ./a.out

lincat:
	clear && gcc $(CFLAGS) -ggdb3 -D BUFFER_SIZE=$(BUFFER_SIZE) $(SRC)/get_next_line.h $(SRC)/get_next_line_utils.c $(SRC)/get_next_line.c main.c -g && ./a.out | cat -e

leak:
	clear && gcc $(CFLAGS) -ggdb3 -D BUFFER_SIZE=$(BUFFER_SIZE) $(SRC)/get_next_line.h $(SRC)/get_next_line_utils.c $(SRC)/get_next_line.c main.c -g && valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./a.out

clean:
	rm $(SRC)/*.gch && rm a.exe a.out *.gch

suicide:
	rm Makefile
	rmmain.c *.txt





