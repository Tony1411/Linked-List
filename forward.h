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
    void push_back(T data) override{
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
    T pop_front() override{
       if(this->empty()){
           throw("No hay elementos");
       }
       this->nodes--;
       T data = this->head->data;
       if(this->head->next==nullptr){
           delete this->head;
           this->head = nullptr;
           this->tail = nullptr;
           return data;
       }
       auto temp = this->head;
       this->head=this->head->next;
       delete temp;
       return data;
    };
    T pop_back() override{
        if(this->empty()){
            throw("No hay elementos");
        }
        this->nodes--;
        T data = this->tail->data;
        if(this->head->next==nullptr){
            delete this->head;
            this->head = nullptr;
            this->tail = nullptr;
            return data;
        }
        auto it = this->head;
        while(it->next->next!=nullptr){
            it=it->next;
        }
        this->tail = it;
        delete this->tail->next;
        this->tail->next = nullptr;
        return data;
    }
    T insert(T data, int idx) override{
        if(idx>=this->size() || idx<0){
            throw("Operacion no realizada");
        }
        if(idx==0 || this->head==nullptr){
            push_front(data);
            return data;
        }
        auto temp = new Node<T>(data);
        auto it = this->head;
        this->nodes++;
        while(idx>1){
            it = it->next;
            idx--;
        }
        //       it
        // N1 -> N2 -> N3    temp
        // N1 -> N2 -> temp -> N3
        temp->next = it->next;
        it->next = temp;
        return data;
    }
    bool remove(T data) override{
        if(this->head==nullptr){
            throw("Operacion no realizada");
        }
        if(this->head->data==data) {
            this->pop_front();
            return true;
        }
        if(this->head==this->tail){
            return false;
        }
        auto it = this->head;
        while(it->next->data != data) {
            it = it->next;
            if(it->next==nullptr){
                return false;
            }
        }
        this->nodes--;
        auto it_2 = it->next;
        it->next = it_2->next;
        if(it_2->next != this->tail) {
            it_2->next->prev = it;
        }
        if(it_2 == this->tail){
            this->tail=it;
        }
        delete it_2;
        return true;
    }
    void reverse() override{
        if(this->head==nullptr){
            throw("La lista no tiene elementos");
        }
        if(this->head->next==nullptr){return;}
        Node<T>* prev = nullptr;
        Node<T>* next;
        Node<T>* current = this->head;
        this->tail = current;
        while(current != nullptr){
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        this->head = prev;
    }
    void display() override{
        for (auto ite1 = this->begin(); ite1 != this->end(); ++ite1) {
            cout << *ite1 << " ";
        }
        cout<<endl;
    }
    string name() override{
        string name = "Forward Linked List";
        return name;
    }

};



#endif //LIST_WITH_ITERATOR_FORWARD_H
