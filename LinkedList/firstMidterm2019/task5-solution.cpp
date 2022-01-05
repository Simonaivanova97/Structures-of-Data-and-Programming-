#include <iostream>
using namespace std;

template <typename T>
struct node{
    T inf;
    node<T>* link;
};

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

void removedups(node<int>*& start){
    if(start && start->link){
        node<int>* copyStart=start, *previousNode=NULL, *toDelete=NULL;
        while(copyStart->link){
            if(copyStart->inf==copyStart->link->inf){
                toDelete=copyStart;
                copyStart=copyStart->link;
                toDelete=NULL;
                delete toDelete;
                if(previousNode==NULL){
                    start=copyStart;
                }
                else{
                    previousNode->link=copyStart;
                }
            }
            else{
                previousNode=copyStart;
                copyStart=copyStart->link;
            }
        }
        copyStart=NULL;
        delete copyStart;
        previousNode=NULL;
        delete previousNode;
    }
}

int main() {

    node<int>* start=NULL, *first=NULL, *second=NULL, *thirth=NULL, *fourth=NULL, *fifth=NULL, *sixth=NULL;
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
    sixth=new node<int>;
    assert(sixth!=NULL);

    start->inf=1;
    start->link=first;
    first->inf=2;
    first->link=second;
    second->inf=3;
    second->link=thirth;
    thirth->inf=4;
    thirth->link=fourth;
    fourth->inf=7;
    fourth->link=fifth;
    fifth->inf=7;
    fifth->link=sixth;
    sixth->inf=7;
    sixth->link=NULL;
    
    cout<<"---Print list---"<<endl;
    print(start);
    
    cout<<"\n---Removedups---"<<endl;
    removedups(start);
    print(start);
    
    return 0;
}

