cmake_minimum_required(VERSION 3.24)
project(ass03)
set(CMAKE_CXX_STANDARD 11)
add_executable(ass03 server.cpp CalculatorKnn.cpp Classifier.cpp Distance.cpp KnnCalcAuc.cpp KnnCalcCan.cpp KnnCalcChb.cpp KnnCalcMan.cpp KnnCalcMin.cpp)
