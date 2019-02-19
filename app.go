package main

// #cgo CFLAGS: -I /usr/include/python3.5m
// #cgo LDFLAGS: -L${SRCDIR} -lpython -lpython3.5m
// int run();
import "C"
import "fmt"

func main() {
	fmt.Println("| Golang |", int(C.run()))
}
