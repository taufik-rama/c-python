package main

// #cgo CFLAGS: -I /usr/include/python3.5m
// #cgo LDFLAGS: -L${SRCDIR} -lpython -L${SRCDIR}/python-build/ -lpython3.7m -lpthread -lm -lutil -ldl
// int run();
import "C"
import "fmt"

func main() {
	fmt.Println("| Golang |", int(C.run()))
}
