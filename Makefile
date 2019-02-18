all:
	gcc main.cc -I /usr/include/python3.5m -L. -lpython3.5m -lpthread -lm -lutil -ldl