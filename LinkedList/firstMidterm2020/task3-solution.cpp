#include <iostream>
using namespace std;

template <typename T>
struct Node{
    T data;
    Node* next;
};

template <typename T>
int lenOfList(Node<T>* start){
    int countElem=0;
    while(start){
        countElem++;
        start=start->next;
    }
    return countElem;
}

template <typename T>
void shuffle(Node<T>*& start){
    if(start && start->next){
        int indexLastElemFirstPart;
        if(lenOfList(start)%2==0){
            indexLastElemFirstPart=lenOfList(start)/2;
        }
        else{
            indexLastElemFirstPart=lenOfList(start)/2+1;
        }
        Node<T>* copyStar=start;
        int currentIndex=1;
        while(currentIndex<indexLastElemFirstPart){
            copyStar=copyStar->next;
            currentIndex++;
        }
        Node<T>* tempStart=copyStar->next;
        copyStar->next=NULL;
        copyStar=tempStart;
        while(copyStar){
            tempStart=copyStar;
            copyStar=copyStar->next;
            tempStart->next=start;
            start=tempStart;
        }
        copyStar=NULL;
        delete copyStar;
        tempStart=NULL;
        delete tempStart;
    }
}

template <typename T>
void print(Node<T>* start){
    if(start){
        while(start){
            if(start->next){
                cout<<start->data<<" -> ";
            }
            else{
                cout<<start->data<<endl;
            }
            start=start->next;
        }
    }
    else{
        cout<<"Empty list!"<<endl;
    }
}
int main(){
    
    Node<int>* start=NULL, *first=NULL, *second=NULL, *thirth=NULL, *fourth=NULL;
    start=new Node<int>;
    first=new Node<int>;
    second=new Node<int>;
    thirth=new Node<int>;
    fourth=new Node<int>;
    
    start->data=1;
    start->next=first;
    first->data=2;
    first->next=second;
    second->data=3;
    second->next=thirth;
    thirth->data=4;
    thirth->next=fourth;
    fourth->data=5;
    fourth->next=NULL;
    
    print(start);
    cout<<"\n---After shuffle---"<<endl;
    shuffle(start);
    print(start);
    return 0;
}
