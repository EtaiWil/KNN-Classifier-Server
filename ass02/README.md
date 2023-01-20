## Assignment 2
This is Etai and Oz README for Ass2 where we implemented the KNN Algorithm.
## Introduction
K-nearest neighbors (KNN) is a supervised machine learning algorithm that can be used for classification or regression. In the case of classification, the algorithm finds the K data points in the training dataset that are closest to the new data point, and then assigns the new data point to the class that those K data points belong to.
## how we implemented:
We did this by creating an abstract `CalculatorKnn` class which implemented the algorithm and used a virtual unimplemented method that is called `calculateDistance`.
By doing so, each class that inherits from `CalculatorKnn`needs to implement this method. in each of the inheriting classes we have implemented this method with the `Distance` class we wrote in the last assignment.

We also created a `Classifier` class that gets a K for the number of KNN and a string repressenting the Distance we want to calculate, the `classifier` creates a list of vectors and their classification in a tuple from the file given as an argument.
The classifier also creates a calculator of the requested type with the given K and the list of vectors that we read from the given file.
By creating the calculator inside the Classifier we have done **composition**.
Eventually after reading all the classified vectors, the program gets a vector from the user to classify, and it classifies it with the `classify` method that gets the vector and returns a string - the classification of the vector.
## run example
in this example we loaded a dataset that contains wine types and we have entered a vector that repressents an unclassified wine.
as a result we got that the wine that the vector is closest to by manhattan distance and k=7 is a white wine
![image](https://user-images.githubusercontent.com/93612510/207716599-5f8f22cf-a801-407c-b1a1-f69933eb32c3.png)

##compile and run instructions
**Compile by `> make` and run by `> a.out k file distance` with k being the K for KNN, file being the path to the Classfied vectors file,and distance being a distance to use**
distance options:
- AUC - Euclidian Distance
- MAN - Manhattan Distance
- CHB - Chebyshev Distance
- CAN - Canberra Distance
- MIN - Minkowski Distance
