all: main.out
main.out: Command.o CLI.o UploadCommand.o
	g++ -std=c++11 -o main.out main.cpp CalculatorKnn.cpp Classifier.cpp Distance.cpp KnnCalcAuc.cpp KnnCalcCan.cpp KnnCalcChb.cpp KnnCalcMan.cpp KnnCalcMin.cpp StandartIO.cpp CLI.o UploadCommand.o Command.o
Command.o:
	g++ -c -std=c++11 -o Command.o Command.cpp
CLI.o:
	g++ -c -std=c++11 -o CLI.o CLI.cpp

UploadCommand.o:
	g++ -c -std=c++11 -o UploadCommand.o UploadCommand.cpp


clean:	
	rm -f *.o *.exe *.out