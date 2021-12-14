//
//  LinkedList.hpp
//  LinkedList
//
//  Created by Simona Ivanova on 11.12.21.
//

#ifndef LinkedList_hpp
#define LinkedList_hpp

#include <stdio.h>
#include <iostream>
using namespace std;

/*
             ______________    ______________            ______________    ______________
   start---> | inf | link |--> | inf | link |--> ... --> | inf | link |--> | inf | NULL |
             --------------    --------------            --------------  / --------------
                                                                        /
                                                                        end
 */

template <typename T>
struct node{
    T inf;
    node<T>* link;
};

template <typename T>
class LinkedList{
public:
    LinkedList();
    LinkedList(node<T>*, node<T>*);
    LinkedList(const LinkedList<T>&);
    LinkedList<T>& operator=(const LinkedList<T>&);
    ~LinkedList();
    
    //Проверка дали списъкът е празен
    bool empty() const;
    //Добавя елемент в края на списъка
    void toEnd(const T&);
    //Добавя елемент, след елемента сочен от указателя
    void insertAfter(node<T>*, const T&);
    //Добавя елемент, преди елемента сочен от указателя
    void insertBefore(node<T>*, const T&);
    //Изтрива елемента, след елемента сочен от указателя
    void deleteAfter(node<T>*);
    //Изтрива елемент, преди елемента сочен от указателя
    void deleteBefore(node<T>*);
    //Изтрива елемент, сочен от указателя
    void deleteElem(node<T>*);
    
    //Извежда съдържанието на списъка
    void print() const;
    //Намира дължината на списъка
    int length() const;
    //Конкатенация на неявния с указания като формален параметър линеен списък
    void concat(const LinkedList<T>&);
    //Обръща елементите на списъка
    void reverse();
    
private:
    node<T>* start, *end;
    
    void copyLinkedList(const LinkedList<T>&);
    void deleteLinkedList();
    
};

template <typename T>
void LinkedList<T>::copyLinkedList(const LinkedList<T>& other){
    if(other.start){
        node<T>* copyOtherStart=other.start,*previousNode=NULL;
        start=new node<T>;
        assert(start!=NULL);
        start->inf=copyOtherStart->inf;
        start->link=previousNode;
        end=start;
        previousNode=start;
        copyOtherStart=copyOtherStart->link;
        while(copyOtherStart){
            end=new node<T>;
            assert(end!=NULL);
            end->inf=copyOtherStart->inf;
            end->link=NULL;
            previousNode->link=end;
            previousNode=end;
            copyOtherStart=copyOtherStart->link;
        }
        delete copyOtherStart;
        previousNode=NULL;
        delete previousNode;
    }
    else{
        start=NULL;
        end=NULL;
    }
}

template <typename T>
void LinkedList<T>::deleteLinkedList(){
    node<T>* tempNode=NULL;
    while(start){
        tempNode=start;
        start=start->link;
        tempNode=NULL;
        delete tempNode;
    }
    end=NULL;
}

template <typename T>
LinkedList<T>::LinkedList(){
    start=NULL;
    end=NULL;
}

template <typename T>
LinkedList<T>::LinkedList(node<T>* st,node<T>* en){
    start=st;
    end=en;
}

template <typename T>
LinkedList<T>::LinkedList(const LinkedList<T>& other){
    copyLinkedList(other);
}

template <typename T>
LinkedList<T>& LinkedList<T>::operator=(const LinkedList<T>& other){
    if(this!=&other){
        deleteLinkedList();
        copyLinkedList(other);
    }
    return *this;
}

template <typename T>
LinkedList<T>::~LinkedList(){
    deleteLinkedList();
}

template <typename T>
bool LinkedList<T>::empty() const{
    return start==NULL;
}

template <typename T>
void LinkedList<T>::toEnd(const T& elem){
    node<T>* newEnd=new node<T>;
    assert(newEnd!=NULL);
    newEnd->inf=elem;
    newEnd->link=NULL;
    if(!empty()){
        end->link=newEnd;
        end=newEnd;
    }
    else{
        start=newEnd;
        end=start;
    }
    newEnd=NULL;
    delete newEnd;
}

template <typename T>
void LinkedList<T>::insertAfter(node<T>* p, const T& elem){
    node<T>* newNode=new node<T>;
    assert(newNode!=NULL);
    newNode->inf=elem;
    newNode->link=p->link;
    p->link=newNode;
    if(p==end){
        end=newNode;
    }
    newNode=NULL;
    delete newNode;
}

template <typename T>
void LinkedList<T>::insertBefore(node<T>* p, const T& elem){
    node<T>* newNode=new node<T>;
    assert(newNode!=NULL);
    newNode->inf=elem;
    newNode->link=p;
    node<T>* copyStart=start;
    if(p==start){
        start=newNode;
    }
    else{
        while(copyStart->link!=p){
            copyStart=copyStart->link;
        }
        copyStart->link=newNode;
    }
    newNode=NULL;
    delete newNode;
    copyStart=NULL;
    delete copyStart;
}

template <typename T>
void LinkedList<T>::deleteAfter(node<T>* p){
    if(p==end){
        cout<<"Invalid operation!"<<endl;
    }
    else{
        node<T>* toDelete=p->link;
        p->link=toDelete->link;
        if(toDelete==end){
            end=p;
        }
        toDelete=NULL;
        delete toDelete;
    }
}

template <typename T>
void LinkedList<T>::deleteBefore(node<T>* p){
    if(p==start){
        cout<<"Invalid operation!"<<endl;
    }
    else{
        node<T>* toDelete=NULL;
        if(start->link==p){
            //node<T>* toDelete=NULL;
            toDelete=start;
            start=start->link;
            toDelete=NULL;
            delete toDelete;
        }
        else{
            node<T>* copyStart=start;
            while(copyStart->link!=p){
                copyStart=copyStart->link;
            }
            toDelete=copyStart;
            *copyStart=*copyStart->link;
            toDelete=NULL;
            delete toDelete;
        }
    }
}

template <typename T>
void LinkedList<T>::deleteElem(node<T>* p){
    if(p==start){
        node<T>* toDelete=start;
        start=start->link;
        toDelete=NULL;
        delete toDelete;
    }
    else{
        node<T>* copyStart=start;
        while(copyStart->link!=p){
            copyStart=copyStart->link;
        }
        copyStart->link=p->link;
        if(p==end){
            end=copyStart;
        }
        p=NULL;
        delete p;
        copyStart=NULL;
        delete copyStart;
    }
}

template <typename T>
void LinkedList<T>::print() const{
    if(!empty()){
        node<T>* copyStart=start;
        while(copyStart){
            if(copyStart->link){
                cout<<copyStart->inf<<" -> ";
            }
            else{
                cout<<copyStart->inf<<endl;
            }
            copyStart=copyStart->link;
        }
        delete copyStart;
    }
    else{
        cout<<"Empty list!"<<endl;
    }
}

template <typename T>
int LinkedList<T>::length() const{
    int len=0;
    node<T>* copyStart=start;
    while(copyStart){
        len++;
        copyStart=copyStart->link;
    }
    delete copyStart;
    return len;
}

template <typename T>
void LinkedList<T>::concat(const LinkedList<T>& other){
    if(other.start){
        node<T>* copyOtherStart=other.start;
        while(copyOtherStart){
            toEnd(copyOtherStart->inf);
            copyOtherStart=copyOtherStart->link;
        }
        delete copyOtherStart;
    }
}

template <typename T>
void LinkedList<T>::reverse(){
    if(!empty() && start!=end){
        node<T>* copyStart=start,*previousNode=NULL;
        end=new node<T>;
        assert(end!=NULL);
        end->inf=copyStart->inf;
        end->link=NULL;
        previousNode=end;
        copyStart=copyStart->link;
        while(copyStart){
            start=new node<T>;
            assert(start!=NULL);
            start->inf=copyStart->inf;
            start->link=previousNode;
            previousNode=start;
            copyStart=copyStart->link;
        }
        delete copyStart;
        previousNode=NULL;
        delete previousNode;
    }
}

#endif /* LinkedList_hpp */
