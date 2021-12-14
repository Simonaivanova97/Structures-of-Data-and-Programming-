//
//  ResizingStack.hpp
//  Stack
//
//  Created by Simona Ivanova on 4.11.21.
//

#ifndef ResizingStack_hpp
#define ResizingStack_hpp

#include <stdio.h>
#include <iostream>
using namespace std;

template <typename T>
class ResizingStack{
public:
    ResizingStack();
    ResizingStack(int);
    ResizingStack(const ResizingStack&);
    ResizingStack& operator=(const ResizingStack&);
    ~ResizingStack();
    
    bool empty()const;
    void push(const T&);
    void pop();
    T top()const;
    void print()const;
    
private:
    T* arr;
    int maxSize;
    int indexCurrentElem;
    
    void copyResizingStack(const T*, int, int);
    bool full() const;
};

template <typename T>
void ResizingStack<T>::copyResizingStack(const T* a, int indexCurrent, int maxS){
    maxSize=maxS;
    arr=new T[maxSize];
    assert(arr!=NULL);
    indexCurrentElem=indexCurrent;
    for (int i=0;i<=indexCurrentElem;i++){
        arr[i]=a[i];
    }
}
template <typename T>
bool ResizingStack<T>::full() const{
    return indexCurrentElem==maxSize-1;
}
template <typename T>
ResizingStack<T>::ResizingStack(){
    indexCurrentElem=-1;
    maxSize=0;
    arr=NULL;
}
template <typename T>
ResizingStack<T>::ResizingStack(int maxS){
    indexCurrentElem=-1;
    maxSize=maxS;
    arr=new T[maxSize];
    assert(arr!=NULL);
}
template <typename T>
ResizingStack<T>::ResizingStack(const ResizingStack<T>& other){
    copyResizingStack(other.arr, other.indexCurrentElem, other.maxSize);
}
template <typename T>
ResizingStack<T>& ResizingStack<T>::operator=(const ResizingStack<T>& other){
    if(this!=&other){
        delete []arr;
        copyResizingStack(other.arr, other.indexCurrentElem, other.maxSize);
    }
    return *this;
}
template <typename T>
ResizingStack<T>::~ResizingStack(){
    delete []arr;
}
template <typename T>
bool ResizingStack<T>::empty()const{
    return indexCurrentElem==-1;
}
template <typename T>
void ResizingStack<T>::push(const T& elem){
    if(full()){
        //cout<<"We will resize stack"<<endl;
        T* copyArr=arr;
        maxSize*=2;
        arr=new T[maxSize];
        assert(arr!=NULL);
        for(int i=0;i<=indexCurrentElem;i++){
            arr[i]=copyArr[i];
        }
        indexCurrentElem++;
        arr[indexCurrentElem]=elem;
        delete []copyArr;
        copyArr=NULL;
    }
    else{
        indexCurrentElem++;
        arr[indexCurrentElem]=elem;
    }
}
template <typename T>
void ResizingStack<T>::pop(){
    if(empty()){
        cout<<"Stack is empty!"<<endl;
    }
    else{
        indexCurrentElem--;
    }
}
template <typename T>
T ResizingStack<T>::top()const{
    return arr[indexCurrentElem];
}
template <typename T>
void ResizingStack<T>::print()const{
    if(!empty()){
        for(int i=indexCurrentElem;i>=0;i--){
            cout<<arr[i]<<endl;
        }
    }
    else{
        cout<<"Stack is empty!"<<endl;
    }
}

#endif /* ResizingStack_hpp */
