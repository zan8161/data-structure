all: basic.h main.c build.h build.c search.h search.c structure.h quicksort.h quicksort.c
	gcc basic.h main.c build.h build.c search.h search.c structure.h quicksort.h quicksort.c -o main

clean:
	rm -f main