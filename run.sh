rm -f libpython.a python
cd c-python/
make clean
make
cp libpython.a ..
cd ..
go build