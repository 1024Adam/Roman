all:
	gcc -ansi -Wall -pedantic -Iinclude src/roman.c src/romanTools.c -o bin/romanRunMe
