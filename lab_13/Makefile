
test.out: hostid.o hostid_test.o
	gcc hostid.o hostid_test.o -o test.out

hostid.o: hostid.c
	gcc -c hostid.c

hostid_test.o: hostid_test.c
	gcc -c hostid_test.c

# Динамика
libDynamic:
	gcc -c main.c
	gcc -c -fPIC hostid.c 
	gcc -shared -o libhostid.so hostid.o
	gcc -o app.out main.o -L. -lhostid  

# Статика
libStatic:
	gcc -c main.c hostid.c
	ar cr libhostid.a hostid.o
	gcc -Wall -Werror -o app.out main.o -L. -lhostid

# main.out: main.o hostid.o
# 	gcc main.o hostid.o -o main.out

# *.o: main.c hostid.c
# 	gcc -c main.c hostid.c
# -Wl,-rpath,.	

# echo $LD_LIBRARY_PATH
# LD_LIBRARY_PATH=$(pwd) 
# export LD_LIBRARY_PATH

clean:
	rm -f *.o *.out *.a *.so