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

template <typename T>
void removesub(node<T>*& firstList, node<T>* secondList){
    if(firstList && secondList){
        node<T>* copyFirstList=firstList, *previousNode=NULL;
        while(copyFirstList){
            node<T>* tempList=copyFirstList, *copySecond=secondList;
            while(tempList && copySecond && tempList->inf==copySecond->inf){
                tempList=tempList->link;
                copySecond=copySecond->link;
            }
            if(copySecond){
                previousNode=copyFirstList;
                copyFirstList=copyFirstList->link;
            }
            else{
                node<T>* toDelete=NULL;
                while(copyFirstList!=tempList){
                    toDelete=copyFirstList;
                    copyFirstList=copyFirstList->link;
                    toDelete=NULL;
                    delete toDelete;
                }
                if(previousNode!=NULL){
                    previousNode->link=copyFirstList;
                }
                else{
                    firstList=copyFirstList;
                }
            }
            tempList=NULL;
            delete tempList;
            copySecond=NULL;
            delete copySecond;
        }
        copyFirstList=NULL;
        delete copyFirstList;
        previousNode=NULL;
        delete previousNode;
    }
}

int main() {

    node<int>* start=NULL, *first=NULL, *second=NULL, *thirth=NULL, *fourth=NULL, *fifth=NULL,
    *sixth=NULL, *seventh=NULL, *eighth=NULL, *nineth=NULL;
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
    seventh=new node<int>;
    assert(seventh!=NULL);
    eighth=new node<int>;
    assert(eighth!=NULL);
    nineth=new node<int>;
    assert(nineth!=NULL);

    start->inf=3;
    start->link=first;
    first->inf=3;
    first->link=second;
    second->inf=1;
    second->link=thirth;
    thirth->inf=2;
    thirth->link=fourth;
    fourth->inf=3;
    fourth->link=fifth;
    fifth->inf=4;
    fifth->link=sixth;
    sixth->inf=5;
    sixth->link=seventh;
    seventh->inf=3;
    seventh->link=eighth;
    eighth->inf=3;
    eighth->link=nineth;
    nineth->inf=6;
    nineth->link=NULL;
    
    node<int>* start2=NULL, *first2=NULL;
    start2=new node<int>;
    assert(start2!=NULL);
    first2=new node<int>;
    assert(first2!=NULL);
    
    start2->inf=3;
    start2->link=first2;
    first2->inf=3;
    first2->link=NULL;
    
    cout<<"---Print list---"<<endl;
    print(start);
    
    cout<<"\n---Remove sub---"<<endl;
    removesub(start, start2);
    print(start);
    
    
    return 0;
}

