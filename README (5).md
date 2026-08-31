# Travel Planner

A command-line **Travel Planner and Trip Log** built in **C++**. The program allows users to add different types of trips, view their saved trip history, and save the trip log to a text file.

## Preview

_Add a screenshot of the program running in the terminal here._

## About the Project

This project was built to practice **object-oriented programming in C++**, particularly inheritance, polymorphism, dynamic memory, classes, constructors/destructors, operator overloading, and file input/output.

The program models different kinds of travel destinations using a common base class and specialized derived classes. A `destination` represents general trip information, while `snowdestination` and `monumentdestination` extend it with destination-specific information.

The trip objects are stored in a `vector` of base-class pointers, allowing different destination types to be managed through the same container.

## Features

- Add new trips through an interactive command-line menu
- Add snow destinations and specify whether they are ski sites
- Add monument destinations and specify whether they are UNESCO heritage monuments
- Store destination city, country, travel type, date, and estimated cost
- View previously saved trip history
- Save trip information to `database.txt`
- Load existing trips from `database.txt` when the program starts
- Handle multiple destination types through polymorphism

## Object-Oriented Programming

### Inheritance

The project uses a base `destination` class containing information shared by all trips.

Two classes inherit from it:

- `snowdestination`
- `monumentdestination`

This avoids duplicating common destination information while allowing each derived class to have its own additional properties and behavior.

For example, a `snowdestination` stores a snow-site name and whether it is a ski site, while a `monumentdestination` stores a monument name and whether it is a heritage monument.

### Polymorphism

The `log` class stores destinations using:

```cpp
vector<destination*> list;
```

Because the vector contains pointers to the base class, it can store objects belonging to different derived classes.

The virtual `gettype()`, `output_display()`, `input_display()`, and `print()` functions allow the appropriate derived-class behavior to be selected for each destination.

This was one of the main concepts I practiced with the project: using a common interface while allowing different destination types to provide their own implementations.

### Dynamic Memory

The `log` class dynamically creates copies of destination objects when they are added to the log.

Because the class owns dynamically allocated objects, it also includes a destructor to release that memory.

The project also implements a **copy constructor** and **copy assignment operator** so that the dynamically allocated destination objects can be copied correctly rather than simply copying their pointer addresses.

## File Input & Output

The program uses `fstream` to store trip information in `database.txt`.

When the program starts, it reads the saved trip records from the file and reconstructs the appropriate destination objects based on their type identifier:

- `S` = snow destination
- `M` = monument destination

When the user chooses to end the session, the current trip log is written back to `database.txt`.

This allowed me to practice reading structured data from a file, writing data to a file, and using the stored information to rebuild objects when the program starts again.

## Program Flow

When the program starts:

1. It attempts to open `database.txt`.
2. Existing trip records are read from the file.
3. The records are converted into the appropriate destination objects.
4. The user is shown a menu with options to view history, add a trip, or save and exit.

When adding a trip, the user enters information such as the date, destination, country, travel type, estimated cost, and destination type.

Depending on the selected destination type, additional information is requested for either a snow destination or a monument destination.

When the user chooses to save and exit, the current log is written to `database.txt`.

## Classes

### `destination`

The base class containing common trip information:

- Destination name
- Country
- Travel type
- Date
- Estimated cost

It also provides virtual functions that can be overridden by derived classes.

### `snowdestination`

Derived from `destination` and adds:

- Snow-site name
- Ski-site status

### `monumentdestination`

Derived from `destination` and adds:

- Monument name
- Heritage monument status

### `log`

Acts as the container for the user's trips.

It manages a `vector<destination*>` and is responsible for adding destinations, copying stored objects, printing them to the database file, and releasing dynamically allocated memory.

## What I Learned

This project helped me practice:

- Object-oriented programming in C++
- Classes and objects
- Encapsulation
- Inheritance
- Polymorphism
- Virtual functions
- Base-class pointers
- Dynamic memory allocation
- Destructors
- Copy constructors
- Copy assignment operators
- Operator overloading
- STL `vector`
- References and pointers
- File input/output with `ifstream` and `ofstream`
- Reading and writing structured data
- Building an interactive command-line program

## How to Run

Compile the C++ source files together using a C++ compiler such as `g++`.

For example:

```bash
g++ mainpa2.cpp Destination.cpp Log.cpp MonumentDestination.cpp SnowDestination.cpp -o travel_planner
```

Then run:

```bash
./travel_planner
```

On Windows, the executable can be run with:

```bash
travel_planner.exe
```

Make sure `database.txt` is in the same directory as the executable so that saved trip information can be loaded and written correctly.

## Credits

This project was created as a C++ programming project to practice object-oriented programming and file handling.
