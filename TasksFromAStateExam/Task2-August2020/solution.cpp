#include <iostream>
#include <string>
using namespace std;

struct node{
    string inf;
    node* link;
};

void printCyclicList(node* start){
    if(start){
        node* copyStart=start;
        while(copyStart->link!=start){
            cout<<copyStart->inf<<" -> ";
            copyStart=copyStart->link;
        }
        cout<<copyStart->inf<<endl;
    }
    else{
        cout<<"Empty list!"<<endl;
    }
}

node* readCyclicList(){
    node* start=NULL, *previousNode=NULL, *newNode=NULL;
    char answer[1];
    cout<<"Enter node? Y or N ";
    cin>>answer;
    if(strcmp(answer,"Y")==0){
        start=new node;
        assert(start!=NULL);
        cout<<"Enter start->inf: ";
        cin>>start->inf;
        previousNode=start;
        do{
            cout<<"Enter node again? Y or N ";
            cin>>answer;
            if(strcmp(answer, "Y")==0){
                newNode=new node;
                assert(newNode!=NULL);
                cout<<"Enter newNode->inf: ";
                cin>>newNode->inf;
                previousNode->link=newNode;
                previousNode=newNode;
            }
        }while(strcmp(answer,"N")!=0);
        previousNode->link=start;
    }
    newNode=NULL;
    delete newNode;
    previousNode=NULL;
    delete previousNode;
    return start;
}

int countWords(string s){
    int count=1,i=0;
    while(s[i]){
        if(s[i]=='-'){
            count++;
        }
        i++;
    }
    return count;
}

void lexicographicSmallestOrder(node*& start){
    if(start && start->link!=start){
        node* copyStart=start;
        while(copyStart->link!=start){
            int minWords=countWords(copyStart->inf);
            string min=copyStart->inf;
            node* pointerToMin=copyStart;
            node* next=copyStart->link;
            while(next->link!=start){
                if(countWords(next->inf)<minWords){
                    min=next->inf;
                    minWords=countWords(next->inf);
                    pointerToMin=next;
                }
                else if(countWords(next->inf)==minWords){
                    if(next->inf<min){
                        min=next->inf;
                        pointerToMin=next;
                    }
                }
                next=next->link;
            }
            if(countWords(next->inf)<minWords){
                min=next->inf;
                minWords=countWords(next->inf);
                pointerToMin=next;
            }
            else if(countWords(next->inf)==minWords){
                if(next->inf<min){
                    min=next->inf;
                    pointerToMin=next;
                }
            }
            if(copyStart!=pointerToMin){
                string temp=copyStart->inf;
                copyStart->inf=min;
                pointerToMin->inf=temp;
            }
            copyStart=copyStart->link;
            next=NULL;
            delete next;
            pointerToMin=NULL;
            delete pointerToMin;
        }
        copyStart=NULL;
        delete copyStart;
    }
}

void unite(node*& start){
    if(start && start->link!=start){
        node* copyStart=start;
        while(copyStart->link!=start){
            if(copyStart->inf[copyStart->inf.length()-1] == copyStart->link->inf[0]){
                copyStart->inf+=" - ";
                copyStart->inf+=copyStart->link->inf;
                node* toDelete=copyStart->link;
                copyStart->link=toDelete->link;
                toDelete=NULL;
                delete toDelete;
            }
            else{
                copyStart=copyStart->link;
            }
        }
        if(copyStart->inf[copyStart->inf.length()-1] == start->inf[0]){
            copyStart->inf+=" - ";
            copyStart->inf+=start->inf;
            node* toDelete=start;
            copyStart->link=toDelete->link;
            toDelete=NULL;
            delete toDelete;
            start=copyStart;
        }
        copyStart=NULL;
        delete copyStart;
        lexicographicSmallestOrder(start);
    }
}

int main(){
    node* start=readCyclicList();
    cout<<"\n-----Print cyclic list ---"<<endl;
    printCyclicList(start);
    cout<<"\n-----Print cyclic list after unite ---"<<endl;
    unite(start);
    printCyclicList(start);
    return 0;
}
