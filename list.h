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
    }

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
        while(head!=tail){
            auto it = head;
            head=head->next;
            delete it;
        }
        delete head;
        head=nullptr;
        tail=nullptr;
        nodes=0;
    }
    T operator[](int idx){
        auto it = head;
        while(idx>0){
            it = it->next;
            idx--;
        }
        return it->data;
    }
    bool find(T data){
        for(auto it=head;it!=nullptr;it=it->next){
            if(it->data==data){
                return true;
            }
        }
        return false;
    }
    void sort(){
        for(auto it_1=this->head;it_1->next!=nullptr;it_1=it_1->next){
            for(auto it_2=it_1->next;it_2!=nullptr;it_2=it_2->next){
                if(it_1->data > it_2->data){
                    auto temp = it_1->data;
                    it_1->data = it_2->data;
                    it_2->data = temp;
                }
            }
        }
    }
    bool is_sorted(){
        for(auto it=this->head;it->next!=nullptr;it=it->next) {
            if (it->data > it->next->data) {
                return false;
            }
        }
        return true;
    }
    virtual void push_front(T) = 0;
    virtual void push_back(T) = 0;
    virtual T pop_front() = 0;
    virtual T pop_back() = 0;
    virtual T insert(T, int) = 0;
    virtual bool remove(T) = 0;
    virtual void reverse() = 0;
    virtual void display() = 0;
    virtual string name() = 0;
};


#endif //LIST_WITH_ITERATOR_LIST_H
