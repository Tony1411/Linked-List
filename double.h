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
        this->head->prev = temp;
        temp->next = this->head;
//        temp->prev = nullptr;
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
        temp->prev = this->tail;
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
        this->head = this->head->next;
        this->head->prev = nullptr;
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
        auto temp = this->tail;
        this->tail = this->tail->prev;
        this->tail->next = nullptr;
        delete temp;
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
        temp->prev = it;
        temp->next = it->next;
        it->next->prev = temp;
        it->next = temp;
        return data;
    }
    bool remove(T data) override{
        if(this->head==nullptr){
            throw("Operacion no realizada");
        }
        if(this->head->data==data){
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
        it_2->next->prev = it;
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
            current->prev = next;
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
        for (auto ite2 = this->tail; ite2 != nullptr; ite2=ite2->prev) {
            cout << ite2->data << " ";
        }
        cout<<endl;
    }
    string name() override{
        string name = "Doubly Linked List";
        return name;
    }
};


#endif //LIST_WITH_ITERATOR_DOUBLE_H
