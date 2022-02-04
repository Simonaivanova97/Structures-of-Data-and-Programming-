#include <iostream>
#include <stack>
using namespace std;

template <typename T>
struct node{
    T inf;
    node<T>* link;
};

template <typename T>
void printStack(stack<T> s){
    while(!s.empty()){
        cout<<s.top()<<endl;
        s.pop();
    }
}

void reverseStack(stack<int>& s){
    stack<int> temp;
    while(!s.empty()){
        temp.push(s.top());
        s.pop();
    }
    s=temp;
}

template <typename T>
void print(node<stack<T> >* start){
    if(start){
        while(start){
            if(start->link){
                printStack(start->inf);
                cout<<"\n|"<<endl;
                cout<<"V\n"<<endl;
            }
            else{
                printStack(start->inf);
            }
            start=start->link;
        }
    }
    else{
        cout<<"Empty list!"<<endl;
    }
}

bool containsOnlyOddNumbers(stack<int> s){
    while(!s.empty()){
        if(s.top()%2==0){
            return false;
            break;
        }
        s.pop();
    }
    return true;
}

bool containsOnlyEvenNumbers(stack<int> s){
    while(!s.empty()){
        if(s.top()%2==1){
            return false;
            break;
        }
        s.pop();
    }
    return true;
}

void concatSimiralStackElements(node<stack<int> >*& start){
    if(start && start->link){
        node<stack<int>>* copyStart=start;
        while(copyStart->link){
            if((containsOnlyOddNumbers(copyStart->inf) && containsOnlyOddNumbers(copyStart->link->inf)) ||
               (containsOnlyEvenNumbers(copyStart->inf) && containsOnlyEvenNumbers(copyStart->link->inf))){
                reverseStack(copyStart->link->inf);
                while(!copyStart->link->inf.empty()){
                    copyStart->inf.push(copyStart->link->inf.top());
                    copyStart->link->inf.pop();
                }
                node<stack<int>>* toDelete=copyStart->link;
                copyStart->link=toDelete->link;
                delete toDelete;
            }
            else{
                copyStart=copyStart->link;
            }
        }
    }
}

template <typename T>
void deleteList(node<T>*& start){
    node<T>* toDelete=NULL;
    while(start){
        toDelete=start;
        start=start->link;
        delete toDelete;
    }
}

int main(){
    stack<int> s1,s2,s3,s4,s5,s6;
    s1.push(2);
    s1.push(4);
    s1.push(6);
    s2.push(8);
    s2.push(0);
    s3.push(5);
    s3.push(7);
    s4.push(9);
    s4.push(1);
    s5.push(2);
    s5.push(0);
    s6.push(1);
    s6.push(2);
    node<stack<int>>* start=NULL, *first=NULL, *second=NULL, *thirth=NULL, *fourth=NULL, *fifth=NULL;
    start=new node<stack<int>>;
    first=new node<stack<int>>;
    second=new node<stack<int>>;
    thirth=new node<stack<int>>;
    fourth=new node<stack<int>>;
    fifth=new node<stack<int>>;
    
    start->inf=s1;
    start->link=first;
    first->inf=s2;
    first->link=second;
    second->inf=s3;
    second->link=thirth;
    thirth->inf=s4;
    thirth->link=fourth;
    fourth->inf=s5;
    fourth->link=fifth;
    fifth->inf=s6;
    fifth->link=NULL;
    
    print(start);
    cout<<"\n---After concat simiral stack elements---"<<endl;
    concatSimiralStackElements(start);
    print(start);
    
    deleteList(start);

    return 0;
}
