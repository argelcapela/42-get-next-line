SRC=../src/
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
	@make clean 1>/dev/null || true

lincat:
	clear && gcc $(CFLAGS) -ggdb3 -D BUFFER_SIZE=$(BUFFER_SIZE) $(SRC)/get_next_line.h $(SRC)/get_next_line_utils.c $(SRC)/get_next_line.c main.c -g && ./a.out | cat -e
	@make clean 1>/dev/null || true

lcatb:
	clear && gcc $(CFLAGS) -ggdb3 -D BUFFER_SIZE=$(BUFFER_SIZE) $(SRC)/get_next_line_bonus.h $(SRC)/get_next_line_utils_bonus.c $(SRC)/get_next_line_bonus.c mainb.c -g && ./a.out | cat -e
	@make clean 1>/dev/null || true

leak:
	clear && gcc $(CFLAGS) -ggdb3 -D BUFFER_SIZE=$(BUFFER_SIZE) $(SRC)/get_next_line.h $(SRC)/get_next_line_utils.c $(SRC)/get_next_line.c main.c -g && valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./a.out

clean:
	@rm $(SRC)*.gch a.exe a.out*  *.gch 2>/dev/null || true

suicide:
	@rm -rfd gnlTester 2>/dev/null || true
	@rm main.c *.txt 2>/dev/null || true
	@rm Makefile 2>/dev/null || true

tester:
	@make -C testadores/tester 2>/dev/null || true





