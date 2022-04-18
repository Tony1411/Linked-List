//
// Created by ASUS on 16/04/2022.
//

#ifndef LIST_WITH_ITERATOR_ITERATOR_H
#define LIST_WITH_ITERATOR_ITERATOR_H

#include "node.h"

template <typename T>
class Iterator {
protected:
    Node<T>* current;

public:
    Iterator() : current(nullptr) {};

    Iterator(Node<T>* current) : current(current) {};

    Iterator<T>& operator=(Iterator<T> other){
        this->current = other.current;
        return *this;
    }

    bool operator!=(Iterator<T> other){
        return this->current!=other.current;
    }

    T operator*(){
        return current->data;
    }

    Node<T>* operator->(){
        return current;
    }
};


#endif //LIST_WITH_ITERATOR_ITERATOR_H
