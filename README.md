# ABC DATABASE


 > Authors: [Shashank Biju, ](https://github.com/shadJack127)
 >          [Daniel Li,](https://github.com/DanielLiCodes)
 >          [Nisarg Patel, ](https://github.com/NisargIO)
 >          [Marcus Lee ](https://github.com/MLee2003)


# Project Description

> * We plan to use C++ for our language with REST libraries, allowing us to communicate with the database and its potential clients. The data that will be stored will be JSON, so a JSON library will also be used. 
> * [RESTCPP](https://github.com/microsoft/cpprestsdk) - REST API for CPP
> * [JSONCPP](https://github.com/open-source-parsers/jsoncpp) - JSON for CPP

> * For personal technologies/clients, we will be using VSCode as our IDE and Github as our version control.
> * [VSCODE](https://code.visualstudio.com/) - a lightweight but powerful source code editor which runs on your desktop and is available for Windows, macOS and Linux. It comes with built-in support for JavaScript, TypeScript and Node.
> * [Github](https://github.com/) - is a web-based version-control and collaboration platform for software developers.

## Features Provided:
> * **Set** - it will ask for an id and data object to store, and then using a hash algorithm store the data in a position within the hash table given by the key.

> * **Find** -  Given an id, using a hash algorithm it will find a key and then retrieve the stored data at the location.

> * **Delete** - given an id, Using the hash algorithm, it will find the data stored at the location and delete it.


 # Phase II
 
 ## UML Diagram
![umldiagram](https://user-images.githubusercontent.com/64798216/166168503-db77f2dc-c369-4c99-ab9c-8bb30eb916d2.jpeg)
For our class diagram, we have one main database class, with 3 sub databases for different data types. The database is comprised of that, as well as normal Database node, that can be modified and compared to other nodes.
The nodes consist of two different types of nodes, a regular JSON node for easy access, as well as a string node that just holds a string.

 > In addition to completing the "Class Diagram" section below, you will need to:
 > * Create an "Epic" (note) for each feature. Place these epics in the `Backlog` column
 > * Complete your first *sprint planning* meeting to plan out the next 7 days of work.
 >   * Break down the "Epics" into smaller actionable user stories (i.e. smaller development tasks). Convert them into issues and assign them to team members. Place these in the `TODO` column.
 >   * These cards should represent roughly 7 days worth of development time for your team, taking you until your first meeting with the TA
 > * Schedule two check-ins using Calendly. You need to pick both time slots during your lab on week 6. Your entire team must be present for both check-ins.
 >   * The first check-in needs to be scheduled with your lab TA. During that meeting, you will discuss your project design/class diagram from phase II.
 >   * The second check-in should be scheduled with a reader. During that meeting you will discuss:
 >     * The tasks you are planning for the first sprint
 >     * How work will be divided between the team members

## Class Diagram
 > Include a **class diagram(s)** for your project and a **description** of the diagram(s). Your class diagram(s) should include all the main classes you plan for the project. This should be in sufficient detail that another group could pick up the project this point and successfully complete it. Use proper UML notation (as discussed in the course slides).
 
 > ## Phase III
 > You will need to schedule a check-in for the second scrum meeting with the same reader you had your first scrum meeting with (using Calendly). Your entire team must be present. This meeting will occur on week 8 during lab time.
 > * Before the meeting you should perform a sprint plan like you did in Phase II.
 > * You should also update this README file by adding the following:
 >   * What design pattern(s) did you use? For each pattern you must explain in 4-5 sentences:
 >     * Why did you pick this pattern? And what feature did you implement with it?
 >     * How did the design pattern help you write better code?
 >   * An updated class diagram that reflects the design pattern(s) you used. You may combine multiple design patterns into one diagram if you'd like, but it needs to be clear which portion of the diagram represents which design pattern (either in the diagram or in the description).
 >   * Make sure your README file (and Project board) are up-to-date reflecting the current status of your project. Previous versions of the README file should still be visible through your commit history.
> 
> During the meeting with your reader you will discuss: 
 > * How effective your last sprint was (each member should talk about what they did)
 > * Any tasks that did not get completed last sprint, and how you took them into consideration for this sprint
 > * Any bugs you've identified and created issues for during the sprint. Do you plan on fixing them in the next sprint or are they lower priority?
 > * What tasks you are planning for this next sprint.

 
 > ## Final deliverable
 > All group members will give a demo to the TA/reader during lab time. The TA/reader will check the demo and the project GitHub repository and ask a few questions to all the team members. 
 > Before the demo, you should do the following:
 > * Complete the sections below (i.e. Screenshots, Installation/Usage, Testing)
 > * Plan one more sprint (that you will not necessarily complete before the end of the quarter). Your In-progress and In-testing columns should be empty (you are not doing more work currently) but your TODO column should have a full sprint plan in it as you have done before. This should include any known bugs (there should be some) or new features you would like to add. These should appear as issues/cards on your Project board.
 > * Make sure your README file and Project board are up-to-date reflecting the current status of your project (e.g. any changes that you have made during the project such as changes to your class diagram). Previous versions should still be visible through your commit history. 
 
 ## Screenshots
 > Screenshots of the input/output after running your application
 ## Installation/Usage
 > Instructions on installing and running your application
 ## Testing
 > How was your project tested/validated? If you used CI, you should have a "build passing" badge in this README.
 
