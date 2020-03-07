# CFLAGS := -std=c99 -Wall -Werror -pedantic -std=c99 -lm -g
CFLAGS := -std=c99
FILE_O := $(subst .c,.o,$(wildcard functions/*.c))
FILE_TESTS_O := test.o $(subst .c,.o,$(wildcard unit_tests/*.c))
HEADERS_DIR := headers/

test.exe: $(FILE_TESTS_O) $(FILE_O)
	gcc -o test.exe $^  $(CFLAGS) 

app.exe:  main.o $(FILE_O)
	gcc -o app.exe $^  $(CFLAGS)

%.o: %.c
	gcc -c -I $(HEADERS_DIR) $^ $(CFLAGS)

functions/%.o: functions/%.c
	gcc -o $@ -c -I $(HEADERS_DIR) $^ $(CFLAGS)

unit_tests/%.o: unit_tests/%.c
	gcc -o $@ -c -I $(HEADERS_DIR) $^ $(CFLAGS)

clean:
	rm -f *.o *.exe unit_tests/*.o functions/*.o

run:
	./app.exe

# print:
# 	echo $(wildcard functions/*.c)