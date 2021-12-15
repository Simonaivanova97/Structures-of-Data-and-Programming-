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
bool sameList(node<T>* firtsList, node<T>* secondList){
    bool same=true;
    while(firtsList){
        if(!secondList){
            same=false;
            break;
        }
        else{
            if(firtsList->inf!=secondList->inf){
                same=false;
                break;
            }
        }
        firtsList=firtsList->link;
        secondList=secondList->link;
    }
    if(secondList){
        same=false;
    }
    return same;
}

template <typename T>
int countOccurence(node<T>* biggerList, node<T>* smallerList, int lenSmallerList){
    int count=0;
    while(biggerList){
        node<T>* copyBiggerList=biggerList, *tempList=NULL;
        int countLen=1;
        node<T>* prevN=NULL, *newNode=NULL;
        tempList=new node<T>;
        assert(tempList!=NULL);
        tempList->inf=copyBiggerList->inf;
        tempList->link=NULL;
        prevN=tempList;
        countLen++;
        copyBiggerList=copyBiggerList->link;
        while(countLen<=lenSmallerList && copyBiggerList){
            newNode=new node<T>;
            assert(newNode!=NULL);
            newNode->inf=copyBiggerList->inf;
            newNode->link=NULL;
            prevN->link=newNode;
            prevN=newNode;
            copyBiggerList=copyBiggerList->link;
            countLen++;
        }
        if(sameList(tempList, smallerList)){
            count++;
        }
        copyBiggerList=NULL;
        delete copyBiggerList;
        tempList=NULL;
        delete tempList;
        prevN=NULL;
        delete prevN;
        newNode=NULL;
        delete newNode;
        biggerList=biggerList->link;
    }
    return count;
}

template <typename T>
bool dupsub(node<T>* start, int k){
    if(k>0){
        while(start){
            node<T>* copyStart=start,*prevN=NULL, *newNode=NULL,*biggerList=start->link;
            int countLen=1;
            node<T>* smallerList=new node<T>;
            assert(smallerList!=NULL);
            smallerList->inf=copyStart->inf;
            smallerList->link=NULL;
            prevN=smallerList;
            countLen++;
            copyStart=copyStart->link;
            while(countLen<=k && copyStart){
                newNode=new node<T>;
                assert(newNode!=NULL);
                newNode->inf=copyStart->inf;
                newNode->link=NULL;
                prevN->link=newNode;
                prevN=newNode;
                countLen++;
                copyStart=copyStart->link;
            }
            if(countOccurence(biggerList, smallerList, k)>=1){
                return true;
                break;
            }
            smallerList=NULL;
            delete smallerList;
            biggerList=NULL;
            delete biggerList;
            copyStart=NULL;
            delete copyStart;
            prevN=NULL;
            delete prevN;
            newNode=NULL;
            delete newNode;
            start=start->link;
        }
    }
    else{
        cout<<"Invalid value for k!"<<endl;
    }
    return false;
}

int main() {

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

    start->inf=1;
    start->link=first;
    first->inf=2;
    first->link=second;
    second->inf=3;
    second->link=thirth;
    thirth->inf=3;
    thirth->link=fourth;
    fourth->inf=3;
    fourth->link=fifth;
    fifth->inf=4;
    fifth->link=NULL;
    
    cout<<"---Print list---"<<endl;
    print(start);
    
    if(dupsub(start,1)){
        cout<<"> Yes"<<endl;
    }
    else{
        cout<<"> No"<<endl;
    }
    
    return 0;
}
