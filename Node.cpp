#ifndef NODE_CPP
#define NODE_CPP

#include "Node.h"

template <class T>
Node<T>::Node(T data)
{
    this->data = data;
    this-> next = NULL;
}

template <class T>
T Node<T>::getData() const
{
    return data;
}

template <class T>
bool Node<T>::operator==(T other) const
{
    // if (*this == &other)
    // {
    //     return true;
    // }
    
    // return false;
    return data == other;
}


#endif /*NODE_CPP*/