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
            if (start == NULL){
                throw "Lista vacia";
            }
            else{
                Node<T> *temp = start;
                start -> prev -> next = start -> next;
                start -> next -> prev = start -> prev;
                start = start -> next;
                nodos--;
                delete temp;
            }
        }
        void pop_back(){
            Node<T> *temp = start->prev;
            if (nodos == 1){
                start = NULL;
                temp->killSelf();
            }
            else{
                start->prev = temp->prev;
                temp->killSelf();
                nodos--;
            }
        }
        T get(int position){
            if (position >= nodos || position < 0){
                throw "fuera de rango";
            }else{
                Node<T> *temp = start;
                for (int i = 0; i < nodos; i++){
                    if ( i == position){
                        return temp->data;
                    }
                    temp = temp->next;
                }
            }
        }
        void concat(List<T> &other){
            start->prev->next = other->start;
            other.start->prev =start->prev;
        }
        bool empty(){
            return start == NULL;
        }
        int size(){
            return nodos;
        }
        void clear(){
            Node<T> *temp = start->next;
            while(temp != start){
                Node<T> *temp2 = temp;
                temp = temp->next;
                temp2->killSelf();
            }
            start = NULL;
            delete temp;
            nodos = 0;
        }
        Iterator<T> begin(){
            if(start == NULL){
                throw "Lista vacia";
            }
            Iterator<T> it(start);
            return it; 
        }
        Iterator<T> end(){
            if(start == NULL){
                throw "Lista vacia";
            }
            Iterator<T> ite(start->prev);
            return ite;
        }

        ~List(){};
};

#endif
