#include "List.h"
#include "Node.h"
#include "SinglyLinked.h"

#include <iostream>
#include <string>

using namespace std;

int main(int argc, char const *argv[])
{
    Node<int> node1(6);
    Node<int> node2(12);
    Node<int> node3(6);
    
    if (node1.getData() == node2.getData())
    {
        cout << "Node 1 and Node 2 are equal" <<endl;
    }
    else
    {
        cout << "Node 1 and Node 2 are not equal" <<endl;
    }

    if (node2.getData() == node3.getData())
    {
        cout << "Node 2 and Node 3 are equal" <<endl;
    }
    else
    {
        cout << "Node 2 and Node 3 are not equal" <<endl;
    }

    if (node1.getData() == node3.getData())
    {
        cout << "Node 1 and Node 3 are equal" <<endl;
    }
    else
    {
        cout << "Node 1 and Node 3 are not equal" <<endl;
    }

    std::cout << "node1: " << &node1 << std::endl;  // must into ostream by refernce because parameter accepts a pointer
    std::cout << "node2: " << &node2 << std::endl;
    std::cout << "node3: " << &node3 << std::endl;

    SinglyList<int> myList;

    // Insert elements into the list
    //myList.insert(4, 0);
    myList.insert(2, 1);
    myList.insert(6, 2);

    myList.insert(8, 3);

    
    // Display the list
    std::cout << "Original List: " << &myList << std::endl;
    
    //Find the smallest and biggest elements
    Node<int>* smallest = myList.findSmallest();
    Node<int>* biggest = myList.findBiggest();
    
    if (smallest && biggest) 
    {
        std::cout << "Smallest: " << smallest->getData() << std::endl;
        std::cout << "Biggest: " << biggest->getData() << std::endl;
    } 
    else 
    {
        std::cout << "List is empty." << std::endl;
    }

     // Clone the list
    List<int>* cloned = myList.clone();   
    std::cout << "Cloned List: " << cloned << std::endl;

   
    // Sort the list in ascending order
    List<int>* ascendingSorted = myList.sort(true);
    std::cout << "Ascending Sorted List: " << ascendingSorted << std::endl;
    
    
    // Sort the list in descending order
    List<int>* descendingSorted = myList.sort(false);
    std::cout << "Descending Sorted List: " << descendingSorted << std::endl;
    
    int arr[] = {10, 20, 30, 40, 50};
    SinglyList<int> listerine(arr, 5);

    // Print the original list
    std::cout << "Original List: " << &listerine << std::endl;

    // Test the clone function
    List<int>* cloneee = listerine.clone();
    std::cout << "Cloned List: " << cloneee << std::endl;

    // Test the [] operator
    Node<int>* nodeAtIndex2 = listerine[2];
    if (nodeAtIndex2) 
    {
        std::cout << "Element at index 2: " << nodeAtIndex2->getData() << std::endl;
    }

    // Test the () operator
    int searchData = 30;
    Node<int>* nodeWithData30 =listerine(&searchData);
    if (nodeWithData30) 
    {
        std::cout << "Node with data 30 found: " << nodeWithData30->getData() << std::endl;
    }

    // Test getIndexFromFront and getIndexFromRear
    int indexFromFront = listerine.getIndexFromFront(30);
    int indexFromRear = listerine.getIndexFromRear(60);

    std::cout << "Index from Front of 30: " << indexFromFront << std::endl;
    std::cout << "Index from Rear of 30: " << indexFromRear << std::endl;

    // Test the remove function
    int removedIndex = listerine.remove(20);
    std::cout << "Removed element at index " << removedIndex << std::endl;

    delete cloned;
    delete cloneee;
    delete ascendingSorted;
    delete descendingSorted;
    
    // SinglyList<int> myList;

    // // Insert some elements into the list
    // myList.insert(10, 0);
    // myList.insert(20, 1);
    // myList.insert(30, 2);
    // myList.insert(40, 3);
    // myList.insert(50, 4);

    // // Testing operator[] with various indices
    // for (int i = -6; i <= 6; i++) {
    //     Node<int>* node = myList[i];
    //     if (node != NULL) {
    //         cout << "Element at index " << i << ": " << node->getData() << endl;
    //     } else {
    //         cout << "Index " << i << " is out of bounds." << endl;
    //     }
    // }

    
    // SinglyList<int> myList;

    // // Populate the list with some data
    // myList.insert(10, 0); // Insert 10 at the front
    // myList.insert(20, 1); // Insert 20 at position 1
    // myList.insert(30, 2); // Insert 30 at position 2
    // myList.insert(40, 3); // Insert 40 at position 3
    // myList.insert(50, 4); // Insert 50 at position 4
    // myList.insert(20, myList.size()); // Add a duplicate value (append)

    // // Testing getIndexFromRear
    // int dataToFind = 20;
    // int indexFromRear = myList.getIndexFromRear(dataToFind);

    // if (indexFromRear != -1)
    // {
    //     std::cout << "The index of data " << dataToFind << " from the rear is: " << indexFromRear << std::endl;
    // }
    // else
    // {
    //     std::cout << "Data " << dataToFind << " not found in the list." << std::endl;
    // }

    return 0;
}