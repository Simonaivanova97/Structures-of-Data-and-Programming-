//
//  LinkedStack.hpp
//  Stack
//
//  Created by Simona Ivanova on 4.11.21.
//

#ifndef LinkedStack_hpp
#define LinkedStack_hpp

#include <stdio.h>
#include <iostream>
using namespace std;

/*          --------------    --------------           --------------
   start->  | inf | link | -> | inf | link | -> ... -> | inf | NULL |
            --------------    --------------           --------------
 */

template <typename T>
struct node{
    T inf;
    node* link;
};

template <typename T>
class LinkedStack{
public:
    LinkedStack();
    LinkedStack(const LinkedStack&);
    LinkedStack& operator=(const LinkedStack&);
    ~LinkedStack();
    
    bool empty()const;
    void push(const T&);
    void pop();
    T top()const;
    void print()const;
    int length()const;
    
private:
    node<T>* start;
    
    void copyLinkedStack(const LinkedStack&);
    void deleteLinkedStack();
};

template <typename T>
void LinkedStack<T>::copyLinkedStack(const LinkedStack<T>& other){
    if(other.start){
        node<T>* copyOtherStart=other.start, *previousNode=NULL, *tempNode=NULL;
        start=new node<T>;
        assert(start!=NULL);
        start->inf=copyOtherStart->inf;
        start->link=previousNode;
        previousNode=start;
        copyOtherStart=copyOtherStart->link;
        while(copyOtherStart){
            tempNode=new node<T>;
            tempNode->inf=copyOtherStart->inf;
            tempNode->link=NULL;
            previousNode->link=tempNode;
            previousNode=tempNode;
            copyOtherStart=copyOtherStart->link;
        }
        copyOtherStart=NULL;
        previousNode=NULL;
        tempNode=NULL;
        delete copyOtherStart;
        delete previousNode;
        delete tempNode;
    }
    else{
        start=NULL;
    }
}
template <typename T>
void LinkedStack<T>::deleteLinkedStack(){
    node<T>* copyStart;
    while(start){
        copyStart=start;
        start=start->link;
        copyStart=NULL;
        delete copyStart;
    }
}
template <typename T>
LinkedStack<T>::LinkedStack(){
    start=NULL;
}
template <typename T>
LinkedStack<T>::LinkedStack(const LinkedStack<T>& other){
    copyLinkedStack(other);
}
template <typename T>
LinkedStack<T>& LinkedStack<T>::operator=(const LinkedStack<T>& other){
    if(this!=&other){
        deleteLinkedStack();
        copyLinkedStack(other);
    }
    return *this;
}
template <typename T>
LinkedStack<T>::~LinkedStack(){
    deleteLinkedStack();
}
template <typename T>
bool LinkedStack<T>::empty()const{
    return start==NULL;
}
template <typename T>
void LinkedStack<T>::push(const T& elem){
    node<T>* copyStart=start;
    start=new node<T>;
    assert(start!=NULL);
    start->inf=elem;
    start->link=copyStart;
    copyStart=NULL;
    delete copyStart;
}
template <typename T>
void LinkedStack<T>::pop(){
    if(empty()){
        cout<<"Stack is empty!"<<endl;
    }
    else{
        node<T>* copyStart=start;
        start=start->link;
        copyStart=NULL;
        delete copyStart;
    }
}
template <typename T>
T LinkedStack<T>::top()const{
    if(!empty()){
        return start->inf;
    }
    else{
        return -1;
    }
}
template <typename T>
void LinkedStack<T>::print()const{
    if(empty()){
        cout<<"Stack is empty!"<<endl;
    }
    else{
        node<T>* copyStart=start;
        while(copyStart){
            cout<<copyStart->inf<<endl;
            copyStart=copyStart->link;
        }
    }
}
template <typename T>
int LinkedStack<T>::length()const{
    node<T>* copyStart=start;
    int count=0;
    while(copyStart){
        copyStart=copyStart->link;
        count++;
    }
    delete copyStart;
    return count;
}

#endif /* LinkedStack_hpp */
