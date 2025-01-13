Singly Linked List Project
This project implements a Singly Linked List data structure in C++. The code defines a series of classes and templates to manage and manipulate a linked list, including functions for insertion, deletion, sorting, and more. The project utilizes object-oriented principles like polymorphism and inheritance for flexibility and extensibility.

Project Structure
Header Files
  Node.h: Defines the Node class, representing the elements of the linked list. Each node holds data and a pointer to the next node.
  List.h: Defines the abstract List class that serves as a base class for all types of lists. It declares common operations such as insert, remove, sort, and clone, but leaves the implementation to derived classes.
  SinglyList.h: Defines the SinglyList class, which inherits from List. It provides the actual implementation for singly linked list operations such as insert, remove, sorting, and more.
Source Files
  Node.cpp: Implements the Node class methods.
  List.cpp: Implements the abstract methods declared in List (although some are left empty to be implemented by derived classes).
  SinglyList.cpp: Implements the SinglyList class methods, including specific functions for working with singly linked lists.
  
Key Classes and Functions
  Node<T>
  Represents an element in the linked list.
  Stores a data element of type T and a pointer to the next node in the list.
  List<T> (Abstract Base Class)
  Declares the structure and common operations for linked lists.
Defines functions like:
  insert: Insert data at a specified position.
  remove: Removes data and returns the index of the removed node.
  size: Returns the size of the list.
  contains: Checks if a certain value is in the list.
  sort: Sorts the list in ascending or descending order.
  clone: Creates a deep copy of the list.
SinglyList<T> (Derived Class)
A concrete class derived from List that implements the specific behavior of a singly linked list.
Implements the following functions:
  insert: Inserts a node at a specified position.
  remove: Removes a node with specified data.
  operator[]: Accesses a node at a given index (supports both positive and negative indices).
  operator(): Searches for a node by its data.
  getIndexFromFront: Gets the index of a node starting from the front.
  getIndexFromRear: Gets the index of a node starting from the rear.
  sort: Sorts the list in ascending or descending order.
  findSmallest: Finds and returns the node with the smallest data.
  findBiggest: Finds and returns the node with the largest data.
  clone: Creates a deep copy of the list.
Compilation and Usage
Prerequisites:
A C++ compiler such as g++ is required to compile the project.
Compilation Instructions:
To compile the project, run the following command from the project directory:
g++ -std=c++11 main.cpp -o linkedlist
./linkedlist

Features
  Polymorphism: The use of polymorphism allows for flexible implementation of list operations across various types of linked lists (e.g., singly linked list, doubly linked list).
  Sorting: The list can be sorted in ascending or descending order based on a boolean flag.
  Memory Management: The code properly handles memory management with dynamic memory allocation and deallocation for list nodes.
