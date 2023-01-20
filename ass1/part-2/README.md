## Welcome To Part 2 Of our Assignment
How To Run using make: `make run` (checked and worked on planet.
you can also use 'make clean' to delete the object files.
if you want to compile and run on your own please try :
```bash
g++ -std=c++11 -o main.o main.cpp Distance.cpp
./main.o
```
In the Distance calculations we first implemented the Minkowski Distance, and used it to implement the Euclidian Distance function (P=2), and the Manhattan Distance function (P=1).
For Invalid input the program will print _Invalid arguments for the Vector_ and close.
For trying to calculate the distance between two vectors from different dimension the program will print _The Dimensions of the vectors are not the same_ and close.
