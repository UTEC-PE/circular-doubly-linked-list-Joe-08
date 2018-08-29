#ifndef LIST_H
#define LIST_H

#include <iostream>
#include "node.h"
#include "iterator.h"

using namespace std;

template <typename T>
class List {
    private:
        Node<T>* start;
        int nodos;

    public:
        List(){
            start = NULL;
            nodos = 0;
        }

        T front(){
            if (start == NULL){
                throw "Lista vacia";
            }
            return start->data;
        }
        T back(){
            return start->prev->data;
        }
        void push_front(T value){
            Node<T>* temp = new Node<T>;
            temp->data = value;
            nodos++;
            if (start == NULL){
                start = temp;
                start->next = start;
                start->prev = start;
            }else{
                temp->next = start;
                temp->prev = start->prev;
                start->prev->next = temp;
                start->prev = temp;
                start = temp;
            }
        }
        void push_back(T value){
            Node<T>* temp = new Node<T>;
            temp->data = value;
            nodos++;
            if (start == NULL){
                start = temp;
                start->next = start;
                start->prev = start;
            }else{
                temp->next = start;
                temp->prev = start->prev;
                start->prev->next = temp;
                start->prev = temp;
            }
        }
        void pop_front(){

        }
        void pop_back(){

        }
        T get(int position){

        }
        void concat(List<T> &other){
            start->prev = other->start;
        }
        bool empty(){
            return start == NULL;
        }
        int size(){
            return nodos;
        }
        void clear(){
            start->killSelf();
        }
        Iterator<T> begin(){

        }
        Iterator<T> end(){

        }

        ~List(){};
};

#endif