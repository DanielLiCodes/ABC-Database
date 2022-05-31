# ABC DATABASE
![Build](https://github.com/cs100/final-project-abcer/actions/workflows/main.yml/badge.svg)


 > Authors: [Shashank Biju, ](https://github.com/shadJack127)
 >          [Daniel Li,](https://github.com/DanielLiCodes)
 >          [Nisarg Patel, ](https://github.com/NisargIO)
 >          [Marcus Lee ](https://github.com/MLee2003)


# Project Description

> * We plan to use C++ for our language with REST libraries, allowing us to communicate with the database and its potential clients. The data that will be stored will be JSON, so a JSON library will also be used. 
> * [Pistache](https://github.com/pistacheio/pistache) - REST API for CPP
> * [JSONCPP](https://github.com/Tencent/rapidjson) - JSON for CPP

> * For personal technologies/clients, we will be using VSCode as our IDE and Github as our version control.
> * [VSCODE](https://code.visualstudio.com/) - a lightweight but powerful source code editor which runs on your desktop and is available for Windows, macOS and Linux. It comes with built-in support for JavaScript, TypeScript and Node.
> * [Github](https://github.com/) - is a web-based version-control and collaboration platform for software developers.

## Features Provided:
> * **Set** - it will ask for an id and data object to store, and then using a hash algorithm store the data in a position within the hash table given by the key.

> * **Find** -  Given an id, using a hash algorithm it will find a key and then retrieve the stored data at the location.

> * **Delete** - given an id, Using the hash algorithm, it will find the data stored at the location and delete it.


 # Phase II
 
 ## UML Diagram
![UML Diagram](https://user-images.githubusercontent.com/64798216/166169966-2decf51f-9cdf-435f-8c65-9181d8f42210.jpeg)


For our class diagram, we have one main database abstract class, which is the base database. That's linked to 3 different types of databases, for arrays, hashtables, and linked lists. Those databases each have their own methods and variables according to what a linked list, array, and hashtable have, such as a head/tail for linked list, and a resize function for array.

The database then has another abstract class, which is the database node. The database node class is extended by a string node, as well as a JSON node class. In each database class such as the hashtable class, it will be made using the database nodes. For example, the hashmap class has an array of database nodes, which are then used in the hashmap. 

The JSON node allows for quick access from our api calls, and the string node is just a regular string. 
 
 > ## Phase III

![Blank diagram(2)](https://user-images.githubusercontent.com/64798216/168508908-bb8beeb2-8654-4802-ad5e-0c47d48f9ddb.jpeg)

We decided upon using the strategy pattern, because we realized that we could use different types of sorting algorithems to organize our array database, such as insertion sort, quicksort, and bogo sort. In order to achieve this, we chose the strategy patern, and had different sorting strategys linked to our array database class. Then for our sorting function, we would take in a strategy, with the default being quicksort. This design pattern helped us write better code as it enables a clean user experience, where they in general can use one of the most efficient sorting methods, but can also use sorts such as insertion for small arrays, or bogo sort if they are trying to have fun. It leads to less clutter in our array database class, and we did not need to implement many different sorting functions there. We also considered the composite pattern, but realized that we did not need it as there was not really a composite aspect for our project, as we don't plan on suporting arrays of arrays, or anything of the sort.


 
 > ## Final deliverable!

 ![UML final](https://user-images.githubusercontent.com/62776702/171256170-1a8fb58e-d5d5-4dfa-9832-a7914b196806.jpeg)
 
 There are some significant chnages that have happened since the third phase of the project. We have intorduced a Database Manager class which is used to determine wether an individual has the verification needed to access a Databaase. Our project continued witht the strategy pattern, and like prior used sorting algortithms to organize our array database, the only difference being the new sorting startegy we added(SelectionSort). The continued updates on the UML diagram helped us follow the chnages on our code cleanly, so we could visualize the steps we would need to take to ensure a complete project.
 
 The overall efficiency of the code has been tested and we have found no errors in our testing process thus far which will be touched on further below. Through the developmental process certain functions we intially planned on creating have been dropped or switched out. We found the need for function we intially hadn't had and found others redundant and we acted accordingly reaching the end of this sprint. The kanban board has the ideas in place for the next sprint.
 
 ## Screenshots
 > Screenshots of the input/output after running your application
 ## Installation/Usage
 > Instructions on installing and running your application
  - Step 1: clone the repository to your device
  - Step 2: type in (cmake .) or (cmake3 . on hammer)
  - Step 3: type make into the terminal
  - Step 4: Congrats you've installed the program and now you can begin to use the database
 >
Usage:
After installing the program onto your terminal, we can begin using ABCDatabase. 
Step 1:

On one terminal page, type in ./ABCdatabase. This will activate the system. 

Step two: 

Then on another terminal you can curl information for example:
	Curl “http://localhost:8080/database/create?type=array&name=accounts” 
Which will create an array named accounts. The file below further describes the pathways of adding/setting/getting/removing/printing values into a database.

You can continue to do this until satisfied with the database

 ## Testing
 > How was your project tested/validated? If you used CI, you should have a "build passing" badge in this README.
 
