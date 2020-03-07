CFLAGS := -std=c99
FILE_O :=  functions/sentence.c functions/unique_words.c functions/binary_matrix.c functions/find_max.c
HEADERS_DIR := headers/

build: main.o $(FILE_O)
	gcc -o app.exe $^  $(CFLAGS)

%.o: %.c
	gcc -c -I $(HEADERS_DIR) $^ $(CFLAGS)

clean:
	rm -f *.o *.exe *.out

run:
	./app.exe files/in.txt