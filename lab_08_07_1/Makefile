CFLAGS := -std=c99 -Wall -Werror -pedantic -lm
FILE_NAME_O = cdio_array.o computational.o change_array.o
FILE_NAME_TEST_o = test_cdio_array.o test_computational.o test_change_array.o

all: app.exe test.exe

app.exe: main.o $(FILE_NAME_O)
	gcc -o app.exe $^ $(CFLAGS)

test.exe: test.o $(FILE_NAME_TEST_o) $(FILE_NAME_O)
	gcc -o test.exe $^ $(CFLAGS)

main.o: main.c
	gcc -c $< $(CFLAGS)

cdio_array.o: cdio_array.c 
	gcc -c $< $(CFLAGS)

computational.o: computational.c
	gcc -c $< $(CFLAGS)

change_array.o: change_array.c 
	gcc -c $< $(CFLAGS)

test.o: test.c 
	gcc -c $< $(CFLAGS)

test_cdio_array.o: test/test_cdio_array.c 
	gcc -c $< $(CFLAGS)

test_computational.o: test/test_computational.c 
	gcc -c $< $(CFLAGS)

test_change_array.o: test/test_change_array.c 
	gcc -c $< $(CFLAGS)

clean:
	rm *.o *.exe

run:
	./app.exe