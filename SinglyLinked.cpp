#ifndef SINGLY_SinglyList_CPP
#define SINGLY_SinglyList_CPP

#include "SinglyLinked.h"

template <class T>
std::ostream &operator<<(std::ostream &os, const SinglyList<T> *sl)
{
    if (sl->head == NULL)
    {
        os << "NULL";
        return os;
    }
    Node<T> *curr = sl->head;
    while (curr != NULL)
    {
        os << curr;
        curr = curr->next;
    }
    return os;
}

template<class T>
SinglyList<T>::SinglyList():List<T>()
{}

template<class T>
SinglyList<T>::SinglyList(T* arr, int size):List<T>()
{
    if (arr==NULL || size<=0)
    {
        return;
    }
    else
    {
        for (int i=0; i<size; i++)
        {
            this->insert(arr[i],this->size());
        }
    }
}

template<class T>
SinglyList<T>::~SinglyList()
{
    Node<T>* current = this->head;
    Node<T>* next;

    while(current)
    {
        next = current ->next;
        delete current;
        current = next;
    }
    this->head = NULL;
}

template<class T>
Node<T>* SinglyList<T>:: insert (T data, int pos)
{
    Node<T>* newNode = new Node<T>(data);
    newNode->next =NULL;

    if (this->head == NULL||pos <=0)
    {
        newNode->next = this->head;
        this->head = newNode;
        return newNode;
    }
    else
    {
        Node<T>* current = this->head;
        Node<T>* prev = NULL;
        
        int index = 0;

        while (current && index < pos) 
        {
            prev = current;
            current = current->next;
            index++;
        }
    
        if (prev)
        {
            prev->next = newNode;
        }
        newNode->next = current;
    }
    return newNode;
}

template<class T>
int SinglyList<T>::remove(T data)
{
    if ( this->head ==NULL)
    {
        return-1;
    }

    Node<T>* current = this->head;
    Node<T>* prev = NULL;
    int index = 0;

    while (current)
    {
        if (current->getData()==data)
        {
            if (prev)
            {
                prev->next = current->next;
            }
            else
            {
                this->head = current ->next;
            }
            delete current;
            return index;
        }

        prev = current;
        current  =current->next;
        index++;
    }
    return -1;
}

template<class T>
Node<T>* SinglyList<T>:: operator[] (int index) const
{
    if (index>= this->size() || index < this->size()*(-1))
    {
        return NULL;
    }

    if (index >= 0)
    {
        Node <T>* pointer = this->head;
        int i=0;
        while (i < index)
        {
            pointer = pointer->next;
            i++;
        }
        return pointer;
    }

    else
    {
        Node<T>* point =this->head;
        int i =this->size()*(-1);
        while (i < index)
        {
            point = point->next;
            i++;
        }
        return point;
    }
//     if (this->head ==NULL )
//     {
//         return NULL;
//     }
//    if (index < 0) {
//         int rearIndex = -1;
//         int size = this->size(); // Use the size function provided by the base class List
//         if (index < -size) {
//             return NULL;
//         }

//         Node<T>* current = this->head;
//         while (current && rearIndex > index) 
//         {
//             current = current->next;
//             rearIndex--;
//         }

//         return current;
//     } 
//     else 
//     {
//         Node<T>* current = this->head;
//         int frontIndex = 0;

//         while (current && frontIndex < index) 
//         {
//             current = current->next;
//             frontIndex++;
//         }

//         if (frontIndex == index) 
//         {
//             return current;
//         } 
//         else 
//         {
//             return NULL;
//         }
//     }
    // if (this->head == NULL) {
    //         return NULL; // List is empty
    //     }

    //     int size = this->size();
    //     if (index >= 0 && index < size) {
    //         // Index is within bounds, start from the front.
    //         Node<T>* current = this->head;
    //         int frontIndex = 0;

    //         while (current && frontIndex < index) {
    //             current = current->next;
    //             frontIndex++;
    //         }

    //         return current;
    //     } else if (index < 0 && -index <= size) {
    //         // Index is negative and within bounds, start from the rear.
    //         Node<T>* current = this->head;
    //         int rearIndex = -1;

    //         while (current && rearIndex > index) {
    //             current = current->next;
    //             rearIndex--;
    //         }

    //         return current;
    //     } else {
    //         // Index is out of bounds.
    //         return NULL;
    //     }
}


template<class T>
Node<T>* SinglyList<T>:: operator() (T* dataPtr) const
{
    if (this->head ==NULL || dataPtr ==NULL)
    {
        return NULL;
    }
    Node<T>* current = this->head;

    while(current)
    {
        if (*(dataPtr) == current->getData() )
        {
            return current;
        }
        current=current->next;
    }
    return NULL;
}

template<class T>
int SinglyList<T>::getIndexFromFront (T data) const
{
    if (this->head ==NULL )
    {
        return -1;
    }

    Node<T>* current= this->head;
    int index = 0;
    while (current)
    {
        if (current->getData()==data)
        {
            return index;
        }
        current = current->next;
        index++;
    }
    return -1;
}

template<class T>
int SinglyList<T>::getIndexFromRear (T data) const
{
    if (this->head ==NULL )
    {
        return -1;
    }

    // Node<T>* current = this-> head;
    // int index = 0;
    // int rearINDEX = -1;

    // while (current)
    // {
    //     if (current->getData()== data)
    //     {
    //         rearINDEX=index;
    //         break;
    //     }

    //     current = current->next;
    //     index++;
    // }
    // return rearINDEX;
    Node<T>* current = this->head;
    int index = 0;
    int rearIndex = -1;
    int currentIndex = 0;

    while (current) 
    {
        if (current->getData() == data) 
        {
            rearIndex = currentIndex;
        }

        current = current->next;
        currentIndex++;
    }

    if (rearIndex == -1) 
    {
        return -1; // Data not found in the list.
    }
    else 
    {
        return currentIndex - rearIndex - 1;
    }
}

template<class T>
List<T>* SinglyList<T>::sort(bool order) const 
{

    // SinglyList<T>* clonedList = new SinglyList<T>();

    // Node<T>* current = this->head;

    // while (current)
    // {
    //     clonedList->insert(current->getData(), clonedList->size());
    //     current = current->next;
    // }
    
    // return clonedList;
    SinglyList<T>* sortedList = new SinglyList<T>();
    Node<T>* current = this->head;

    while (current) {
        Node<T>* toInsert = new Node<T>(current->getData());
        Node<T>* prev = NULL;
        Node<T>* currentSorted = sortedList->head;

        while (currentSorted) 
        {
            if ((order && toInsert->getData() < currentSorted->getData()) || (!order && toInsert->getData()> currentSorted->getData())) 
            {
                break;
            }
            prev = currentSorted;
            currentSorted = currentSorted->next;
        }

        if (!prev) 
        {
            // Insert at the beginning
            toInsert->next = sortedList->head;
            sortedList->head = toInsert;
        } 
        else 
        {
            // Insert in the middle or at the end
            prev->next = toInsert;
            toInsert->next = currentSorted;
        }

        current = current->next;

        if (!prev && toInsert != sortedList->head) 
        {
            delete toInsert;
            toInsert ==NULL;
        }
    }

    // //std::cout << sortedList <<std::endl;
    return sortedList;
}


template<class T>
Node<T>* SinglyList<T>:: findSmallest() const
{
    if (this->head ==NULL)
    {
        return NULL;
    }
    Node<T>* current = this->head;
    Node<T>* smallest = current;

    while (current)
    {
        if (current->getData()<smallest->getData())
        {
            smallest= current;
        }
        current = current->next;
    }
    return smallest;
}

template<class T>
Node<T>* SinglyList<T>:: findBiggest() const
{
    if (this->head==NULL)
    {
        return NULL;
    }
    Node<T>* current = this->head;
    Node<T>* biggest = current;

    while (current)
    {
        if (current->getData() > biggest->getData())
        {
            biggest= current;
        }
        current = current->next;
    }
    return biggest;
}

template<class T>
List<T>* SinglyList<T>::clone() const
{
    SinglyList<T>* clonedList = new SinglyList<T>();
    Node<T>* current = this->head;

    if (this->head ==NULL)
    {
        return clonedList;
    }
   
    while (current) 
    {
        clonedList->insert(current->getData(), clonedList->size());
        current = current->next;
    }

    return clonedList;
}








#endif /*SinglyList_CPP*/
