all:
	gcc -std=c99 -pedantic -Werror -Wall -Wextra -Wvla -c src/tinyprintf.c -o src/tinyprintf.o

clean:
	rm -rf src/tinyprintf.o
