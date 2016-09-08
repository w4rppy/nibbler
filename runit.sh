clean
g++ -c -fPIC Koala.cpp
g++ -o libkoala.so -shared Koala.o
g++ *.cpp -ldl -g3 libkoala.so
setenv LD_LIBRARY_PATH ~/
./a.out
