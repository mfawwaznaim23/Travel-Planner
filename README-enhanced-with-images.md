# Travel Planner

A command-line **Travel Planner and Trip Log** built in **C++**. The program lets a user load previously saved trips, add monument or snow destinations, view trip history, and save the current log to `database.txt` before exiting.

## Program Demo

The screenshots below are from an actual run of the program. Each image is placed next to the feature it demonstrates so the README follows the same order as the program.

### 1. Main Menu and Empty History

When the program starts, it loads `database.txt` if the file exists and then displays three choices: **H** to view history, **T** to add a trip, and **E** to save and end the session. In the example below, the history is initially empty, so the program tells the user to add trips first.



<img width="1536" height="286" alt="image" src="https://github.com/user-attachments/assets/677b22f3-1307-4a3a-a7a6-331ffd8f93d8" />




### 2. Adding a Monument Destination — Mount Rushmore

Pressing **T** starts the trip-entry process. The user enters the date, city, country, vacation type, estimated cost, and destination type. Choosing **M** creates a monument destination and asks whether it is a UNESCO heritage site, followed by the monument name.

This run adds **Keystone, USA**, with **MountRushmore** as the monument.



<img width="1102" height="576" alt="image" src="https://github.com/user-attachments/assets/5c18be2c-ca53-49ea-b847-18f597e21d96" />




### 3. Adding Another Monument Destination — Taj Mahal

The same monument flow can be used for another object. Here, the program adds **Agra, India**, identifies the destination as a monument, records it as a heritage monument, and stores **TajMahal** as the monument name.



<img width="1046" height="603" alt="image" src="https://github.com/user-attachments/assets/057a82eb-4d7f-470e-95cc-5abd6ea6483c" />




These two examples show that the same `monumentdestination` class can represent multiple monument-trip instances while keeping each object's own trip data.

### 4. Adding a Snow Destination — Aspen

Choosing **S** instead creates a `snowdestination`. In addition to the common trip information, the program asks whether the snow destination is a ski site and then asks for the snow-site name.

In this example, **Aspen, USA** is added as a winter trip with **snowmass** recorded as a ski site.



<img width="1064" height="615" alt="image" src="https://github.com/user-attachments/assets/2fd72080-2ddd-4244-9fa5-c418e59b3ffe" />




### 5. Saved Records in `database.txt`

Each destination is written in a compact format. The first character identifies the object's type:

- `M` = monument destination
- `S` = snow destination

The remaining values store the date, city, country, estimated cost, vacation type, destination-specific name, and a Boolean value (`1` or `0`) for the heritage/ski-site property.



<img width="1059" height="222" alt="image" src="https://github.com/user-attachments/assets/c208fbcd-4110-4c27-af2e-7a43502bd7b1" />




For example, the Aspen line begins with `S`, while the Agra line begins with `M`. When the program starts again, it uses this first character to decide which derived object to reconstruct.

### 6. Viewing Trip History

Pressing **H** reads the saved records from `database.txt`. Depending on whether a record begins with `S` or `M`, the program rebuilds the corresponding destination data and calls that destination's `output_display()` function.



<img width="1065" height="330" alt="image" src="https://github.com/user-attachments/assets/d7e90e9d-d0fc-4dbf-b43f-1f253ae685fe" />




The result is a readable history containing monument trips such as Keystone and Agra and snow trips such as Aspen and Alaska.

### 7. Saving and Ending the Session

Pressing **E** opens `database.txt` for output, calls `user1.print(output_file)`, writes the destinations stored in the log, closes the file, prints `GoodBye!`, and ends the loop.



<img width="901" height="170" alt="image" src="https://github.com/user-attachments/assets/3a99ebb0-7c66-43b6-a8b3-16af2eb92514" />




This allows the saved trips to be loaded again the next time the program runs.

---

## How the Program Is Designed

The project uses object-oriented programming to represent several related destination types without putting all destination-specific behavior into one class.

### Class Structure

```text
                 destination
                 /         \
                /           \
     snowdestination     monumentdestination
                \           /
                 \         /
                  log stores
              destination* objects
```

### `destination` — Base Class

`destination` contains information shared by every trip, including the destination name, country, vacation type, date, and estimated cost. It also provides virtual functions that derived classes can override.

The shared fields are why both the monument and snow screenshots ask for the same basic information before asking destination-specific questions.

### `snowdestination` — Derived Class

`snowdestination` inherits the common destination information and adds snow-specific information:

- snow-site name
- whether the location is a ski site

The Aspen screenshot above is a direct example of a `snowdestination` instance.

![Snow destination instance](images/add-snow.png)

### `monumentdestination` — Derived Class

`monumentdestination` inherits the same common destination information and adds monument-specific information:

- monument name
- whether it is recognized as a heritage monument

The Keystone and Agra examples are two separate instances of this class.

![Monument destination instance](images/add-monument-agra.png)

## Inheritance

Inheritance lets `snowdestination` and `monumentdestination` reuse the common data and behavior defined by `destination`. Instead of creating separate city, country, date, vacation-type, and cost logic for every destination type, the derived classes only add what makes them different.

This is visible in the program runs: both destination types first collect the same general trip information, but the final questions change based on whether the user enters `S` or `M`.

## Polymorphism

The `log` class stores different destination types in one vector:

```cpp
vector<destination*> list;
```

A base-class pointer can therefore point to a `destination`, `snowdestination`, or `monumentdestination` object. The program uses `gettype()` to determine the concrete type when copying objects, while virtual functions such as `print()`, `input_display()`, and `output_display()` allow destination-specific behavior.

The mixed saved history demonstrates why this is useful: monument and snow destinations can belong to the same trip log even though they contain different specialized information.

![Mixed monument and snow records](images/database-records.png)

## Dynamic Memory and Copying

`log::add_destination()` creates a new object on the heap according to the destination type and stores its pointer in the vector. For example, an `M` results in a copied `monumentdestination`, while an `S` results in a copied `snowdestination`.

Because the vector owns dynamically allocated objects, the `log` class also defines a destructor. The project additionally defines a copy constructor and copy-assignment operator so copied logs can create their own destination objects rather than intentionally sharing the same object pointers.

## File Input and Output

The program uses `ifstream` and `ofstream` with `database.txt`.

**Loading:** At startup, `main()` reads the first type character from each saved record. `S` causes the snow fields to be read into a `snowdestination`; `M` causes the monument fields to be read into a `monumentdestination`. Each reconstructed object is then added to `user1`.

**Saving:** When the user presses **E**, `user1.print(output_file)` sends every stored object's data back to `database.txt`.

![Database file format](images/database-records.png)

## Program Flow

```text
Start
  |
  v
Open database.txt
  |
  v
Load S and M records into the log
  |
  v
Display menu
  |
  +---- H ----> Read/display saved history ----+
  |                                             |
  +---- T ----> Enter common trip information  |
  |                 |                           |
  |                 +-- S --> Snow details -----+
  |                 |                           |
  |                 +-- M --> Monument details -+
  |                                             |
  +---- E ----> Save log to database.txt --> End
```

## Features

- Interactive terminal menu for viewing, adding, and saving trips
- Monument and snow destination types
- Common trip fields: date, city, country, vacation type, and estimated cost
- Monument-specific heritage status and monument name
- Snow-specific ski-site status and snow-site name
- Persistent storage using `database.txt`
- Loading saved destination objects when the program starts
- Inheritance and polymorphism through a common `destination` base class
- Dynamic allocation of destination objects inside the trip log
- Copy constructor, copy-assignment operator, and destructor in `log`

## What I Practiced

This project gave me practice with **C++ classes and objects, inheritance, polymorphism, virtual functions, base-class pointers, dynamic memory, destructors, copy constructors, copy assignment, STL `vector`, references, file I/O, and interactive command-line program design**.

## How to Run

Compile all source files together. For example, with `g++`:

```bash
g++ mainpa2.cpp Destination.cpp Log.cpp MonumentDestination.cpp SnowDestination.cpp -o travel_planner
```

Then run:

```bash
./travel_planner
```

On Windows:

```bash
travel_planner.exe
```

Keep `database.txt` in the same working directory as the executable so the program can load and save the trip records.

## Project Files

```text
Travel-Planner/
├── mainpa2.cpp
├── Destination.h
├── Destination.cpp
├── SnowDestination.h
├── SnowDestination.cpp
├── MonumenDestination.h
├── MonumentDestination.cpp
├── Log.h
├── Log.cpp
├── database.txt
├── images/
│   ├── saved-history.png
│   ├── add-monument.png
│   ├── add-monument-agra.png
│   ├── add-snow.png
│   ├── database-records.png
│   ├── trip-history.png
│   └── save-exit.png
└── README.md
```
