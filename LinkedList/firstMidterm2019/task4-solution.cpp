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
    node<T>* startRev=NULL;
    if(start && start->link){
        node<T>* previousNode=NULL;
        startRev=new node<T>;
        assert(startRev!=NULL);
        startRev->inf=start->inf;
        startRev->link=NULL;
        previousNode=startRev;
        start=start->link;
        while(start){
            startRev=new node<T>;
            assert(startRev!=NULL);
            startRev->inf=start->inf;
            startRev->link=previousNode;
            previousNode=startRev;
            start=start->link;
        }
        previousNode=NULL;
        delete previousNode;
    }
    else{
        startRev=start;
    }
    return startRev;
}

template <typename T>
void mirror(node<T>*& start){
    if(start){
        node<T>* revStart=reverseList(start);
        if(start->link){
            node<T>* copyStart=start, *previousNode=NULL,* newNode=NULL;
            while(copyStart->link){
                copyStart=copyStart->link;
            }
            previousNode=copyStart;
            while(revStart){
                newNode=new node<T>;
                assert(newNode!=NULL);
                newNode->inf=revStart->inf;
                newNode->link=NULL;
                previousNode->link=newNode;
                previousNode=newNode;
                revStart=revStart->link;
            }
            delete revStart;
            copyStart=NULL;
            delete copyStart;
            previousNode=NULL;
            delete previousNode;
            newNode=NULL;
            delete newNode;
        }
        else{
            start->link=new node<T>;
            start->link->inf=revStart->inf;
            start->link->link=NULL;
        }
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
