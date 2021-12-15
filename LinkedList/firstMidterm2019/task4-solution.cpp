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

template <typename T>
node<T>* reverseList(node<T>* start){
    node<T>* reverseStart=NULL,*previousNode=NULL;
    while(start){
        reverseStart=new node<T>;
        assert(reverseStart!=NULL);
        reverseStart->inf=start->inf;
        reverseStart->link=previousNode;
        previousNode=reverseStart;
        start=start->link;
    }
    previousNode=NULL;
    delete previousNode;
    return reverseStart;
}

template <typename T>
void mirror(node<T>*& start){
    node<T>* copyStart=start, *reverseStart=reverseList(start);
    if(copyStart){
        while(copyStart->link){
            copyStart=copyStart->link;
        }
        copyStart->link=reverseStart;
    }
}

int main(){
    node<int>* start=NULL, *first=NULL, *second=NULL, *thirth=NULL, *fourth=NULL, *fifth=NULL;
    start=new node<int>;
    assert(start!=NULL);
    first=new node<int>;
    assert(first!=NULL);
    second=new node<int>;
    assert(second!=NULL);
    thirth=new node<int>;
    assert(thirth!=NULL);
    fourth=new node<int>;
    assert(fourth!=NULL);
    fifth=new node<int>;
    assert(fifth!=NULL);
    
    start->inf=4;
    start->link=first;
    first->inf=4;
    first->link=second;
    second->inf=10;
    second->link=thirth;
    thirth->inf=1;
    thirth->link=fourth;
    fourth->inf=1;
    fourth->link=fifth;
    fifth->inf=0;
    fifth->link=NULL;
    
    cout<<"---Print list---"<<endl;
    print(start);
    //cout<<"\n---Reverse list---"<<endl;
    //print(reverseList(start));
    cout<<"\n---Mirror---"<<endl;
    mirror(start);
    print(start);
    return 0;
}
