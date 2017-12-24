build: main

main: main.o
	gcc main.o -o main

main.o: main.c
	gcc -g -c -o main.o main.c

run: main
	./main

clean:
	rm -f *.o main

