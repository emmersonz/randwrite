randwrite: randwrite.o list.o
	g++ -o randwrite randwrite.o list.o
randwrite.o: randwrite.cc list.h
	g++ -c randwrite.cc
list.o: list.h list.cc
	g++ -c list.cc