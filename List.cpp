#ifndef LIST_CPP
#define LIST_CPP

#include "List.h"

template<class T>
List<T>::List()
{
    this->head = NULL;
}

template<class T>
List<T>::~List()
{/*empty as the derived class will be do the deallocating (check polymorphism)*/}

template<class T>
int List<T>::size() const
{
    Node<T>* current = head; //create a variable and copy head so head doesnt change
    int count=0;

    if (head == NULL)
    {
        return 0;
    }

    while (current!=NULL)
    {
        count++;
        current = current->next;
    }

    return count;
}


template<class T>
bool List<T>::contains(T data) const
{
    if(head == NULL)
    {
        return false;
    }
    
    Node<T>* current = head;

    while (current)
    {
        if (current->getData() == data)
        {
            return true;
        }
        current = current->next;
    }
    return false;
}

#endif