#include <iostream>
#include <stack>
using namespace std;

template <typename T>
struct Node{
    T data;
    Node* next;
};

template <typename T>
void printStack(stack<T> s){
    while(!s.empty()){
        cout<<s.top()<<endl;
        s.pop();
    }
}

template <typename T>
void print(Node<stack<T> >* start){
    if(start){
        while(start){
            if(start->next){
                printStack(start->data);
                cout<<"\n|"<<endl;
                cout<<"V\n"<<endl;
            }
            else{
                printStack(start->data);
            }
            start=start->next;
        }
    }
    else{
        cout<<"Empty list!"<<endl;
    }
}

template <typename T>
int numberOfListElements(Node<T>* start){
    int count=0;
    while(start){
        count++;
        start=start->next;
    }
    return count;
}

template <typename T>
int numberOfStackElements(stack<T> s){
    int count=0;
    while(!s.empty()){
        count++;
        s.pop();
    }
    return count;
}

template <typename T>
int numberOfAllElements(Node<stack<T> >* start){
    int num=0;
    if(start){
        while(start){
            num+=numberOfStackElements(start->data);
            start=start->next;
        }
    }
    return num;
}

template <typename T>
void equalize(Node<stack<T> >*& start){
    if(start && start->next){
        stack<T> temp;
        int minNumberOfElem=numberOfAllElements(start)/numberOfListElements(start);
        int rest=numberOfAllElements(start)%numberOfListElements(start);
        int count=1;
        
        Node<stack<T> >* copyStart=start;
        while(copyStart){
            int currentNumberOfElem;
            if(count<=rest){
                currentNumberOfElem=minNumberOfElem+1;
                count++;
            }
            else{
                currentNumberOfElem=minNumberOfElem;
            }
            while(numberOfStackElements(copyStart->data)>currentNumberOfElem){
                temp.push(copyStart->data.top());
                copyStart->data.pop();
            }
            while(numberOfStackElements(copyStart->data)<currentNumberOfElem){
                copyStart->data.push(temp.top());
                temp.pop();
            }
            copyStart=copyStart->next;
        }
    }
}

int main(){
    
    stack<int> s1,s2,s3,s4;
    s1.push(5);
    s1.push(4);
    s1.push(3);
    s1.push(2);
    s1.push(1);
    
    s2.push(7);
    s2.push(6);
    
    s3.push(11);
    s3.push(10);
    s3.push(9);
    s3.push(8);
    
    s4.push(12);
    
    Node<stack<int> >* start=NULL, *first=NULL, *second=NULL, *thirth=NULL;
    start=new Node<stack<int> >;
    assert(start!=NULL);
    first=new Node<stack<int> >;
    assert(first!=NULL);
    second=new Node<stack<int> >;
    assert(second!=NULL);
    thirth=new Node<stack<int> >;
    assert(thirth!=NULL);
    
    start->data=s1;
    start->next=first;
    first->data=s2;
    first->next=second;
    second->data=s3;
    second->next=thirth;
    thirth->data=s4;
    thirth->next=NULL;
    
    print(start);
    cout<<"\n---After equalize---"<<endl;
    equalize(start);
    print(start);
    return 0;
}
