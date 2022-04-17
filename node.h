//
// Created by ASUS on 16/04/2022.
//

#ifndef LIST_WITH_ITERATOR_NODE_H
#define LIST_WITH_ITERATOR_NODE_H

template <typename T>
struct Node {
    T data;
    Node<T>* next;
    Node<T>* prev;
    Node(T data) : data(data) {
        next = prev = nullptr;
    };
    void killSelf();
};

template <typename T>
void Node<T>::killSelf() {
    if (next) {
        next->killSelf();
    }
    delete this;
}


#endif //LIST_WITH_ITERATOR_NODE_H
