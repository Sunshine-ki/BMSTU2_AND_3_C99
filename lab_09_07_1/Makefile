CFLAGS := -std=c99 -Wall -Werror -pedantic -lm -g
FILE_NAME_O = cdio.o matrix_reduction.o matrix_increase.o func_multiplication.o
FILE_NAME_TEST_O = test.o cdio_tests.o func_multiplication_tests.o matrix_reduction_tests.o matrix_increase_tests.o
# .PHONY: all clean run

all: app.exe test.exe 

#  Сборка main
app.exe: main.o $(FILE_NAME_O) 
	gcc -o app.exe $^ $(CFLAGS)

# Сборка test
test.exe: $(FILE_NAME_TEST_O) $(FILE_NAME_O)
	gcc -o test.exe $^ $(CFLAGS)

%.o: %.c
	gcc -c $^ $(CFLAGS)	

clean:
	rm -f *.o *.exe

run:
	./app.exe < test_func/in_7.txt 