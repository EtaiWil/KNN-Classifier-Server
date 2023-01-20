## Assignment 3
This is Etai and Oz README for Assignment 3 where we implemented the KNN Algorithm on a TCP server, with a client side to send over the requested data to classify.
## Introduction
K-nearest neighbors (KNN) is a supervised machine learning algorithm that can be used for classification or regression. In the case of classification, the algorithm finds the K data points in the training dataset that are closest to the new data point, and then assigns the new data point to the class that those K data points belong to.
Transmission Control Protocol (TCP) is a standard that defines how to establish and maintain a network conversation by which applications can exchange data.
TCP is a connection-oriented protocol, which means a connection is established and maintained until the applications at each end have finished exchanging messages.
## how we implemented:
We modified our first implementation of the Classifier class we built in [assignment 2](https://github.com/EtaiWil/advanced-programming-1/tree/main/ass02) to get K and the desired Distance Type as arguments to the Classify function instead of the constructor. The classifier holds KNN calculators (which we also built in this assignment) of each distance type (they all inherit from abstrct class with a virtual distance calculation function) in a map of string keys and the calculators as values. when getting the request from the client we use the requested distance type string to get the matching calculator and request from him to classify the given vector with a given K value from the client.
When the client sends a vector, a distance type and a K value, we validate the input and use the calculatorKnn classify method to get it's classification from the vectors we first read from the file.
## run example
in this example we loaded a dataset that contains wine types and we have entered a vector, the Manhattan distance shortcut and K=8.
as a result we got an answer from the server that the wine that the vector is closest to by Manhattan distance and k=8 is a white wine
![image](https://user-images.githubusercontent.com/93612510/210455619-7cf58f39-154e-4cea-94fc-33b038bd1436.png)

## compile and run instructions
**Compile by `> make` and run by running a server and a client.**

server : `> server.out FilePath PortNumber`
client : `> client.out ServerIp ServerPort`
after running both, the client should enter a valid vector seperated by spaces, a distance Metric shortcut from the valid options and a valid K. 
distance options:
- AUC - Euclidian Distance
- MAN - Manhattan Distance
- CHB - Chebyshev Distance
- CAN - Canberra Distance
- MIN - Minkowski Distance

##### please note:
_if the given K is bigger than the dataset, the returned output will be according to the number of vectors in the dataset instead_
