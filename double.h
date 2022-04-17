//
// Created by ASUS on 16/04/2022.
//

#ifndef LIST_WITH_ITERATOR_DOUBLE_H
#define LIST_WITH_ITERATOR_DOUBLE_H

#include "list.h"
#include "iterator.h"

template <typename T>
class DoubleListIterator : public Iterator<T> {
public:
    DoubleListIterator() : Iterator<T>() {};
    DoubleListIterator(Node<T> *current) : Iterator<T>(current) {};
    DoubleListIterator<T>& operator++(){
        this->current = this->current->next;
        return *this;
    }//++it
    DoubleListIterator<T>& operator--(){
        this->current = this->current->prev;
        return *this;
    }//--it
};

template <typename T>
class DoubleList : public List<T>{
public:
    typedef DoubleListIterator<T> iterator;

public:
    DoubleList() : List<T>() { }

    /* new functions */
    iterator begin() {
        // TODO
        return iterator(this->head);
    }

    iterator end() {
        // TODO
        return iterator(this->tail);
    }

    ~DoubleList() {
        if (this->head) {
            this->head->killSelf();
        }
    }
};


#endif //LIST_WITH_ITERATOR_DOUBLE_H
