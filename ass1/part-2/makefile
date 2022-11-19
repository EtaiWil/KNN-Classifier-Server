all: main.o
main.o: main.cpp Distance.cpp	
	g++ -std=c++11 -o main.o main.cpp Distance.cpp
run: main.o
	./main.o
clean:	
	rm -f *.o *.exe