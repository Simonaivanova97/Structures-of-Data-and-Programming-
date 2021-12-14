//
//  Stack.hpp
//  Stack
//
//  Created by Simona Ivanova on 3.11.21.
//

#ifndef Stack_hpp
#define Stack_hpp

#include <stdio.h>
#include <iostream>
using namespace std;
const int MAX_SIZE=5;

template <typename T>
class Stack{
public:
    Stack();
    bool empty()const;
    void push(const T&);
    void pop();
    T top()const;
    void print()const;
    
private:
    T arr[MAX_SIZE];
    int indexCurrentElem;
    
    bool full()const;
};

template <typename T>
bool Stack<T>::full()const{
    return indexCurrentElem==MAX_SIZE-1;
}
template <typename T>
Stack<T>::Stack(){
    indexCurrentElem=-1;
}
template <typename T>
bool Stack<T>::empty()const{
    return indexCurrentElem==-1;
}
template <typename T>
void Stack<T>::push(const T& elem){
    if(!full()){
        indexCurrentElem++;
        arr[indexCurrentElem]=elem;
    }
    else{
        cout<<"Stack is full!"<<endl;
    }
}
template <typename T>
void Stack<T>::pop(){
    if(!empty()){
        indexCurrentElem--;
    }
    else{
        cout<<"Stack is empty!"<<endl;
    }
}
template <typename T>
T Stack<T>::top()const{
    return arr[indexCurrentElem];
}
template <typename T>
void Stack<T>::print()const{
    if(!empty()){
        for(int i=indexCurrentElem;i>=0;i--){
            cout<<arr[i]<<endl;
        }
    }
    else{
        cout<<"Stack is empty!"<<endl;
    }
}
#endif /* Stack_hpp */
