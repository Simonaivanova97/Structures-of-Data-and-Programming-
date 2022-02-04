#include <iostream>
using namespace std;

template <typename T>
struct node{
    T inf;
    node<T>* link;
};

//Функция, която извежда елементите на списък с първи елемент start.
template <typename T>
void print(node<T>* start){
    if(start!=NULL){
        while(start){
            if(start->link){
                cout<<start->inf<<" -> ";
            }
            else{
                cout<<start->inf<<endl;
            }
            start=start->link;
        }
    }
    else{
        cout<<"Empty list!"<<endl;
    }
}

void fillgaps(node<int>*& start){
    if(start && start->link){
        node<int>* copyStart=start,*previousNode=copyStart,* newNode=NULL;
        while(copyStart->link){
            int a=copyStart->inf, b=copyStart->link->inf;
            if(b-a>1){
                node<int>* next=copyStart->link;
                for(int i=a+1;i<b;i++){
                    newNode=new node<int>;
                    assert(newNode!=NULL);
                    newNode->inf=i;
                    previousNode->link=newNode;
                    previousNode=newNode;
                }
                previousNode->link=next;
                copyStart=next;
                previousNode=copyStart;
            }
            else{
                copyStart=copyStart->link;
                previousNode=copyStart;
            }
        }
        delete newNode;
    }
}

int main(){
    node<int>* start=NULL, *first=NULL, *second=NULL, *thirth=NULL;
    start=new node<int>;
    assert(start!=NULL);
    first=new node<int>;
    assert(first!=NULL);
    second=new node<int>;
    assert(second!=NULL);
    thirth=new node<int>;
    assert(thirth!=NULL);

    start->inf=1;
    start->link=first;
    first->inf=2;
    first->link=second;
    second->inf=5;
    second->link=thirth;
    thirth->inf=7;
    thirth->link=NULL;

    cout<<"---Print list---"<<endl;
    print(start);
    
    cout<<"\n---Fillgaps---"<<endl;
    fillgaps(start);
    print(start);
    
    delete start, first, second, thirth;
    return 0;
}
