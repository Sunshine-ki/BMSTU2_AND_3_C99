CFLAGS := -std=c99 -Wall -Werror -pedantic -std=c99 -lm -g
# CFLAGS := -std=c99
FILE_O := snprintf.o test_snprintf.o 
HEADERS_DIR := headers/

all: app.exe test.exe

app.exe: main.o $(FILE_O)
	gcc -o app.exe $^ $(CFLAGS)

test.exe: test.o $(FILE_O)
	gcc -o test.exe $^ $(CFLAGS)

%.o: %.c
	gcc -c -I $(HEADERS_DIR) $^ $(CFLAGS)

clean:
	rm -f *.o *.exe functions/*.o

run:
	./app.exe
