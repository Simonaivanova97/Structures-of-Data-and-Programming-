#include <iostream>
#include <string>
using namespace std;

template <typename T>
struct Node{
    T data;
    Node* next;
};

template <typename T>
void print(Node<T>* start){
    if(start){
        while(start){
            if(start->next){
                cout<<start->data<<" -> ";
            }
            else{
                cout<<start->data<<" ";
            }
            start=start->next;
        }
    }
    else{
        cout<<"Empty list!"<<endl;
    }
}

double sum(const double& x, const double& y){
    return x+y;
}

double div(const double& x, const double& y){
    return x/y;
}
string concatStr(const string& x, const string& y){
    return x+y;
}

template <typename T>
T reduce(Node<T>* start, T (*f)(const T&, const T&)){
    if(!start){
        cout<<"Empty list!"<<endl;
        return NULL;
    }
    else if(start && !start->next){
        return start->data;
    }
    else{
        T result=start->data;
        start=start->next;
        while(start){
            result=(*f)(result, start->data);
            //cout<<"Result "<<result<<endl;
            start=start->next;
        }
        return result;
    }
}

template <typename T>
void deleteList(Node<T>*& start){
    Node<T>* toDelete=NULL;
    while(start){
        toDelete=start;
        start=start->next;
        delete toDelete;
    }
}

int main(){
    
    Node<double>* start=NULL, *first=NULL, *second=NULL, *thirth=NULL;
    start=new Node<double>;
    assert(start!=NULL);
    first=new Node<double>;
    assert(first!=NULL);
    second=new Node<double>;
    assert(second!=NULL);
    thirth=new Node<double>;
    assert(thirth!=NULL);
    
    start->data=1;
    start->next=first;
    first->data=2;
    first->next=second;
    second->data=3;
    second->next=thirth;
    thirth->data=4;
    thirth->next=NULL;
    
    Node<string>* start2=NULL, *first2=NULL, *second2=NULL, *thirth2=NULL, *fourth2=NULL, *fifth2=NULL;
    start2=new Node<string>;
    assert(start2!=NULL);
    first2=new Node<string>;
    assert(first2!=NULL);
    second2=new Node<string>;
    assert(second2!=NULL);
    thirth2=new Node<string>;
    assert(thirth2!=NULL);
    fourth2=new Node<string>;
    assert(fourth2!=NULL);
    fifth2=new Node<string>;
    assert(fifth2!=NULL);
    
    start2->data='S';
    start2->next=first2;
    first2->data='i';
    first2->next=second2;
    second2->data='m';
    second2->next=thirth2;
    thirth2->data='o';
    thirth2->next=fourth2;
    fourth2->data='n';
    fourth2->next=fifth2;
    fifth2->data='a';
    fifth2->next=NULL;
    
    cout<<"Apply function sum of list: ";
    print(start);
    cout<<" and result is: "<<reduce(start,&sum)<<endl;
    
    cout<<"Apply function div of list: ";
    print(start);
    cout<<" and result is: "<<reduce(start,&div)<<endl;
    
    cout<<"Apply function concat of list: ";
    print(start2);
    cout<<" and result is: "<<reduce(start2, &concatStr)<<endl;
    
    deleteList(start);
    deleteList(start2);
    return 0;
}

