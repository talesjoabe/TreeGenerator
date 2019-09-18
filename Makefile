all:
	g++ -cpp -std=c++11 main.cpp -W -Wall -ansi -pedantic
	g++ -o -std=c++11 main main.o
