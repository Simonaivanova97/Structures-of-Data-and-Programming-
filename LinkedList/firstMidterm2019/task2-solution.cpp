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

//Фунцкия, която намира дължината на списък.
template <typename T>
int length(node<T>* start){
    int len=0;
    while(start){
        len++;
        start=start->link;
    }
    return len;
}

void removeIdx(node<int>*& start){
    if(start){
        int len=length(start);
        int countElem=1;
        node<int>* toDelete=NULL;
        while(start && start->inf==len-countElem){
            toDelete=start;
            start=start->link;
            toDelete=NULL;
            delete toDelete;
            countElem++;
        }
        if(start){
            countElem++;
            node<int>* previousNode=start, * copyStart=start->link;
            while(copyStart){
                if(copyStart->inf==len-countElem){
                    toDelete=copyStart;
                    previousNode->link=toDelete->link;
                    copyStart=previousNode->link;
                    countElem++;
                    toDelete=NULL;
                    delete toDelete;
                }
                else{
                    previousNode=copyStart;
                    copyStart=copyStart->link;
                    countElem++;
                }
            }
            delete copyStart;
            previousNode=NULL;
            delete previousNode;
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
    
    cout<<"\nLength of list is "<<length(start)<<endl;
    
    cout<<"\n---Remove index---"<<endl;
    removeIdx(start);
    print(start);
    return 0;
}
