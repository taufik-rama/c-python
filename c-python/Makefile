all:
	gcc -c lib.c -I /usr/include/python3.5m -lpython3.5m -lpthread -lm -lutil -ldl
	ar rcs libpython.a lib.o

clean:
	rm -f *.o *.a