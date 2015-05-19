Main: main.cpp HugeInt.o
	g++ -o main main.cpp HugeInt.o
HugeInt.o: HugeInt.cpp HugeInt.h
	g++ -c HugeInt.cpp -o HugeInt.o
