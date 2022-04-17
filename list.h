//
// Created by ASUS on 16/04/2022.
//

#ifndef LIST_WITH_ITERATOR_LIST_H
#define LIST_WITH_ITERATOR_LIST_H

#include <iostream>
#include "node.h"
using namespace std;

// TODO: Implement all methods
template <typename T>
class List {
protected:
    Node<T>* head;
    Node<T>* tail;
    int nodes;

public:
    List() : head(nullptr), tail(nullptr), nodes(0) {};
    ~List(){
        clear();
    } ;

    T front() {
        return head->data;
    }
    T back() {
        return tail->data;
    }
    bool empty() {
        return nodes==0;
    };
    int size() {
        return nodes;
    }
    void clear(){
        if (head) {
            head->killSelf();
        }
    }
    virtual void push_front(T) = 0;
    virtual void push_back(T) = 0;
/*    virtual T pop_front() = 0;
    virtual T pop_back() = 0;
    virtual T insert(T, int) = 0;
    virtual bool remove(T) = 0;
    virtual T operator[](int) = 0;
    virtual bool find(T) = 0;
    virtual void sort() = 0;
    virtual bool is_sorted() = 0;
    virtual List* reverse() = 0;
    virtual void display(std::ostream& os) = 0;
    virtual string name() = 0; */
};


#endif //LIST_WITH_ITERATOR_LIST_H
