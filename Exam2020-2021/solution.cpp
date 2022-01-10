#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
};

int lenOfList(Node* start){
    int count=0;
    while(start){
        count++;
        start=start->next;
    }
    return count;
}

void print(Node* start){
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

int countDigit(int number){
    int count=0;
    if(number==0){
        count=1;
    }
    else{
        while(number>0){
            count++;
            number/=10;
        }
    }
    return count;
}

void inc(Node*& start){
    int count=0, lengthList=lenOfList(start);
    int firstNumber=0, secondNumber=0, degree=lengthList/2-1;
    while(start){
        if(count<=lengthList/2-1){
            firstNumber+=start->data*pow(10, degree);
            if(count==lengthList/2-1){
                degree=lengthList/2-1;
            }
            else{
                degree--;
            }
        }
        else{
            secondNumber+=start->data*pow(10,degree);
            degree--;
        }
        start=start->next;
        count++;
    }
    firstNumber--;
    secondNumber++;
    Node* previousNode=NULL, *newNode=NULL;
    start=new Node;
    assert(start!=NULL);
    degree=countDigit(firstNumber)-1;
    start->data=firstNumber/pow(10,degree);
    start->next=previousNode;
    previousNode=start;
    int rest=pow(10,degree);
    firstNumber=firstNumber%rest;
    degree--;
    while(degree>=0){
        newNode=new Node;
        assert(newNode!=NULL);
        newNode->data=firstNumber/pow(10,degree);
        previousNode->next=newNode;
        previousNode=newNode;
        rest=pow(10,degree);
        firstNumber=firstNumber%rest;
        degree--;
    }
    degree=countDigit(secondNumber)-1;
    while(degree>=0){
        newNode=new Node;
        assert(newNode!=NULL);
        newNode->data=secondNumber/pow(10,degree);
        previousNode->next=newNode;
        previousNode=newNode;
        rest=pow(10,degree);
        secondNumber=secondNumber%rest;
        degree--;
    }
    previousNode->next=NULL;
    newNode=NULL;
    delete newNode;
    previousNode=NULL;
    delete previousNode;
}

int main() {
    Node* start=NULL,* first=NULL, *second=NULL, *thirth=NULL, *fourth=NULL, *fifth=NULL, *sixth=NULL, *seventh=NULL;
    start=new Node;
    first=new Node;
    second=new Node;
    thirth=new Node;
    fourth=new Node;
    fifth=new Node;
    sixth=new Node;
    seventh=new Node;
    
    start->data=1;
    start->next=first;
    first->data=9;
    first->next=second;
    second->data=0;
    second->next=thirth;
    thirth->data=0;
    thirth->next=fourth;
    fourth->data=9;
    fourth->next=fifth;
    fifth->data=9;
    fifth->next=sixth;
    sixth->data=9;
    sixth->next=seventh;
    seventh->data=9;
    seventh->next=NULL;
    
    cout<<"---Print list---"<<endl;
    print(start);
    cout<<"\n---Print list aftre function inc---"<<endl;
    inc(start);
    print(start);
    return 0;
}
