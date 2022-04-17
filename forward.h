//
// Created by ASUS on 16/04/2022.
//

#ifndef LIST_WITH_ITERATOR_FORWARD_H
#define LIST_WITH_ITERATOR_FORWARD_H

#include "list.h"
#include "iterator.h"
#include "node.h"

template <class T>
class ForwardListIterator : public Iterator<T> {
public:
    ForwardListIterator() : Iterator<T>() {};
    ForwardListIterator(Node<T> *current) : Iterator<T>(current) {};

    ForwardListIterator<T>& operator++()//++it
    {
        this->current = this->current->next;
        return *this;
    }

    ForwardListIterator<T>& operator++(int) //it++
    {
        Node<T>* temp = this->current;
        this->current = this->current->next;
        return ForwardListIterator<T>(temp);//mas memoria
    }

//    T operator*(){
//        return current->data;
//    }

    ForwardListIterator<T>& operator--()//++it
    {
        throw ("It's not implement");
    }
};

template <typename T>
class ForwardList : public List<T> {
public:
    typedef ForwardListIterator<T> iterator;

public:
    ForwardList() : List<T>() { }

    /* new functions */
    iterator begin() {
       return iterator(this->head);
    }

    iterator end() {
       return iterator(nullptr);
    }
    void push_front(T data) override{
       auto temp = new Node<T>(data);
       this->nodes++;
       if(this->head==nullptr){
           this->head=temp;
           this->tail=temp;
           return;
       }
       temp->next = this->head;
       this->head = temp;
    }
    virtual void push_back(T data){
       auto temp = new Node<T>(data);
       this->nodes++;
       if(this->head==nullptr){
           this->head=temp;
           this->tail=temp;
           return;
       }
       this->tail->next = temp;
       this->tail = temp;
    }
/*    virtual T pop_front() = 0;
    virtual T pop_back() = 0;
    virtual T insert(T, int) = 0;
    virtual bool remove(T) = 0;
    virtual T operator[](int) = 0;
    virtual bool find(T) = 0;
    virtual void sort() = 0;
    virtual bool is_sorted() = 0;
    virtual List<T>* reverse() = 0;
    virtual void display(std::ostream& os) = 0;
    virtual string name() = 0; */

    ~ForwardList() {
        if (this->head) {
            this->head->killSelf();
        }
    }

};



#endif //LIST_WITH_ITERATOR_FORWARD_H
