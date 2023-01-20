all: server.out client.out
server.out:
	g++ -std=c++11 -o server.out server.cpp CalculatorKnn.cpp Classifier.cpp Distance.cpp KnnCalcAuc.cpp KnnCalcCan.cpp KnnCalcChb.cpp KnnCalcMan.cpp KnnCalcMin.cpp
client.out:
	g++ -std=c++11 -o client.out client.cpp
clean:	
	rm -f *.o *.exe *.out