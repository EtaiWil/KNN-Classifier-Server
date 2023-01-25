## Assignment 4
This is Etai and Oz README for Assignment 4 where we implemented the KNN Algorithm on a MultiThreaded TCP server, with a client side to send over the requested data to classify.
## Introduction
K-nearest neighbors (KNN) is a supervised machine learning algorithm that can be used for classification or regression. In the case of classification, the algorithm finds the K data points in the training dataset that are closest to the new data point, and then assigns the new data point to the class that those K data points belong to.
Transmission Control Protocol (TCP) is a standard that defines how to establish and maintain a network conversation by which applications can exchange data.
TCP is a connection-oriented protocol, which means a connection is established and maintained until the applications at each end have finished exchanging messages.
## how we implemented:
We Created a CLI class that manages all the data from the server, it gets a DefaultIO object which is an abstract class, and it uses it to communicate, this way we created a SocketIO class that implements it and that way we communicated with a Tcp socket. in the beggining we used the terminal to pass the messages so we also implemented a StandartIO class that uses the terminal to get the data.
The CLI also has a Classfier object member, at first it need to train his classifier with data he gets from the IO, and afterwards he can use this trained classifier to classify his test vectors (which he also got from the user).
We used the Command Design Pattern to create and control all the commands. each Command Object has a description and an excecute method (each command has a different one).
![image](https://user-images.githubusercontent.com/93612510/214552651-51cafca3-c932-42ad-9b83-68d46c8252f6.png)

The CLI object has a list of all of his Commands and in each time he writes his menu to the IO he prints all of his Commands description and this way he gets an input from the IO and calls the matching Command excecute method.
![image](https://user-images.githubusercontent.com/93612510/214552710-43d1289f-99c8-423f-907d-a5e86e623628.png)
For Each client That creates a TCP Connection in the server a new Thread opens with the handleClient method that gets the clients socket as an argument, and in this thread a new CLI object is created and handles the Client.
By doing so we can support up to 5 clients at a a time because the client handling is happening on a different thread, and the main thread returns to accept a new connection from other clients.

## run example
in this example we loaded a dataset that contains iris flower types and its test vectors , reconfigured the KNN algorithm settings to K=7 and distance metric to by Manhattan Distance. than we classified the test vectors and printed the classifications, at the end we downloaded the classifications.
![image](https://user-images.githubusercontent.com/93612510/214554064-bbb94b1d-2126-40a0-9cfa-9d14ce864591.png)
![image](https://user-images.githubusercontent.com/93612510/214554159-0c6343cd-0e02-4e3c-9ccf-eab00e3a78df.png)


## compile and run instructions
**Compile by `> make` and run by running a server and a client.**

run a server : `> server.out PortNumber`

run a client : `> client.out ServerIp ServerPort`

The options for Distance Metric calculation in the algorithm settings are :

- AUC - Euclidian Distance
- MAN - Manhattan Distance
- CHB - Chebyshev Distance
- CAN - Canberra Distance
- MIN - Minkowski Distance

##### please note:
_if the given K is bigger than the dataset, the returned output will be according to the number of vectors in the dataset instead_
