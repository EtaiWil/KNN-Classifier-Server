all: server.out client.out
server.out:
	g++ -std=c++11 -pthread -o server.out server.cpp CLI.cpp StandartIO.cpp CalculatorKnn.cpp Classifier.cpp Distance.cpp KnnCalcAuc.cpp KnnCalcCan.cpp KnnCalcChb.cpp KnnCalcMan.cpp KnnCalcMin.cpp UploadCommand.cpp Command.cpp SettingCommand.cpp ClassifyCommand.cpp PrintCommand.cpp SendCommand.cpp ExitCommand.cpp SocketIO.cpp
client.out:
	 g++ -std=c++11 -pthread -o client.out client.cpp SocketIO.cpp
clean:	
	rm -f *.o *.exe *.out