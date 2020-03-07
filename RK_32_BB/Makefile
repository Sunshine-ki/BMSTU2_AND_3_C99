
build: main.o list.o
	gcc -o app.exe  main.o list.o
	
main.o: main.c 
	gcc -c main.c

list.o: list.c
	gcc -c list.c

clean:
	rm -f *.o *.exe functions/*.o

run:
	./app.exe in.txt
